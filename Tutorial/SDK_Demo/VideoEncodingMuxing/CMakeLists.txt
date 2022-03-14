include_directories(.)
add_executable(EncodingMuxingMain EncodingMuxingMain.cpp CoderMuxer.cpp EncodingMuxingAudio.cpp EncodingMuxingVideo.cpp Stream.cpp)
target_link_libraries(EncodingMuxingMain ${LINK_LIBS} ${FFMPEG_LIBS})