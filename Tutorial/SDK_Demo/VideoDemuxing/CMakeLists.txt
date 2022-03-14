include_directories(.)
add_executable(VideoDemuxingMain VideoDemuxingMain.cpp AVDecoder.cpp DemuxingContext.cpp)
target_link_libraries(VideoDemuxingMain ${LINK_LIBS} ${FFMPEG_LIBS})