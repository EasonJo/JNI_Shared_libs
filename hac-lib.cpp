#define LOG_TAG "HAC_SOA_NATIVE"

#include <jni.h>
#include <string>
#include "header/commonDef.h"
#include "header/SoaInterface.h"
#include "header/SoaHacImpl.h"
#include "header/Utils.h"
#include <thread>
#include <sstream>
#include <cassert>

//
// Created by Eason on 2022/7/14.
//

static JavaVM *javaVm = nullptr; //全局指针,用于保存JNI对象
static jobject pJobject = nullptr;
static jobject soa_server_interface = nullptr;
//全局对象
static std::shared_ptr<SoaHACInterface> soaHac = nullptr;

extern "C"
JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    //javaVm = vm;
    LOGI("JNI_OnLoad!");
    return JNI_VERSION_1_6;
}

extern "C"
JNIEXPORT void JNICALL
Java_ltd_qisi_jnidemo_SoaHACManager_initService(JNIEnv *env, jobject thiz) {
    LOGI("init HAC soa native");
    env->GetJavaVM(&javaVm); //保存全局JavaVM对象
    ::pJobject = env->NewGlobalRef(thiz);
    //初始化SoaHacImpl对象
    ::soaHac = std::shared_ptr<SoaHACInterface>(new SoaHacImpl());
    //todo 发布与订阅服务,执行初始化动作
    ::soaHac->initSoaHAC();
}

extern "C"
JNIEXPORT void JNICALL
Java_ltd_qisi_jnidemo_SoaHACManager_stopService(JNIEnv *env, jobject thiz) {
    LOGI("init HAC soa native");
}

