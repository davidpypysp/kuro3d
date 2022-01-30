add_library(loader.texture_loader texture_loader.cc)

add_gtest(loader.texture_loader_test texture_loader_test.cc)
target_link_libraries(loader.texture_loader_test
	loader.texture_loader
)

add_library(loader.model_loader model_loader.cc)
target_link_libraries(loader.model_loader
    assimp::assimp
	loader.texture_loader
	base.mesh_basic_material
	base.mesh_flat_material
	scene.scene_manager
)

add_gtest(loader.model_loader_test model_loader_test.cc)
target_link_libraries(loader.model_loader_test
	loader.model_loader
)
