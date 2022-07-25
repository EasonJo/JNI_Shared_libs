/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2022. All rights reserved.
 */

#ifndef HUAWEI_CALCULATORINTERFACE_COMMON_H
#define HUAWEI_CALCULATORINTERFACE_COMMON_H

#include "ara/com/types.h"
#include "ara/com/init_config.h"
#include "impl_type_uint64_t.h"
#include <cfloat>
#include <cmath>

namespace huawei {
    namespace methods {
        namespace Divide {
            struct Output {
                ::uint64_t result;

                static bool IsPlane() {
                    return true;
                }

                using IsEnumerableTag = void;

                template<typename F>
                void enumerate(F &fun) {
                    fun(result);
                }

                template<typename F>
                void enumerate(F &fun) const {
                    fun(result);
                }

                bool operator==(const Output &t) const {
                    return (result == t.result);
                }
            };
        } // namespace Divide
        namespace add {
            struct Output {
                ::uint64_t result;

                static bool IsPlane() {
                    return true;
                }

                using IsEnumerableTag = void;

                template<typename F>
                void enumerate(F &fun) {
                    fun(result);
                }

                template<typename F>
                void enumerate(F &fun) const {
                    fun(result);
                }

                bool operator==(const Output &t) const {
                    return (result == t.result);
                }
            };
        } // namespace add
        namespace substract {
            struct Output {
                ::uint64_t result;

                static bool IsPlane() {
                    return true;
                }

                using IsEnumerableTag = void;

                template<typename F>
                void enumerate(F &fun) {
                    fun(result);
                }

                template<typename F>
                void enumerate(F &fun) const {
                    fun(result);
                }

                bool operator==(const Output &t) const {
                    return (result == t.result);
                }
            };
        } // namespace substract
    } // namespace methods

    class CalculatorInterface {
    public:
        constexpr CalculatorInterface() = default;

        constexpr static ara::com::ServiceIdentifierType
        ServiceIdentifier = ara::com::ServiceIdentifierType("/Services/ServiceInterface/CalculatorInterface");
        constexpr static ara::com::ServiceVersionType
        ServiceVersion = ara::com::ServiceVersionType("1.1");
    };
} // namespace huawei

#endif // HUAWEI_CALCULATORINTERFACE_COMMON_H
