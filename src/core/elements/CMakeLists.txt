add_library(elements_atom atom.cc)

add_library(elements_scene_atom scene_atom.cc)
target_link_libraries(elements_scene_atom
	elements_atom
)

add_library(elements_camera_pack camera_pack.cc)

add_library(elements_camera_atom camera_atom.cc)
target_link_libraries(elements_camera_atom
	elements_camera_pack
	elements_scene_atom
)

add_library(elements_cube_geometry cube_geometry.cc)

add_library(elements_mesh_basic_material mesh_basic_material.cc)
target_link_libraries(elements_mesh_basic_material
	base_material
)

add_library(elements_mesh_flat_material mesh_flat_material.cc)

add_library(elements_pack pack.cc)

add_library(elements_visual_pack visual_pack.cc)
target_link_libraries(elements_visual_pack
	elements_pack
)

add_library(elements_mesh_pack mesh_pack.cc)
target_link_libraries(elements_mesh_pack
	elements_camera_atom
)
