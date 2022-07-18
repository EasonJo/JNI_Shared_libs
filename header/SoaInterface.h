//
// Created by eason on 2022/7/15.
//

#ifndef JNIDEMO_SOAINTERFACE_H
#define JNIDEMO_SOAINTERFACE_H

/**
 * 空调相关的接口声明
 */
class SoaHACInterface {
public:
    //基类虚析构函数必须提供实现，如果声明为纯虚析构函数，也必须提供单独的实现
    virtual ~SoaHACInterface() = default;
    //另外一种写法
    //virtual ~SoaHACInterface(){};

    /**
     * 执行初始化动作
     */
    virtual void initSoaHAC() = 0;

    /**
     * 获取空调的温度值
     * @return
     */
    virtual float getTemperature() = 0;

    /**
     * 获取空调的风量等级
     * @return
     */
    virtual int getHacLevel() = 0;

    /**
     * 测试用
     */
    virtual void doTest() = 0;
};

/**
 * 车窗相关的接口声明
 */
class SoaWindowsInterface {
public:
    //基类虚析构函数必须提供实现，如果声明为纯虚析构函数，也必须提供单独的实现
    virtual ~SoaWindowsInterface() = default;
    //另外一种写法
    //virtual ~SoaWindowsInterface() {};

    /**
     * 执行初始化动作
     */
    virtual void initSoaWindows() = 0;

    /**
     * 打开车窗
     * @param level 车窗开度
     */
    virtual void open(int level) = 0;

    /**
     * 关闭车窗
     * @param level 关闭幅度
     */
    virtual void close(int level) = 0;

    /**
     * 获取车窗的开度
     * @param position 车窗位置
     * @return 车窗打开幅度
     */
    virtual int getWindowStatus(int position) = 0;
};

#endif //JNIDEMO_SOAINTERFACE_H
