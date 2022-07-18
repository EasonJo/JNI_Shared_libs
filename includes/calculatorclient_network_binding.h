/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2022. All rights reserved.
 */

#ifndef CALCULATORCLIENT_NETWORK_BINDING_H
#define CALCULATORCLIENT_NETWORK_BINDING_H

#include "ara/core/array.h"
#include "ara/core/instance_specifier.h"

namespace huawei {
namespace calculatorinterface {
    const ara::core::Array<ara::core::InstanceSpecifier, 1> INSTANCE_SPECIFIERS = {
        ara::core::InstanceSpecifier("CalculatorClient/CalculatorClient/RequiredCalculatorInterface")
    };
} // namespace calculatorinterface
} // namespace huawei

#endif // CALCULATORCLIENT_NETWORK_BINDING_H
