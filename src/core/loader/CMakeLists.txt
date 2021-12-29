add_library(loader_model_loader model_loader.cc)
target_link_libraries(loader_model_loader
	renderer_geometry
	elements_mesh_pack
	elements_mesh_basic_material
	elements_mesh_flat_material
    assimp
)

add_library(loader_texture_loader texture_loader.cc)