# add_library(base_shader shader.cc)

# add_library(base_material material.cc)

add_library(base.camera_comp camera_comp.cc)

add_gtest(base.camera_comp_test camera_comp_test.cc)
target_link_libraries(base.camera_comp_test
	base.camera_comp
)

