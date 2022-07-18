cmake_minimum_required(VERSION 3.21)
#使用Android的工具链文件,需要先设置NDK的系统环境变量
# $ANDROID_NDK_HOME="NDK的系统路径"

#需要在Project之前设置,具体参考.cmake文件中声明的属性,这些属性都需要在project之前定义
# ANDROID_TOOLCHAIN
# ANDROID_ABI
# ANDROID_PLATFORM
# ANDROID_STL
# ANDROID_PIE
# ANDROID_CPP_FEATURES
# ANDROID_ALLOW_UNDEFINED_SYMBOLS
# ANDROID_ARM_MODE
# ANDROID_DISABLE_FORMAT_STRING_CHECKS
# ANDROID_CCACHE
set(ANDROID_PLATFORM android-29)
set(ANDROID_ABI arm64-v8a)

#和上面的属性，设置一个即可
#set(ANDROID_NATIVE_API_LEVEL android-29)
project(JNI_Shared_libs)

set(CMAKE_CXX_STANDARD 11)
#定义Android NDK的路径,设置了NDK的系统环境变量之后,无需再设置此路径
#set(ANDROID_NDK "D:/Android/android-sdk/ndk/25.0.8775105")
#设置NDK编译链工具文件路径,此文件内部会生成基于CMAKE的NDK编译需要的所有编译参数
set(CMAKE_TOOLCHAIN_FILE "${ANDROID_NDK}/build/cmake/android.toolchain.cmake")
#set(CMAKE_ANDROID_NDK ${ANDROID_NDK}) 设置了环境变量之后,就无须设置此变量,.cmake文件内部已经处理
#set(CMAKE_SYSTEM_NAME Android) .cmake文件内部指定
#set(CMAKE_SYSTEM_VERSION 29) .cmake文件内部指定
#set(CMAKE_ANDROID_ARCH_ABI armeabi-v7a) .cmake文件内部指定

#无需再设置以下属性,android.toolchain.cmake文件中会根据ANDROID_ABI自动为以下属性赋值
#set(CMAKE_ANDROID_ARCH_ABI arm64-v8a)
# 设置C编译选项
set(CMAKE_C_FLAGS "-fpic -fexceptions -frtti")
# 设置CXX编译选项
set(CMAKE_CXX_FLAGS "-fpic -fexceptions -frtti")
#不能自己手动设置,系统会自动选择,因为不同的平台上.使用的编译工具不一样
#set(CMAKE_C_COMPILER "${ANDROID_NDK}/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang")
#set(CMAKE_CXX_COMPILER "${ANDROID_NDK}/toolchains/llvm/prebuilt/darwin-x86_64/bin/clang++")

#批量查询到.c .h .cpp文件
#file(GLOB allCpp *.c *.h *.cpp *.hpp)
include_directories(${CMAKE_SOURCE_DIR}/header)
#include_directories(${CMAKE_SOURCE_DIR}/includes)
#include_directories(${HUAWEI_SDK}/include)

add_library( # Sets the name of the library.
        window_soa
        # Sets the library as a shared library.
        SHARED
        # Provides a relative path to your source file(s).
        window-lib.cpp SoaWindowsImpl.cpp)

add_library(hac_soa SHARED hac-lib.cpp SoaHacImpl.cpp)

## 添加第三方库
#[[add_library(soa_ap
        SHARED
        IMPORTED)
set_target_properties(
        soa_ap
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/libs/libCalculatorClient.so)]]

message("Android NDK: ${ANDROID_NDK}")
message("${ANDROID_ABI}")
message("${CMAKE_TOOLCHAIN_FILE}")

#使用Android Studio时使用
#find_library( # Sets the name of the path variable.
#        log-lib
#
#        # Specifies the name of the NDK library that
#        # you want CMake to locate.
#        log)

target_link_libraries( # Specifies the target library.
        window_soa
        #soa_ap
        android
        # Links the target library to the log library
        # included in the NDK.
        log)

target_link_libraries( # Specifies the target library.
        hac_soa
        #soa_ap
        android
        # Links the target library to the log library
        # included in the NDK.
        log)