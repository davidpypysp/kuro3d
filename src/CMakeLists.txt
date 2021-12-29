set(EXE_NAME kuro3d)
set(CMAKE_CXX_STANDARD 17)

# Gtest
enable_testing()
include(GoogleTest)

# Add header path
include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(core)
add_subdirectory(gui)

# Gui app
add_executable(${EXE_NAME} main.cc)
target_link_libraries(${EXE_NAME} gui_imgui)

# Copy shader files to destination
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



add_executable(hello_test hello_test.cc)
target_link_libraries(
  hello_test
  gtest_main
)
gtest_discover_tests(hello_test)