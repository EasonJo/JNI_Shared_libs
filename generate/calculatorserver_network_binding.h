/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2022. All rights reserved.
 */

#ifndef CALCULATORSERVER_NETWORK_BINDING_H
#define CALCULATORSERVER_NETWORK_BINDING_H

#include "ara/core/array.h"
#include "ara/core/instance_specifier.h"

namespace huawei {
namespace calculatorinterface {
    const ara::core::Array<ara::core::InstanceSpecifier, 1> INSTANCE_SPECIFIERS = {
        ara::core::InstanceSpecifier("CalculatorServer/CalculatorServer/ProvidedCalculatorService")
    };
} // namespace calculatorinterface
} // namespace huawei

#endif // CALCULATORSERVER_NETWORK_BINDING_H
