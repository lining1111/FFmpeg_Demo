## 15-使用FFmpeg SDK进行视频图像转换与音频重采样

    视频缩放和图像格式转换
    音频信号的重采样

### 15.1 视频图像转换

    可以对照源码中doc/examples/scaling_video.c

    调用libswscale库，将YUV420P格式的图像转换为RGB24格式
    SwsContext 图像转换的核心结构
    sws_getContext 创建SwsContext结构指针
    sws_scale 图像转换

### 15.2 音频重采样

    可以对照源码中doc/examples/resampling_audio.c 但不相同

    调用libswresample库，对原音频信息进行冲采样
    SwrContext 音频信号重采样的核心结构
    swr_alloc 创建SwrContext结构指针
    swr_init 在设置好SwrContext参数后，初始化
    swr_convert 将按某采样率采样的一段输入音频信号按照指定采样率转换为输出音频信号