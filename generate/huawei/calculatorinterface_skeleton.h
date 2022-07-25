/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2022. All rights reserved.
 */

#ifndef HUAWEI_CALCULATORINTERFACE_SKELETON_H
#define HUAWEI_CALCULATORINTERFACE_SKELETON_H

#include "ara/com/internal/skeleton/skeleton_adapter.h"
#include "ara/com/internal/skeleton/event_adapter.h"
#include "ara/com/internal/skeleton/field_adapter.h"
#include "ara/com/internal/skeleton/method_adapter.h"
#include "ara/com/crc_verification.h"
#include "huawei/calculatorinterface_common.h"
#include <cstdint>
#include <memory>

namespace huawei {
namespace skeleton {
namespace events
{
    using DividedByZero = ara::com::internal::skeleton::event::EventAdapter<bool>;
    static constexpr ara::com::internal::EntityId CalculatorInterfaceDividedByZeroId = 33118U; //DividedByZero_event_hash
}

namespace methods
{
    using DivideHandle = ara::com::internal::skeleton::method::MethodAdapter;
    using addHandle = ara::com::internal::skeleton::method::MethodAdapter;
    using substractHandle = ara::com::internal::skeleton::method::MethodAdapter;
    static constexpr ara::com::internal::EntityId CalculatorInterfaceDivideId = 50707U; //Divide_method_hash
    static constexpr ara::com::internal::EntityId CalculatorInterfaceaddId = 14241U; //add_method_hash
    static constexpr ara::com::internal::EntityId CalculatorInterfacesubstractId = 63238U; //substract_method_hash
}

namespace fields
{
    using DivideResult = ara::com::internal::skeleton::field::FieldAdapter<::uint64_t>;
    static constexpr ara::com::internal::EntityId CalculatorInterfaceDivideResultId = 33857U; //DivideResult_field_hash
    static constexpr ara::com::internal::EntityId CalculatorInterfaceDivideResultSetterId = 37758U; //DivideResult_setter_hash
    static constexpr ara::com::internal::EntityId CalculatorInterfaceDivideResultGetterId = 37525U; //DivideResult_getter_hash
}

class CalculatorInterfaceSkeleton {
private:
    std::unique_ptr<ara::com::internal::skeleton::SkeletonAdapter> skeletonAdapter;
    void ConstructSkeleton(const ara::com::MethodCallProcessingMode mode)
    {
        if (mode == ara::com::MethodCallProcessingMode::kEvent) {
            if (!(skeletonAdapter->SetMethodThreadNumber(skeletonAdapter->GetMethodThreadNumber(5U), 1024U))) {
#ifndef NOT_SUPPORT_EXCEPTIONS
                ara::core::ErrorCode errorcode(ara::com::ComErrc::kNetworkBindingFailure);
                throw ara::com::ComException(std::move(errorcode));
#else
                std::cerr << "Error: Not support exception, create skeleton failed!"<< std::endl;
#endif
            }
        }
        const ara::core::Result<void> resultDividedByZero = skeletonAdapter->InitializeEvent(DividedByZero);
        ThrowError(resultDividedByZero);
        const ara::core::Result<void> resultDivide = skeletonAdapter->InitializeMethod<ara::core::Future<DivideOutput>>(methods::CalculatorInterfaceDivideId);
        ThrowError(resultDivide);
        const ara::core::Result<void> resultadd = skeletonAdapter->InitializeMethod<ara::core::Future<addOutput>>(methods::CalculatorInterfaceaddId);
        ThrowError(resultadd);
        const ara::core::Result<void> resultsubstract = skeletonAdapter->InitializeMethod<ara::core::Future<substractOutput>>(methods::CalculatorInterfacesubstractId);
        ThrowError(resultsubstract);
        DivideResult.SetSetterEntityId(fields::CalculatorInterfaceDivideResultSetterId);
        DivideResult.SetGetterEntityId(fields::CalculatorInterfaceDivideResultGetterId);
        const ara::core::Result<void> resultDivideResult = skeletonAdapter->InitializeField<::uint64_t>(DivideResult);
        ThrowError(resultDivideResult);
    }

