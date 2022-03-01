## 07-FFmpeg的基本操作

### 7.1 FFmpeg概述
    ffplay视频播放器
    ffprobe 媒体信息解析器
    ffmpeg
### 7.2 ffplay的基本使用方法
    显示版本    ffplay -version
    显示编译选项  ffplay -buildconf
    设置日志级别  ffplay -loglevel debug -i input.avi 
                日志级别 quiet panic fatal error warning info verbose debug trace
    全屏播放    ffplay -i input.avi -fs
    指定输入视频的宽、高和帧率   ffplay -i input_1280x720.yuv -f rawvideo -video_size 1280x720 -framerate 25
    禁用音频流、视频流、字幕流 -an 禁用音频流 -vn 禁用视频流 -sn 禁用字幕流
    指定播放的起始时间和时长 ffplay -ss 300 -t 20 -i input.avi -autoexit 从第300秒开始播放，20秒后结束，并自动退出
    指定播放音量 ffplay -volumn 60 0i input.avi
    设置播放窗口  -window_title 指定播放窗口标题
                -noborder 播放窗口无边框
                -alwaysontop 播放窗口置顶
                -left x pos 设置播放窗口的左方位置
                -top y pos 设置播放窗口的上方位置
                -x width 指定播放窗口的宽度
                -y height 指定播放窗口的高度

### 7.3 ffprobe的基本使用方法
    显示全部信息 ffprobe -i input.avi
    显示更详细的封装格式信息 ffprobe -show_format -i test.mp4
    显示每一路媒体流信息 ffprobe -show_streams -i test.mp4
    显示每个码流包的信息 ffprobe -show_packets -i test.mp4
    显示媒体流和码流包的负载信息 ffprobe -show_streams -show_data -i test.mp4
    显示每一帧图像的信息 ffprobe -show_frames -i test.mp4
    指定检测信息的输出格式 ffprobe -of json -i test.mp4
        常用格式有default、compact/CSV、flat、ini、json、xml
        ffprobe -show_frames -of=default=nk=1:nw=1 -i test.mp4
        ffprobe -show_frames -of csv=nk=0 -i test.mp4 >> test_mp4.csv
        ffprobe -show_frames -of flat=sep_char='-' -i test.mp4
        ffprobe -show_frames -of ini -i test.mp4
        ffprobe -show_frames -of json=c=1 -i test.mp4

### 7.4 ffmpeg的基本使用方法
    显示版本 ffmpeg -version
    查看编译配置参数 ffmpeg -buildconf
    显示支持的解复用器格式 ffmpeg -demuxers
    显示支持的复用器格式 ffmpeg -nuxers
    显示支持的所有输入格式和输出格式 ffmpeg -formats
    显示支持的解码器 ffmpeg -decoders
    显示支持的编码器 ffmpeg -encoders
    显示支持的媒体协议 ffmpeg -protocols
    显示支持的硬件加速框架 ffmpeg -hwaccels
    具体的命令较为复杂，详看 http://ffmpeg.org/ffmpeg.html
