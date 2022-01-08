add_library(loader.model_loader model_loader.cc)
target_link_libraries(loader.model_loader
	base.mesh_comp
	base.mesh_basic_material
	scene.scene_manager
    assimp
)

add_library(loader.texture_loader texture_loader.cc)
