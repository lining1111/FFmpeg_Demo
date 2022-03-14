include_directories(.)
add_executable(VideoScalingMain VideoScalingMain.cpp)
target_link_libraries(VideoScalingMain ${LINK_LIBS} ${FFMPEG_LIBS})