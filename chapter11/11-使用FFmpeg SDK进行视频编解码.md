## 11-使用FFmpeg SDK进行视频编解码

    重点介绍如何使用libavcodec将图像序列编码为H.264的视频码流，以及如何将视频码流解码为YUV格式图像。
    并介绍libavcodec中常用的关键数据结构的定义和作用

### 11.1 libavcodec 视频编码

    可以对照源码中doc/examples/encode_video.c

    avcodec_find_encoder_by_name 传入字符串类型的编码器名称即可查找对应的编码器实例，
        具体的字符串内容，参考源码libavcodec/allcodecs.c中AVCodec类型的ff_xxxx_encoder
            如：传入libx264 使用x264编码器编码
                传入h264_nvenc 使用NVIDIA H.264编码器编码
    类似的功能还有avcodec_find_encoder 传入AVCodecID 枚举类型
    在FFmpeg中，没一个编码器对应一个上下文结构(AVCodecContext)，
    在编码开始前，通过avcodec_alloc_context3创建，再通过该上下文结构配置相应的编码参数
    AVCodecContext结构使用成员priv_data保存编解码器的配置信息，可以通过av_opt_set等方法进行设置
    avcodec_open2初始化编码器上下文，它会给AVCodecContext内部的数据成员分配内存空间，
    以进行编码参数的校验，并调用编码器内部的init函数进行初始化操作
    AVFrame 未压缩的图像
    针对视频编码器，其流程为从数据源获取图像格式的输入数据，保存为AVFrame对象，并传入编码器，从编码器中输出AVPacket结构
    AVFrame结构中data指针所保存的内存为待编码图像的像素数据，linesize获取data[]存储区的宽度
    AVPacket 压缩的视频码流
    码流数据保存在AVPacket结构的data指针指向的内存区中，size为数据长度
    av_packet_alloc 创建AVPacket并初始化
    av_frame_alloc 创建AVFrame并初始化 av_frame_get_buffer 按照参数给AVFrame分配内存空间
    encoding 编码循环体，至少实现以下三个功能
        1.从视频源中循环获取输入图像(如从输入文件中读取)
        2.将当前帧传入编码器进行编码，获取输出的码流包
        3.输出码流包中的压缩码流(如写出到输出文件)
    编码1帧图像数据，需要两个关键的API 
    avcodec_send_frame 将图像传入编码器
    avcodec_receive_packet 从编码器获取输出的码流

### 11.2 libavcodec 视频解码

    可以对照源码中doc/examples/decode_video.c

    AVCodecParserContext 是码流解析器的句柄，其作用是从一串二进制数据流中解析出符合某种编码标准的码流包
    使用av_parser_init可以根据指定的codec_id创建AVCodecParserContext
    decoding 解码循环体，至少实现以下三个功能
        1.从输入源循环获取码流包(如从输入文件中读取码流包)
        2.将当前帧传入解码器，获得输出的图像帧
        3.输出解码获得的图像帧(如将图像帧写入输出文件)
    想要从数据缓存区中解析出AVPacket结构，必须调用av_parser_parse2,当调用时，首先通过参数指定保存某一段码流数据
    的缓存区及其长度，然后通过输出poutbuf指针或poutbuf_size的值来判断是否读取了一个完整的AVPacket结构
    解码阶段，使用两个关键的API 
    avcodec_send_packet 将封装的二进制码流传入解码器
    avcodec_receive_frame 从解码器中获取解码输出的图像帧结构