## 13-使用FFmpeg SDK进行音视频文件的解封装与封装

    调用libavformat库中相关的API，对音视频文件进行解封装和封装

### 13.1 音视频文件的解封装

    可以对照源码中doc/examples/demuxing_decoding.c

    AVFormatContext 文件上下文结构
    avformat_open_input 打开输入的音视频文件或者网络媒体流，并初步探测输入数据的格式
                        解析与某个封装格式对应的头文件中的流信息
    avformat_find_stream_info 解析输入文件中的音视频流信息
    AVStream 用于表示音视频输入文件中所包含的一路音频流、视频流或字幕流
    av_find_best_stream 方便选择关注的流序号

### 13.2 音频流与视频流文件的封装

    可以对照源码中doc/examples/muxing.c 但是这个是从图片读起，和音频混合。
    也可以参照源码中doc/examples/remuxing.c 但是也不太相同

    将音频流和视频流复用到输出文件需要三步
    1.写入输出文件的头结构
    2.循环写入音频包和视频包
        将音频包和视频包循环写入输出文件分以下三步
            1.从输入文件中读取音频包或者视频包
            2.确定音频包和视频包的时间戳，判断写入顺序
            3.将码流包写入输出文件
    3.写入输出文件的尾结构
        