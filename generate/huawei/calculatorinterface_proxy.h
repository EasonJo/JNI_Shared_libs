/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2022. All rights reserved.
 */

#ifndef HUAWEI_CALCULATORINTERFACE_PROXY_H
#define HUAWEI_CALCULATORINTERFACE_PROXY_H

#include "ara/com/internal/proxy/proxy_adapter.h"
#include "ara/com/internal/proxy/event_adapter.h"
#include "ara/com/internal/proxy/field_adapter.h"
#include "ara/com/internal/proxy/method_adapter.h"
#include "ara/com/crc_verification.h"
#include "huawei/calculatorinterface_common.h"
#include <string>

namespace huawei {
    namespace proxy {
        namespace events {
            using DividedByZero = ara::com::internal::proxy::event::EventAdapter<bool>;
            static constexpr ara::com::internal::EntityId CalculatorInterfaceDividedByZeroId = 33118U; //DividedByZero_event_hash
        }

        namespace fields {
            using DivideResult = ara::com::internal::proxy::field::FieldAdapter<::uint64_t>;
            static constexpr ara::com::internal::EntityId CalculatorInterfaceDivideResultId = 33857U; //DivideResult_field_hash
            static constexpr ara::com::internal::EntityId CalculatorInterfaceDivideResultSetterId = 37758U; //DivideResult_setter_hash
            static constexpr ara::com::internal::EntityId CalculatorInterfaceDivideResultGetterId = 37525U; //DivideResult_getter_hash
        }

        namespace methods {
            static constexpr ara::com::internal::EntityId CalculatorInterfaceDivideId = 50707U; //Divide_method_hash
            static constexpr ara::com::internal::EntityId CalculatorInterfaceaddId = 14241U; //add_method_hash
            static constexpr ara::com::internal::EntityId CalculatorInterfacesubstractId = 63238U; //substract_method_hash


            class Divide {
            public:
                using Output = huawei::methods::Divide::Output;

                Divide(const std::shared_ptr<vrtf::vcc::Proxy> &proxy, const ara::com::internal::EntityId entityId)
                        : method_(proxy, entityId) {}

                void Initialize(const std::shared_ptr<vrtf::vcc::Proxy> &proxy,
                                const ara::com::internal::EntityId entityId) {
                    method_.Initialize(proxy, entityId);
                }

                ara::core::Future<Output> operator()(const ::uint64_t &num1, const ::uint64_t &num2) {
                    return method_(num1, num2);
                }

                ara::com::internal::proxy::method::MethodAdapter<Output, ::uint64_t, ::uint64_t> GetMethod() const {
                    return method_;
                }

            private:
                ara::com::internal::proxy::method::MethodAdapter<Output, ::uint64_t, ::uint64_t> method_;
            };

            class add {
            public:
                using Output = huawei::methods::add::Output;

                add(const std::shared_ptr<vrtf::vcc::Proxy> &proxy, const ara::com::internal::EntityId entityId)
                        : method_(proxy, entityId) {}

                void Initialize(const std::shared_ptr<vrtf::vcc::Proxy> &proxy,
                                const ara::com::internal::EntityId entityId) {
                    method_.Initialize(proxy, entityId);
                }

                ara::core::Future<Output> operator()(const ::uint64_t &num1, const ::uint64_t &num2) {
                    return method_(num1, num2);
                }

                ara::com::internal::proxy::method::MethodAdapter<Output, ::uint64_t, ::uint64_t> GetMethod() const {
                    return method_;
                }

            private:
                ara::com::internal::proxy::method::MethodAdapter<Output, ::uint64_t, ::uint64_t> method_;
            };

            class substract {
            public:
                using Output = huawei::methods::substract::Output;

                substract(const std::shared_ptr<vrtf::vcc::Proxy> &proxy, const ara::com::internal::EntityId entityId)
                        : method_(proxy, entityId) {}

                void Initialize(const std::shared_ptr<vrtf::vcc::Proxy> &proxy,
                                const ara::com::internal::EntityId entityId) {
                    method_.Initialize(proxy, entityId);
                }

                ara::core::Future<Output> operator()(const ::uint64_t &num1, const ::uint64_t &num2) {
                    return method_(num1, num2);
                }

                ara::com::internal::proxy::method::MethodAdapter<Output, ::uint64_t, ::uint64_t> GetMethod() const {
                    return method_;
                }

            private:
                ara::com::internal::proxy::method::MethodAdapter<Output, ::uint64_t, ::uint64_t> method_;
            };
        } // namespace methods

        class CalculatorInterfaceProxy {
        private:
            std::unique_ptr<ara::com::internal::proxy::ProxyAdapter> proxyAdapter;
        public:
            using HandleType = vrtf::vcc::api::types::HandleType;

            class ConstructionToken {
            public:
                explicit ConstructionToken(std::unique_ptr<ara::com::internal::proxy::ProxyAdapter> &proxy) : ptr(
                        std::move(proxy)) {}

