## 12-使用FFmpeg SDK进行音频编解码

    着重介绍如何调用libavcodec库中相关API，将PCM格式的原始音频采样数据编码为MP3格式或者AAC格式的音频文件，以及
    将MP3格式或者AAC格式的音频文件解码为PCM格式的音频采样数据

### 12.1 libavcodec 音频编码

    可以对照源码中doc/examples/encode_audio.c,但是有很大不同，跟本工程的video_encoder类似

    初始化和视频编码器类似，但是传入的参数为音频采样格式、音频采样率、声道布局和声道数等信息
    音频采样格式可分为packed和planar两大类，在每个大类中，根据保存采样点的数据类型又细分若干类型
    单声道音频，packed和planar保存方式无实际区别
    多声道、立体音频，packed格式保存的采样数据，各个声道之间交替存储。planar格式是不同声道连续存储

### 12.2 libavcodec 音频解码
    
    可以对照源码中doc/examples/decode_audio.c,但是有很大不同，跟本工程的video_decoder类似