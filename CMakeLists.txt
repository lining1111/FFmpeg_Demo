cmake_minimum_required(VERSION 3.19)
project(FFmpeg_Demo)

include_directories(inc)

set(SRC_DIRS src)
foreach (src_dir ${SRC_DIRS})
    aux_source_directory(${src_dir} src_dir_file)
    set(SRC_FILES ${SRC_FILES} ${src_dir_file})
endforeach (src_dir)


set(LINK_LIBS m pthread jpeg iconv sqlite3 ssl crypto x264)
set(FFMPEG_LIBS avcodec avformat avutil swresample swscale avfilter)

set(CMAKE_CXX_STANDARD 11)

add_executable(FFmpeg_Demo main.cpp)

add_subdirectory(chapter10)
add_subdirectory(chapter11)
add_subdirectory(chapter12)
add_subdirectory(chapter13)
add_subdirectory(chapter14)
add_subdirectory(chapter15)

add_subdirectory(Tutorial/SDK_Demo)