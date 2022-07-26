//
// Created by eason on 2022/7/15.
//
#define LOG_TAG "SoaHacImpl"

#include "calculator_client.h"
#include <thread>
#include "SoaInterface.h"
#include "commonDef.h"
#include "SoaHacImpl.h"

float SoaHacImpl::getTemperature() {
    LOGI("Read HAC temperature form HAC.");
    //从soa的client调用温度
    return 23.5;
}

int SoaHacImpl::getHacLevel() {
    LOGI("Read HAC LEVEL form HAC.");
    return 3;
}

void SoaHacImpl::initSoaHAC() {
    //todo 初始化
    LOGD("initSoaHAC......");
}

SoaHacImpl::~SoaHacImpl() {
    LOGI("~SoaHacImpl");
    //释放资源
}

SoaHacImpl::SoaHacImpl() {
    //todo 初始化
    int i = 0;
    //soaApClient = new SoaApClient()
}

void SoaHacImpl::doTest() {
    CalculatorClient::ClientAct clientAct;
    std::thread t([&]() {
        clientAct.Init();
        std::this_thread::sleep_for(std::chrono::seconds(200));
        clientAct.Act();
        std::this_thread::sleep_for(std::chrono::seconds (200));
        clientAct.Stop();
    });
    t.detach();
}

