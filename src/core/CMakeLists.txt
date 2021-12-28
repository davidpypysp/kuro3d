
add_subdirectory(renderer)
add_subdirectory(elements)
add_subdirectory(model)
add_subdirectory(scene)

add_library(core engine.cc)
target_link_libraries(core
	geometry
	gl_render_api
	material
	shader_manager
	shader
	texture_loader
	renderer
)
target_link_libraries(core
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

target_link_libraries(core
	scene_node
	scene_manager
	scene_utils
)
target_link_libraries(core
	model_loader
)