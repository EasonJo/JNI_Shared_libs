//
// Created by Eason on 2022/7/14.
//

#ifndef JNIDEMO_COMMONDEF_H
#define JNIDEMO_COMMONDEF_H

#ifndef LOG_TAG
#define LOG_TAG "SOA_JNI"
#endif //LOG_TAG

#include <string>
#include <android/log.h>
#include <jni.h>

#define  LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define  LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define  LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define  LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)

//定义一个回调函数
using Callback = std::function<std::string(JNIEnv *env, jobject jObj)>;

#endif //JNIDEMO_COMMONDEF_H