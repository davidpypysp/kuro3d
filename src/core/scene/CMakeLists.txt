add_library(scene_scene_node scene_node.cc)

add_gtest(scene_scene_node_test scene_node_test.cc)
target_link_libraries(scene_scene_node_test
	scene_scene_node
)

add_library(scene_scene_manager scene_manager.cc)

add_gtest(scene_scene_manager_test scene_manager_test.cc)
target_link_libraries(scene_scene_manager_test
	scene_scene_manager
)
