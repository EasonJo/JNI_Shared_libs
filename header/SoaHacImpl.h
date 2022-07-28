//
// Created by eason on 2022/7/15.
//

#ifndef JNIDEMO_SOAHACIMPL_H
#define JNIDEMO_SOAHACIMPL_H

#include "SoaInterface.h"
#include "calculator_client.h"

class SoaHacImpl : public SoaHACInterface {

private:
    //SoAAPClient* soaApClient;

    std::shared_ptr<CalculatorClient::ClientAct> clientAct = nullptr;
public:

    explicit SoaHacImpl();

    ~SoaHacImpl() override;

    void initSoaHAC() override;

    float getTemperature() override;

    int getHacLevel() override;

    void doTest() override;

};

#endif //JNIDEMO_SOAHACIMPL_H
