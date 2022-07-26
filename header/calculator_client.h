/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2012-2021. All rights reserved.
 * Description: AP组件示例程序服务端头文件
 * Create: 2021-9-8
 */
#ifndef HUAWEI_AP_CONTROL_CONTROL_ACTIVITY_H_
#define HUAWEI_AP_CONTROL_CONTROL_ACTIVITY_H_

#include <memory>
#include <mutex>
#include <iostream>
#include "CalculatorClient/executable.h"


namespace CalculatorClient {
    class ClientAct {
        using CalculatorProxy = huawei::proxy::CalculatorInterfaceProxy;
    public:
        ClientAct() = default;

        ~ClientAct() = default;

        /**
         * 初始化
         */
        void Init();

        /**
         * 停止
         */
        void Stop();

        /**
         * 模拟调用服务端的方法
         */
        void Act();


    private:

        /**
         * 客户端发现Server端的回调函数,类似于Android BindService的时候的ServiceConnection回调;
         * @param handles
         * @param handler
         */
        void ServiceAvailabilityCallback(ara::com::ServiceHandleContainer<CalculatorProxy::HandleType> handles,
                                         ara::com::FindServiceHandle handler);

        /**
         * 除0的时候异常回调;
         */
        void DividedByZeroCallback();

        /**
         * 除法的结果回调,监听filed字段的变化
         */
        void DividedResultCallback();

        /**
         * 加法
         * @param num1
         * @param num2
         */
        void AddMethodCall(uint64_t num1, uint64_t num2);

        /**
         * 减法
         * @param num1
         * @param num2
         */
        void SubtractMethodCall(uint64_t num1, uint64_t num2);

        /**
         * 除法
         * @param num1
         * @param num2
         */
        void DivideMethodCall(uint64_t num1, uint64_t num2);

        //std::uint64_t GetDividedResult();
        //void SetDividedResult(std::uint64_t value);
        std::shared_ptr<CalculatorProxy> calculatorProxy_;
        ara::com::FindServiceHandle CalculatorServiceHandle_;
    };
}
#endif
