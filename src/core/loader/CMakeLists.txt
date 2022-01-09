add_library(loader.texture_loader texture_loader.cc)

add_gtest(loader.texture_loader_test texture_loader_test.cc)
target_link_libraries(loader.texture_loader_test
	loader.texture_loader
)

add_library(loader.model_loader model_loader.cc)
target_link_libraries(loader.model_loader
    assimp
	loader.texture_loader
	scene.scene_manager
)

add_gtest(loader.model_loader_test model_loader_test.cc)
target_link_libraries(loader.model_loader_test
	loader.model_loader
)

add_library(loader.loader_controller loader_controller.cc)
target_link_libraries(loader.loader_controller
	loader.model_loader
)

