##video_filter
add_executable(video_filter video_filter.cpp
        ../src/io_data.cpp
        ../src/video_filter_core.cpp)
target_link_libraries(video_filter ${FFMPEG_LIBS} ${LINK_LIBS})

##audio_filter
add_executable(audio_filter audio_filter.cpp
        ../src/io_data.cpp
        ../src/audio_filter_core.cpp)
target_link_libraries(audio_filter ${FFMPEG_LIBS} ${LINK_LIBS})