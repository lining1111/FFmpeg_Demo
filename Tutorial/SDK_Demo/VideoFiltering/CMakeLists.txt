include_directories(.)
add_executable(VideoFilteringMain VideoFilteringMain.cpp Filter.cpp Frame.cpp IOFiles.cpp)
target_link_libraries(VideoFilteringMain ${LINK_LIBS} ${FFMPEG_LIBS})