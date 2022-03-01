##video_encoder
add_executable(video_encoder video_encoder.cpp
        ../src/io_data.cpp
        ../src/video_encoder_core.cpp)
target_link_libraries(video_encoder ${FFMPEG_LIBS} ${LINK_LIBS})

##video_decoder
add_executable(video_decoder video_decoder.cpp
        ../src/io_data.cpp
        ../src/video_decoder_core.cpp)
target_link_libraries(video_decoder ${FFMPEG_LIBS} ${LINK_LIBS})