

add_executable(main main.cpp)
target_link_libraries(main ${LIBS})
add_executable(main2 main2.cpp)
target_link_libraries(main2 ${LIBS})
add_executable(241 24.1.cpp)
target_link_libraries(241 ${LIBS})

add_executable(2423 2423.cpp)
target_link_libraries(2423 ${LIBS})

add_executable(25 25.cpp common.cpp)
target_link_libraries(25 ${LIBS})

#add_custom_target(phonyyyy
#        COMMAND cp
#        ${CMAKE_CURRENT_SOURCE_DIR}/scripts ${CMAKE_CURRENT_BINARY_DIR}/scripts )

add_custom_command(TARGET 25 PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/scripts ${CMAKE_CURRENT_BINARY_DIR}/scripts )