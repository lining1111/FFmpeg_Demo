##audio_encoder
add_executable(audio_encoder audio_encoder.cpp
        ../src/io_data.cpp
        ../src/audio_encoder_core.cpp)
target_link_libraries(audio_encoder ${FFMPEG_LIBS} ${LINK_LIBS})

##audio_decoder
add_executable(audio_decoder audio_decoder.cpp
        ../src/io_data.cpp
        ../src/audio_decoder_core.cpp)
target_link_libraries(audio_decoder ${FFMPEG_LIBS} ${LINK_LIBS})