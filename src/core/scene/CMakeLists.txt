add_library(scene_scene_node scene_node.cc)

add_library(scene_scene_manager scene_manager.cc)
target_link_libraries(scene_scene_manager
	scene_scene_node
	elements_cube_geometry
)