    CalculatorInterfaceSkeleton& operator=(const CalculatorInterfaceSkeleton&) = delete;

    static void ThrowError(const ara::core::Result<void>& result)
    {
        if (!(result.HasValue())) {
#ifndef NOT_SUPPORT_EXCEPTIONS
            ara::core::ErrorCode errorcode(result.Error());
            throw ara::com::ComException(std::move(errorcode));
#else
            std::cerr << "Error: Not support exception, create skeleton failed!"<< std::endl;
#endif
        }
    }
public:
    using DivideOutput = huawei::methods::Divide::Output;

    using addOutput = huawei::methods::add::Output;

    using substractOutput = huawei::methods::substract::Output;

    class ConstructionToken {
    public:
        explicit ConstructionToken(std::unique_ptr<ara::com::internal::skeleton::SkeletonAdapter>& skeleton)
            : ptr(std::move(skeleton)) {}
        explicit ConstructionToken(std::unique_ptr<ara::com::internal::skeleton::SkeletonAdapter>&& skeleton)
            : ptr(std::move(skeleton)) {}
        ConstructionToken(ConstructionToken&& other) : ptr(std::move(other.ptr)) {}
        ConstructionToken& operator=(ConstructionToken && other)
        {
            if (&other != this) {
                ptr = std::move(other.ptr);
            }
            return *this;
        }
        ConstructionToken(const ConstructionToken&) = delete;
        ConstructionToken& operator = (const ConstructionToken&) = delete;
        std::unique_ptr<ara::com::internal::skeleton::SkeletonAdapter> GetSkeletonAdapter()
        {
            return std::move(ptr);
        }
    private:
        std::unique_ptr<ara::com::internal::skeleton::SkeletonAdapter> ptr;
        fields::DivideResult DivideResult;
    };
    explicit CalculatorInterfaceSkeleton(const ara::com::InstanceIdentifier& instanceId,
                           const ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent)
        : skeletonAdapter(std::make_unique<ara::com::internal::skeleton::SkeletonAdapter>(::huawei::CalculatorInterface::ServiceIdentifier, instanceId, mode)),
          DividedByZero(skeletonAdapter->GetSkeleton(), events::CalculatorInterfaceDividedByZeroId),
          DivideHandle(skeletonAdapter->GetSkeleton(), methods::CalculatorInterfaceDivideId),
          addHandle(skeletonAdapter->GetSkeleton(), methods::CalculatorInterfaceaddId),
          substractHandle(skeletonAdapter->GetSkeleton(), methods::CalculatorInterfacesubstractId),
          DivideResult(skeletonAdapter->GetSkeleton(), fields::CalculatorInterfaceDivideResultId) {
        ConstructSkeleton(mode);
    }

    explicit CalculatorInterfaceSkeleton(const ara::core::InstanceSpecifier& instanceSpec,
                           const ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent)
        :skeletonAdapter(std::make_unique<ara::com::internal::skeleton::SkeletonAdapter>(::huawei::CalculatorInterface::ServiceIdentifier, instanceSpec, mode)),
          DividedByZero(skeletonAdapter->GetSkeleton(), events::CalculatorInterfaceDividedByZeroId),
          DivideHandle(skeletonAdapter->GetSkeleton(), methods::CalculatorInterfaceDivideId),
          addHandle(skeletonAdapter->GetSkeleton(), methods::CalculatorInterfaceaddId),
          substractHandle(skeletonAdapter->GetSkeleton(), methods::CalculatorInterfacesubstractId),
          DivideResult(skeletonAdapter->GetSkeleton(), fields::CalculatorInterfaceDivideResultId) {
        ConstructSkeleton(mode);
    }

