include_directories(.)
add_executable(VideoRemuxingMain VideoRemuxingMain.cpp)
target_link_libraries(VideoRemuxingMain ${LINK_LIBS} ${FFMPEG_LIBS})