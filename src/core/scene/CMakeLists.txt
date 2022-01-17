add_library(scene.scene_node scene_node.cc)

add_gtest(scene.scene_node_test scene_node_test.cc)
target_link_libraries(scene.scene_node_test
	scene.scene_node
)

add_library(scene.scene_manager scene_manager.cc)
target_link_libraries(scene.scene_manager
	scene.scene_node
)

add_gtest(scene.scene_manager_test scene_manager_test.cc)
target_link_libraries(scene.scene_manager_test
	scene.scene_manager
)