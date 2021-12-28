add_library(scene_node scene_node.cc)

add_library(scene_manager scene_manager.cc)
target_link_libraries(scene_manager
	scene_node
	cube_geometry
)

add_library(scene_utils scene_utils.cc)