                explicit ConstructionToken(std::unique_ptr<ara::com::internal::proxy::ProxyAdapter> &&proxy) : ptr(
                        std::move(proxy)) {}

                ConstructionToken(ConstructionToken &&other)  noexcept : ptr(std::move(other.ptr)) {}

                ConstructionToken &operator=(ConstructionToken &&other) {
                    if (&other != this) {
                        ptr = std::move(other.ptr);
                    }
                    return *this;
                }

                ConstructionToken(const ConstructionToken &) = delete;

                ConstructionToken &operator=(const ConstructionToken &) = delete;

                std::unique_ptr<ara::com::internal::proxy::ProxyAdapter> GetProxyAdapter() {
                    return std::move(ptr);
                }

            private:
                std::unique_ptr<ara::com::internal::proxy::ProxyAdapter> ptr;
            };

            virtual ~CalculatorInterfaceProxy() {
                DividedByZero.UnsetReceiveHandler();
                DividedByZero.Unsubscribe();
            }

            explicit CalculatorInterfaceProxy(const vrtf::vcc::api::types::HandleType &handle)
                    : proxyAdapter(std::make_unique<ara::com::internal::proxy::ProxyAdapter>(
                    ::huawei::CalculatorInterface::ServiceIdentifier, handle)),
                      DividedByZero(proxyAdapter->GetProxy(), events::CalculatorInterfaceDividedByZeroId,
                                    proxyAdapter->GetHandle(), ::huawei::CalculatorInterface::ServiceIdentifier),
                      Divide(proxyAdapter->GetProxy(), methods::CalculatorInterfaceDivideId),
                      add(proxyAdapter->GetProxy(), methods::CalculatorInterfaceaddId),
                      substract(proxyAdapter->GetProxy(), methods::CalculatorInterfacesubstractId),
                      DivideResult(proxyAdapter->GetProxy(), fields::CalculatorInterfaceDivideResultId,
                                   proxyAdapter->GetHandle(), ::huawei::CalculatorInterface::ServiceIdentifier) {
                ara::core::Result<void> resultDivide = proxyAdapter->InitializeMethod<methods::Divide::Output>(
                        methods::CalculatorInterfaceDivideId);
                ThrowError(resultDivide);
                ara::core::Result<void> resultadd = proxyAdapter->InitializeMethod<methods::add::Output>(
                        methods::CalculatorInterfaceaddId);
                ThrowError(resultadd);
                ara::core::Result<void> resultsubstract = proxyAdapter->InitializeMethod<methods::substract::Output>(
                        methods::CalculatorInterfacesubstractId);
                ThrowError(resultsubstract);
                DivideResult.SetSetterEntityId(fields::CalculatorInterfaceDivideResultSetterId);
                DivideResult.SetGetterEntityId(fields::CalculatorInterfaceDivideResultGetterId);
                ara::core::Result<void> resultDivideResult = proxyAdapter->InitializeField<::uint64_t>(DivideResult);
                ThrowError(resultDivideResult);
            }

            void ThrowError(const ara::core::Result<void> &result) const {
                if (!(result.HasValue())) {
#ifndef NOT_SUPPORT_EXCEPTIONS
                    ara::core::ErrorCode errorcode(result.Error());
                    throw ara::com::ComException(std::move(errorcode));
#else
                    std::cerr << "Error: Not support exception, create proxy failed!"<< std::endl;
#endif
                }
            }

            CalculatorInterfaceProxy(const CalculatorInterfaceProxy &) = delete;

            CalculatorInterfaceProxy &operator=(const CalculatorInterfaceProxy &) = delete;

            CalculatorInterfaceProxy(CalculatorInterfaceProxy &&) = default;

            CalculatorInterfaceProxy &operator=(CalculatorInterfaceProxy &&) = default;

            CalculatorInterfaceProxy(ConstructionToken &&token) noexcept
                    : proxyAdapter(token.GetProxyAdapter()),
                      DividedByZero(proxyAdapter->GetProxy(), events::CalculatorInterfaceDividedByZeroId,
                                    proxyAdapter->GetHandle(), ::huawei::CalculatorInterface::ServiceIdentifier),
                      Divide(proxyAdapter->GetProxy(), methods::CalculatorInterfaceDivideId),
                      add(proxyAdapter->GetProxy(), methods::CalculatorInterfaceaddId),
                      substract(proxyAdapter->GetProxy(), methods::CalculatorInterfacesubstractId),
                      DivideResult(proxyAdapter->GetProxy(), fields::CalculatorInterfaceDivideResultId,
                                   proxyAdapter->GetHandle(), ::huawei::CalculatorInterface::ServiceIdentifier) {
                DivideResult.SetSetterEntityId(fields::CalculatorInterfaceDivideResultSetterId);
                DivideResult.SetGetterEntityId(fields::CalculatorInterfaceDivideResultGetterId);
            }

