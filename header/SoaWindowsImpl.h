//
// Created by eason on 2022/7/15.
//

#ifndef JNIDEMO_SOAWINDOWSIMPL_H
#define JNIDEMO_SOAWINDOWSIMPL_H


#include "SoaInterface.h"

class SoaWindowsImpl : public SoaWindowsInterface {
public:
    ~SoaWindowsImpl() override;

    void initSoaWindows() override;

    void open(int level) override;

    void close(int level) override;

    int getWindowStatus(int position) override;
};


#endif //JNIDEMO_SOAWINDOWSIMPL_H
