

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

add_executable(251 251.cpp common.cpp)
target_link_libraries(251 ${LIBS})

add_executable(252 252.cpp common.cpp)
target_link_libraries(252 ${LIBS})

add_executable(253 253.cpp common.cpp)
target_link_libraries(253 ${LIBS})

add_executable(261 261.cpp common.cpp)
target_link_libraries(261 ${LIBS})
#add_custom_target(phonyyyy
#        COMMAND cp
#        ${CMAKE_CURRENT_SOURCE_DIR}/scripts ${CMAKE_CURRENT_BINARY_DIR}/scripts )

add_custom_command(TARGET 25 PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/scripts/config.lua ${CMAKE_CURRENT_BINARY_DIR}/scripts/config.lua )

add_custom_command(TARGET 252 PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/scripts/f.lua ${CMAKE_CURRENT_BINARY_DIR}/scripts/f.lua )

add_custom_command(TARGET 261 PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/scripts/calledinlua.lua ${CMAKE_CURRENT_BINARY_DIR}/scripts/calledinlua.lua )