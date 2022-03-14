add_executable(VideoEncodingMain VideoEncodingMain.cpp Encoder.cpp InputOutput.cpp)
target_link_libraries(VideoEncodingMain ${LINK_LIBS} ${FFMPEG_LIBS})