    explicit CalculatorInterfaceSkeleton(const ara::com::InstanceIdentifierContainer instanceContainer,
                           const ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent)
        :skeletonAdapter(std::make_unique<ara::com::internal::skeleton::SkeletonAdapter>(::huawei::CalculatorInterface::ServiceIdentifier, instanceContainer, mode)),
          DividedByZero(skeletonAdapter->GetSkeleton(), events::CalculatorInterfaceDividedByZeroId),
          DivideHandle(skeletonAdapter->GetSkeleton(), methods::CalculatorInterfaceDivideId),
          addHandle(skeletonAdapter->GetSkeleton(), methods::CalculatorInterfaceaddId),
          substractHandle(skeletonAdapter->GetSkeleton(), methods::CalculatorInterfacesubstractId),
          DivideResult(skeletonAdapter->GetSkeleton(), fields::CalculatorInterfaceDivideResultId) {
        ConstructSkeleton(mode);
    }

    CalculatorInterfaceSkeleton(const CalculatorInterfaceSkeleton&) = delete;

    CalculatorInterfaceSkeleton(CalculatorInterfaceSkeleton&&) = default;
    CalculatorInterfaceSkeleton& operator=(CalculatorInterfaceSkeleton&&) = default;
    CalculatorInterfaceSkeleton(ConstructionToken&& token) noexcept
        : skeletonAdapter(token.GetSkeletonAdapter()),
          DividedByZero(skeletonAdapter->GetSkeleton(), events::CalculatorInterfaceDividedByZeroId),
          DivideHandle(skeletonAdapter->GetSkeleton(), methods::CalculatorInterfaceDivideId),
          addHandle(skeletonAdapter->GetSkeleton(), methods::CalculatorInterfaceaddId),
          substractHandle(skeletonAdapter->GetSkeleton(), methods::CalculatorInterfacesubstractId),
          DivideResult(skeletonAdapter->GetSkeleton(), fields::CalculatorInterfaceDivideResultId) {
        DivideResult.SetSetterEntityId(fields::CalculatorInterfaceDivideResultSetterId);
        DivideResult.SetGetterEntityId(fields::CalculatorInterfaceDivideResultGetterId);
    }

    static ara::core::Result<ConstructionToken> Preconstruct(
        ara::com::InstanceIdentifier instanceId,
        const ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent)
    {
        std::unique_ptr<ara::com::internal::skeleton::SkeletonAdapter> preSkeletonAdapter =
            std::make_unique<ara::com::internal::skeleton::SkeletonAdapter>(
                ::huawei::CalculatorInterface::ServiceIdentifier, instanceId, mode);
        return PreConstructResult(preSkeletonAdapter, mode);
    }

    static ara::core::Result<ConstructionToken> Preconstruct(
        ara::core::InstanceSpecifier instanceSpec,
        const ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent)
    {
        std::unique_ptr<ara::com::internal::skeleton::SkeletonAdapter> preSkeletonAdapter =
            std::make_unique<ara::com::internal::skeleton::SkeletonAdapter>(
                ::huawei::CalculatorInterface::ServiceIdentifier, instanceSpec, mode);
        return PreConstructResult(preSkeletonAdapter, mode);
    }

    static ara::core::Result<ConstructionToken> Preconstruct(
        ara::com::InstanceIdentifierContainer instanceIdContainer,
        const ara::com::MethodCallProcessingMode mode = ara::com::MethodCallProcessingMode::kEvent)
    {
        std::unique_ptr<ara::com::internal::skeleton::SkeletonAdapter> preSkeletonAdapter =
            std::make_unique<ara::com::internal::skeleton::SkeletonAdapter>(
                ::huawei::CalculatorInterface::ServiceIdentifier, instanceIdContainer, mode);
        return PreConstructResult(preSkeletonAdapter, mode);
    }

