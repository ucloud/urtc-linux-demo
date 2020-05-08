# URTC X64 SDK DEMO使用说明

适用环境：ubuntu 16.04 18.04
编译工具: cmake make gcc g++

URTC 以动态链接库的方式提供SDK，包括头文件和动态链接库文件：
- urtclib/interface/UCloudRtcComDefine.h
- urtclib/interface/UCloudRtcEngine.h
- urtclib/interface/UCloudRtcErrorCode.h
- urtclib/interface/UCloudRtcMediaDevice.h
- urtclib/lib/libliburtcmediaengine.so
- urtclib/lib/liburtcnetengine.so

URTC DEMO为开源，用户可以直接使用到自己的产品中。

## DEMO及SDK使用注意事项

- 该SDK的视频源为 mp4，`main.cpp`中的`urtcengine->AddFileList(files, true)`
- 推流成功，用户可以处理回调函数`URTCEventHandler.cpp`中的`onLocalPublish`处理，如果`code==0`，则推流成功
- 单个文件播放回调 回调函数`URTCEventHandler.cpp`中的`onFileDataEnd`处理，`filename 表示电脑前播完文件名称`
- 列表播放完毕 回调函数`URTCEventHandler.cpp`中的`onFileListEnd`处理，`filename为“”`

## 如果在目标机器上编译使用下面的命令

```
cd build
# 生成Makefile等
cmake ../.
# 编译成功后，在../bin中生成可执行文件
make
# 执行
cd ..
bin/enginedemo roomid  userid  其中 roomid 和userid 指定为自己的房间标识和用户标识

客户端 https://demo.urtc.com.cn 加入 roomid 指定的房间 观看视频
```

## 创建URTC应用快速入门

参考：[快速上手](https://docs.ucloud.cn/video/urtc/quick)


## **注意事项**

1. 使用本库需要了解URTC的基本配置参数，包括应用名称，AppID, AppKey, roomid，userid, tokenid, 具体使用方法请参考[URTC文档](https://docs.ucloud.cn/video/urtc)
2. 使用本库需要了解URTC的基本概念，包括进入房间、离开房间、发布视频流、取消发布、订阅视频流、取消订阅，
3. URTC 加入参考(参考`main.cpp`,`URTCConfig.cpp`):
   - AppID、AppKey为在UCloud控制台创建应用时系统自动生成;
   - 【重要】AppKey为接入平台认证Key，本demo中直接使用该Key接入，生产环境下务必将AppKey存在服务器端,[使用Token接入](https://docs.ucloud.cn/video/urtc/sdk/token)；
   - 应用名称采用 产品序列号+产品名称，比如：ozuz63kum2i4djb3_巡检无人机；
   - roomid采用设备序列号，比如：afnyhnizq9l4l9ev；
   - userid采用设备序列号+摄像头编号，比如：afnyhnizq9l4l9ev_camera3；
   - tokenid为服务器端生成，测试环境直接使用AppKey测试，生产环境务必参考本项第2条；
4. 生产、测试环境切换：
   - 生产模式使用Tokenid，配置`URTCConfig.cpp`，`mSdkMode = UCLOUD_RTC_SDK_MODE_NORMAL;`, 此时在`main.cpp中获取tokenid;
