add_library(atom atom.cc)

add_library(scene_atom scene_atom.cc)
target_link_libraries(scene_atom atom)

add_library(camera_pack camera_pack.cc)

add_library(camera_atom camera_atom.cc)
target_link_libraries(camera_atom camera_pack scene_atom)

add_library(cube_geometry cube_geometry.cc)

add_library(mesh_basic_material mesh_basic_material.cc)
target_link_libraries(mesh_basic_material material)

add_library(mesh_flat_material mesh_flat_material.cc)

add_library(pack pack.cc)

add_library(mesh_pack mesh_pack.cc)
target_link_libraries(mesh_pack camera_atom)


add_library(elements
	atom
	camera_atom
	camera_pack
	cube_geometry
	mesh_basic_material
	mesh_flat_material
	pack
	mesh_pack
	scene_atom
)