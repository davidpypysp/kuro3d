add_library(scene_node scene_node.cc)

add_library(scene_manager scene_manager.cc)
target_link_libraries(scene_manager cube_geometry)

add_library(scene_utils scene_utils.cc)

add_library(scene
	scene_node
	scene_manager
	scene_utils
)