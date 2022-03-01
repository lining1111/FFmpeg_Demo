cmake_minimum_required(VERSION 3.19)
project(FFmpeg_Demo)

set(LINK_LIBS m pthread jpeg iconv sqlite3 ssl crypto x264)
set(FFMPEG_LIBS avcodec avformat avutil swresample swscale avfilter)

set(CMAKE_CXX_STANDARD 11)

add_executable(FFmpeg_Demo main.cpp)

add_subdirectory(chapter10)