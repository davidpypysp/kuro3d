add_library(geometry geometry.cc)

add_library(gl_render_api gl_render_api.cc)

add_library(material material.cc)

add_library(shader_manager shader_manager.cc)

add_library(shader shader.cc)

add_library(texture_loader texture_loader.cc)

add_library(renderer renderer.cc)
target_link_libraries(renderer
	visual_pack
	shader
)