            static ara::core::Result<ConstructionToken> Preconstruct(
                    const vrtf::vcc::api::types::HandleType &handle) {
                std::unique_ptr<ara::com::internal::proxy::ProxyAdapter> preProxyAdapter =
                        std::make_unique<ara::com::internal::proxy::ProxyAdapter>(
                                ::huawei::CalculatorInterface::ServiceIdentifier, handle);
                bool result = true;
                ara::core::Result<void> initResult;
                do {
                    const methods::Divide Divide(preProxyAdapter->GetProxy(), methods::CalculatorInterfaceDivideId);
                    initResult = preProxyAdapter->InitializeMethod<methods::Divide::Output>(
                            methods::CalculatorInterfaceDivideId);
                    if (!initResult.HasValue()) {
                        result = false;
                        break;
                    }
                    const methods::add add(preProxyAdapter->GetProxy(), methods::CalculatorInterfaceaddId);
                    initResult = preProxyAdapter->InitializeMethod<methods::add::Output>(
                            methods::CalculatorInterfaceaddId);
                    if (!initResult.HasValue()) {
                        result = false;
                        break;
                    }
                    const methods::substract substract(preProxyAdapter->GetProxy(),
                                                       methods::CalculatorInterfacesubstractId);
                    initResult = preProxyAdapter->InitializeMethod<methods::substract::Output>(
                            methods::CalculatorInterfacesubstractId);
                    if (!initResult.HasValue()) {
                        result = false;
                        break;
                    }
                    fields::DivideResult DivideResult(preProxyAdapter->GetProxy(),
                                                      fields::CalculatorInterfaceDivideResultId, handle,
                                                      ::huawei::CalculatorInterface::ServiceIdentifier);
                    DivideResult.SetSetterEntityId(fields::CalculatorInterfaceDivideResultSetterId);
                    DivideResult.SetGetterEntityId(fields::CalculatorInterfaceDivideResultGetterId);
                    initResult = preProxyAdapter->InitializeField<::uint64_t>(DivideResult);
                    if (!initResult.HasValue()) {
                        result = false;
                        break;
                    }
                } while (false);

                if (result) {
                    ConstructionToken token(std::move(preProxyAdapter));
                    return ara::core::Result<ConstructionToken>(std::move(token));
                } else {
                    ConstructionToken token(std::move(preProxyAdapter));
                    ara::core::Result<ConstructionToken> preResult(std::move(token));
                    const ara::core::ErrorCode errorcode(initResult.Error());
                    preResult.EmplaceError(errorcode);
                    return preResult;
                }
            }

            static ara::com::FindServiceHandle StartFindService(
                    const ara::com::FindServiceHandler<ara::com::internal::proxy::ProxyAdapter::HandleType> &handler,
                    const ara::com::InstanceIdentifier instance) {
                return ara::com::internal::proxy::ProxyAdapter::StartFindService(handler,
                                                                                 ::huawei::CalculatorInterface::ServiceIdentifier,
                                                                                 instance);
            }

            static ara::com::FindServiceHandle StartFindService(
                    const ara::com::FindServiceHandler<ara::com::internal::proxy::ProxyAdapter::HandleType> handler,
                    const ara::core::InstanceSpecifier specifier) {
                return ara::com::internal::proxy::ProxyAdapter::StartFindService(handler,
                                                                                 ::huawei::CalculatorInterface::ServiceIdentifier,
                                                                                 specifier);
            }

            static ara::com::ServiceHandleContainer<ara::com::internal::proxy::ProxyAdapter::HandleType> FindService(
                    const ara::com::InstanceIdentifier instance) {
                return ara::com::internal::proxy::ProxyAdapter::FindService(
                        ::huawei::CalculatorInterface::ServiceIdentifier, instance);
            }

            static ara::com::ServiceHandleContainer<ara::com::internal::proxy::ProxyAdapter::HandleType> FindService(
                    const ara::core::InstanceSpecifier specifier) {
                return ara::com::internal::proxy::ProxyAdapter::FindService(
                        ::huawei::CalculatorInterface::ServiceIdentifier, specifier);
            }

            static void StopFindService(const ara::com::FindServiceHandle &handle) {
                ara::com::internal::proxy::ProxyAdapter::StopFindService(handle);
            }

            HandleType GetHandle() const {
                return proxyAdapter->GetHandle();
            }

            bool SetEventThreadNumber(const std::uint16_t number, const std::uint16_t queueSize) {
                return proxyAdapter->SetEventThreadNumber(number, queueSize);
            }

            events::DividedByZero DividedByZero;
            methods::Divide Divide;
            methods::add add;
            methods::substract substract;
            fields::DivideResult DivideResult;
        };
    } // namespace proxy
} // namespace huawei

#endif // HUAWEI_CALCULATORINTERFACE_PROXY_H
