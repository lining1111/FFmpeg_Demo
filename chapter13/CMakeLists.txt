##demuxer
add_executable(demuxer demuxer.cpp
        ../src/demuxer_core.cpp)
target_link_libraries(demuxer ${FFMPEG_LIBS} ${LINK_LIBS})

##muxer
add_executable(muxer muxer.cpp
        ../src/muxer_core.cpp)
target_link_libraries(muxer ${FFMPEG_LIBS} ${LINK_LIBS})