extern "C"
JNIEXPORT jstring JNICALL
Java_ltd_qisi_jnidemo_SoaHACManager_stringFromJNI(JNIEnv *env, jobject thiz) {
    std::string str = "Hello From HAC SOA Native.";
    LOGI("init HAC soa native!");
    return env->NewStringUTF(str.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_ltd_qisi_jnidemo_SoaHACManager_sendEvent(JNIEnv *env, jobject thiz, jint event) {
    //do sent soaEvent
    //todo 调用soa发送event的能力
    LOGI("send event %d to soa server!", event);
}

extern void testCallBack();

extern "C"
JNIEXPORT void JNICALL
Java_ltd_qisi_jnidemo_SoaHACManager_testJniCallBack(JNIEnv *env, jobject thiz) {
    //从 SOA 读取 HAC 的状态,返回给应用层
    testCallBack();
}

bool mNeedDetach = JNI_FALSE;

std::string call_from_thread(jobject jObj, const Callback &pFunction) {
    //从 Java 层获取 value
    JNIEnv *env;
    //获取当前native线程是否有没有被附加到jvm环境中
    jint getEnvStat = javaVm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);
    if (getEnvStat == JNI_EDETACHED) {
        //如果没有， 主动附加到jvm环境中，获取到env
        if (javaVm->AttachCurrentThread(&env, nullptr) != 0) {
            return "";
        }
        mNeedDetach = JNI_TRUE;
    }

    if (jObj == nullptr) {
        LOGE("pJobject is Null!!!");
        return "";
    }

    std::string s = pFunction(env, jObj);
    if (!s.empty()) {
        LOGI("%s", s.c_str());
    }

    //释放当前线程
    if (mNeedDetach) {
        javaVm->DetachCurrentThread();
    }
    env = nullptr;
    return s;
}

void run() {
    const std::__thread_id &threadId = std::this_thread::get_id();
    LOGD("Native Thread ID: %s", getThreadIdOfString(threadId).c_str());

    std::string a = call_from_thread(
            pJobject,
            [](JNIEnv *env, jobject jobject1) -> std::string {
                //通过全局变量g_obj 获取到要回调的类
                jclass javaClass = env->GetObjectClass(pJobject);
                if (javaClass == nullptr) {
                    LOGI("Unable to find class");
                    javaVm->DetachCurrentThread();
                    return "";
                }

                //获取要回调的方法ID
                jmethodID javaCallbackId = env->GetMethodID(javaClass, "serverImpl", "(I)Ljava/lang/String;");
                //jmethodID javaCallbackId1 = env->GetMethodID(javaClass, "serverImpl", "()I");
                if (javaCallbackId == nullptr) {
                    LOGD("Unable to find method:serverImpl");
                    return "";
                }
                //执行回调
                //jstring method = static_cast<jstring>(env->CallObjectMethod(pJobject, javaCallbackId, 1));
                auto method = (jstring) env->CallObjectMethod(pJobject, javaCallbackId, 1);
                const char *result = env->GetStringUTFChars(method, 0);
                return {result};
            });
    LOGD("Call From SOA Client!!!! %s", a.c_str());
    int i = 0;
    while (i < 50) {
        LOGD("Call From SOA Client!!!! %d", i++);
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        call_from_thread(soa_server_interface, [](JNIEnv *env, jobject jObj) -> std::string {
            if (env != nullptr) {
                jclass soa_interface = env->GetObjectClass(jObj);
                if (soa_interface == nullptr) {
                    LOGI("Unable to find class");
                    javaVm->DetachCurrentThread();
                    return "";
                }
                jmethodID getAndroidVersion = env->GetMethodID(soa_interface, "getAndroidVersion", "()I");
                jmethodID getAndroidName = env->GetMethodID(soa_interface, "getAndroidName", "()Ljava/lang/String;");
                if (getAndroidVersion == nullptr || getAndroidName == nullptr) {
                    LOGW("Unable to find method:getAndroidVersion or getAndroidName");
                    return "";
                }
                jint version = env->CallIntMethod(jObj, getAndroidVersion);
                jstring name = static_cast<jstring>(env->CallObjectMethod(jObj, getAndroidName));
                LOGD("getAndroidVersion: %d", version);
                LOGD("getAndroidName: %s", env->GetStringUTFChars(name, 0));
            }
            return "";
        });
    }
}

void testCallBack() {
    std::thread thread(run);
    thread.detach();
}

extern "C"
JNIEXPORT void JNICALL
Java_ltd_qisi_jnidemo_SoaHACManager_setSoaServiceImpl(JNIEnv *env, jobject thiz, jobject soaServerInterface) {
    ::soa_server_interface = env->NewGlobalRef(soaServerInterface);
}
extern "C"
JNIEXPORT jfloat JNICALL
Java_ltd_qisi_jnidemo_SoaHACManager_getTemperature(JNIEnv *env, jobject thiz) {
    assert(::soaHac != nullptr);
    // 获取温度
    return soaHac->getTemperature();
}
extern "C"
JNIEXPORT jint JNICALL
Java_ltd_qisi_jnidemo_SoaHACManager_getHACLevel(JNIEnv *env, jobject thiz) {
    assert(::soaHac != nullptr);
    // 获取风量等级
    return soaHac->getHacLevel();
}

extern "C"
JNIEXPORT void JNICALL
Java_ltd_qisi_jnidemo_SoaHACManager_doMethod(JNIEnv *env, jobject thiz, jstring pJstring) {
    if (soaHac == nullptr) {
        LOGE("SOA IMPL is NULL.");
        return;
    }
    //method call.
    const char *s = env->GetStringUTFChars(pJstring, 0);
    std::string method = s;
    LOGI("do method call %s to soa server!", std::string(s).c_str());
    //todo 用枚举或者内置基本类型
//    if (method == "HACTemperature") {
//        auto t = soaHac->getTemperature();
//        LOGD("HAC Temperature is %f", t);
//    } else if (method == "HAC_LEVEL") {
//        auto l = soaHac->getHacLevel();
//        LOGD("HAC LEVEL is %d", l);
//    }
    soaHac->doTest();
}