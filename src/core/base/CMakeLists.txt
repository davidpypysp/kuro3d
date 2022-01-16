add_library(base.mesh_flat_material mesh_flat_material.cc)

add_library(base.mesh_basic_material mesh_basic_material.cc)

add_library(base.camera_comp camera_comp.cc)

add_gtest(base.camera_comp_test camera_comp_test.cc)
target_link_libraries(base.camera_comp_test
	base.camera_comp
)

