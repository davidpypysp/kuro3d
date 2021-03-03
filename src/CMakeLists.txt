set(EXE_NAME kuro3d)
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR})

file(GLOB_RECURSE PROJECT_HEADERS
    ${CMAKE_SOURCE_DIR}/src/*.h
)
file(GLOB_RECURSE PROJECT_SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cc
)

add_executable(${EXE_NAME} ${PROJECT_HEADERS} ${PROJECT_SOURCES})


target_link_libraries(${EXE_NAME}
    ${IMGUI_LIBRARIES}
    assimp
)

install(TARGETS ${EXE_NAME}
    DESTINATION ${CMAKE_BINARY_DIR}
)

file(GLOB PROJECT_SHADERS
    ${CMAKE_SOURCE_DIR}/src/core/shaders/*.comp
    ${CMAKE_SOURCE_DIR}/src/core/shaders/*.frag
    ${CMAKE_SOURCE_DIR}/src/core/shaders/*.geom
    ${CMAKE_SOURCE_DIR}/src/core/shaders/*.vert
)

add_custom_command(
    TARGET ${EXE_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SHADERS} $<TARGET_FILE_DIR:${EXE_NAME}>
    # DEPENDS ${PROJECT_SHADERS}
    COMMENT "Copy shader files..."
)
add_custom_command(
    TARGET ${EXE_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources/ $<TARGET_FILE_DIR:${EXE_NAME}>/resources
    # DEPENDS ${PROJECT_SHADERS}
    COMMENT "Copy resource..."
)