    static ara::core::Result<ConstructionToken> PreConstructResult(
        std::unique_ptr<ara::com::internal::skeleton::SkeletonAdapter>& preSkeletonAdapter, const ara::com::MethodCallProcessingMode mode)
    {
        bool result = true;
        ara::core::Result<void> initResult;
        do {
            if (mode == ara::com::MethodCallProcessingMode::kEvent) {
                if(!preSkeletonAdapter->SetMethodThreadNumber(preSkeletonAdapter->GetMethodThreadNumber(5U), 1024U)) {
                    result = false;
                    ara::core::ErrorCode errorcode(ara::com::ComErrc::kNetworkBindingFailure);
                    initResult.EmplaceError(errorcode);
                    break;
                }
            }
            const events::DividedByZero DividedByZero(preSkeletonAdapter->GetSkeleton(), events::CalculatorInterfaceDividedByZeroId);
            initResult = preSkeletonAdapter->InitializeEvent(DividedByZero);
            if (!initResult.HasValue()) {
                result = false;
                break;
            }
            initResult = preSkeletonAdapter->InitializeMethod<ara::core::Future<DivideOutput>>(methods::CalculatorInterfaceDivideId);
            if (!initResult.HasValue()) {
                result = false;
                break;
            }
            initResult = preSkeletonAdapter->InitializeMethod<ara::core::Future<addOutput>>(methods::CalculatorInterfaceaddId);
            if (!initResult.HasValue()) {
                result = false;
                break;
            }
            initResult = preSkeletonAdapter->InitializeMethod<ara::core::Future<substractOutput>>(methods::CalculatorInterfacesubstractId);
            if (!initResult.HasValue()) {
                result = false;
                break;
            }
            fields::DivideResult DivideResult(preSkeletonAdapter->GetSkeleton(), fields::CalculatorInterfaceDivideResultId);
            DivideResult.SetSetterEntityId(fields::CalculatorInterfaceDivideResultSetterId);
            DivideResult.SetGetterEntityId(fields::CalculatorInterfaceDivideResultGetterId);
            initResult = preSkeletonAdapter->InitializeField<::uint64_t>(DivideResult);
            if (!initResult.HasValue()) {
                result = false;
                break;
            }
        } while(false);

        if (result) {
            ConstructionToken token(std::move(preSkeletonAdapter));
            return ara::core::Result<ConstructionToken>(std::move(token));
        } else {
            ConstructionToken token(std::move(preSkeletonAdapter));
            ara::core::Result<ConstructionToken> preResult(std::move(token));
            const ara::core::ErrorCode errorcode(initResult.Error());
            preResult.EmplaceError(errorcode);
            return preResult;
        }
    }

    virtual ~CalculatorInterfaceSkeleton()
    {
        StopOfferService();
    }

    void OfferService()
    {
        skeletonAdapter->RegisterE2EErrorHandler(&CalculatorInterfaceSkeleton::E2EErrorHandler, *this);
        skeletonAdapter->RegisterMethod(&CalculatorInterfaceSkeleton::Divide, *this, methods::CalculatorInterfaceDivideId);
        skeletonAdapter->RegisterMethod(&CalculatorInterfaceSkeleton::add, *this, methods::CalculatorInterfaceaddId);
        skeletonAdapter->RegisterMethod(&CalculatorInterfaceSkeleton::substract, *this, methods::CalculatorInterfacesubstractId);
        DivideResult.VerifyValidity();
        skeletonAdapter->OfferService();
    }
    void StopOfferService()
    {
        skeletonAdapter->StopOfferService();
        DivideResult.ResetInitState();
    }
    ara::core::Future<bool> ProcessNextMethodCall()
    {
        return skeletonAdapter->ProcessNextMethodCall();
    }
    bool SetMethodThreadNumber(const std::uint16_t& number, const std::uint16_t& queueSize)
    {
        return skeletonAdapter->SetMethodThreadNumber(number, queueSize);
    }
    virtual ara::core::Future<DivideOutput> Divide(const ::uint64_t& num1, const ::uint64_t& num2) = 0;
    virtual ara::core::Future<addOutput> add(const ::uint64_t& num1, const ::uint64_t& num2) = 0;
    virtual ara::core::Future<substractOutput> substract(const ::uint64_t& num1, const ::uint64_t& num2) = 0;
    virtual void E2EErrorHandler(ara::com::e2e::E2EErrorCode, ara::com::e2e::DataID, ara::com::e2e::MessageCounter){}

    events::DividedByZero DividedByZero;
    methods::DivideHandle DivideHandle;
    methods::addHandle addHandle;
    methods::substractHandle substractHandle;
    fields::DivideResult DivideResult;
};
} // namespace skeleton
} // namespace huawei

#endif // HUAWEI_CALCULATORINTERFACE_SKELETON_H
