include_directories(.)
add_executable(VideoDecodingMain VideoDecodingMain.cpp Decoder.cpp InputOutput.cpp)
target_link_libraries(VideoDecodingMain ${LINK_LIBS} ${FFMPEG_LIBS})