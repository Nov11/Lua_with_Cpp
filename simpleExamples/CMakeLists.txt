add_executable(main main.cpp)
target_link_libraries(main ${LIBS})
add_executable(main2 main2.cpp)
target_link_libraries(main2 ${LIBS})
add_custom_command(TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/scripts ${CMAKE_CURRENT_BINARY_DIR}/scripts )