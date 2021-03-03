set(IMGUI_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/third_party/imgui)
file(GLOB IMGUI_SOURCES
    ${IMGUI_INCLUDE_DIR}/*.cpp
    ${IMGUI_INCLUDE_DIR}/misc/cpp/*.cpp
    ${IMGUI_INCLUDE_DIR}/backends/imgui_impl_opengl3.cpp
    ${IMGUI_INCLUDE_DIR}/backends/imgui_impl_glfw.cpp
)
add_library(imgui STATIC ${IMGUI_SOURCES})

add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)

include_directories(
    ${IMGUI_INCLUDE_DIR}
    ${IMGUI_INCLUDE_DIR}/backends
    ${OPENGL_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIR}
    ${GLAD_INCLUDE_DIR}
)

target_link_libraries(imgui
    ${OPENGL_LIBRARIES}
    ${GLFW_LIBRARIES}
    ${GLAD_LIBRARIES}
)

set_target_properties(imgui PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(imgui PROPERTIES FOLDER third_party)

set(IMGUI_LIBRARIES imgui)
