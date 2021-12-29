add_library(base_shader shader.cc)

add_executable(base_shader_test shader_test.cc)
target_link_libraries(base_shader_test
	gtest_main
	base_shader
	core_engine
	${IMGUI_LIBRARIES}
)
gtest_discover_tests(base_shader_test)

add_library(base_texture texture.cc)

add_library(base_material material.cc)