add_library(renderer_geometry geometry.cc)

add_library(renderer_gl_render_api gl_render_api.cc)

add_library(renderer_shader_manager shader_manager.cc)

add_library(renderer_renderer renderer.cc)
target_link_libraries(renderer_renderer
	elements_visual_pack
	base_shader
)