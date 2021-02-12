set(EXE_NAME kuro3d)

file(GLOB_RECURSE PROJECT_SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cc
)


add_executable(${EXE_NAME} ${PROJECT_SOURCES})

include_directories(${CMAKE_SOURCE_DIR})

target_link_libraries(${EXE_NAME}
    ${IMGUI_LIBRARIES}
)

install(
    TARGETS ${EXE_NAME}
    DESTINATION ${CMAKE_BINARY_DIR}
)
