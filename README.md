# URTC ARM64 SDK DEMO

## 适用环境

ubuntu 16.04、18.04

## 编译工具

cmake make gcc g++

URTC 以动态链接库的方式提供SDK，包括头文件和动态链接库文件：

urtclib/interface/UCloudRtcComDefine.h
urtclib/interface/UCloudRtcEngine.h
urtclib/interface/UCloudRtcErrorCode.h
urtclib/interface/UCloudRtcMediaDevice.h
urtclib/lib/libliburtcmediaengine.so
urtclib/lib/liburtcnetengine.so

URTC DEMO为开源，用户可以直接使用到自己的产品中。

## RTSP源的约束

该SDK的视频源为RTSP格式，只支持H.264 baseline，RTSP 关键帧(GOP)设置推荐在3秒以内，码率设置需要小于3000kbps。

## 编译demo

 ** 如果在目标机器上编译使用下面的命令

```

cd build
# 生成Makefile等
cmake ../.
# 编译成功后，在../bin中生成可执行文件
make
# 执行
cd ..
bin/enginedemo rtsp://path/to/rtspstream

```

 ** 如果使用交叉编译，需要修改CMakeList.txt （交叉编译速度会有所提高）

```

# 打开文件CMakeList.txt中下面的注释
SET(CROSS_COMPILE 1)

IF(CROSS_COMPILE)
SET(TOOLCHAIN_DIR "/path/to/compile-toolchain/gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu")
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_DIR}/bin/aarch64-linux-gnu-g++)
set(CMAKE_C_COMPILER   ${TOOLCHAIN_DIR}/bin/aarch64-linux-gnu-gcc)

SET(CMAKE_FIND_ROOT_PATH  ${TOOLCHAIN_DIR}
 ${TOOLCHAIN_DIR}/include
 ${TOOLCHAIN_DIR}/lib )
ENDIF(CROSS_COMPILE)

```

## 运行demo

编译完毕后，运行

./enginedemo roomid userid rtsp://xxx

>  roomid：自定义的房间号，同一个房间的用户可以通讯。
>  userid ：自定义的用户号，每个客户端id需要唯一。
>  rtsp://xxx，为通过RTSP拉流设备的网络地址。


推流成功，用户可以处理回调函数URTCEventHandler.cpp中的onLocalPublish处理，如果code==0，则推流成功。
