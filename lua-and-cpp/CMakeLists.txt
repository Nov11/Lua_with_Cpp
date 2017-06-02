add_executable(a a.cpp)
target_link_libraries(a ${LIBS})
add_executable(b b.cpp)
target_link_libraries(b ${LIBS})
add_executable(callback callback.cpp)
target_link_libraries(callback ${LIBS})

add_custom_command(TARGET a POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/scripts ${CMAKE_CURRENT_BINARY_DIR}/scripts )
#message(${CMAKE_CURRENT_SOURCE_DIR} " aa " ${CMAKE_CURRENT_BINARY_DIR}/scripts)