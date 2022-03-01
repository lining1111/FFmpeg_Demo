##video_transformer
add_executable(video_transformer video_transformer.cpp
        ../src/io_data.cpp
        ../src/video_swscale_core.cpp)
target_link_libraries(video_transformer ${FFMPEG_LIBS} ${LINK_LIBS})

##audio_resampler
add_executable(audio_resampler audio_resampler.cpp
        ../src/io_data.cpp
        ../src/audio_resampler_core.cpp)
target_link_libraries(audio_resampler ${FFMPEG_LIBS} ${LINK_LIBS})