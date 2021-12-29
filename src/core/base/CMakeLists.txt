# add_library(base_shader shader.cc)

# add_library(base_material material.cc)

add_library(base_camera_comp camera_comp.cc)

add_gtest(base_camera_comp_test camera_comp_test.cc)
target_link_libraries(base_camera_comp_test
	base_camera_comp
)

