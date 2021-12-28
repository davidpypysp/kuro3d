add_library(model_loader model_loader.cc)
target_link_libraries(model_loader
	geometry
	mesh_pack
	mesh_basic_material
	mesh_flat_material
    assimp
)

add_library(texture_loader texture_loader.cc)

