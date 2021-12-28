
add_subdirectory(base)
add_subdirectory(renderer)
add_subdirectory(elements)
add_subdirectory(loader)
add_subdirectory(scene)

add_library(core_engine engine.cc)
target_link_libraries(core_engine
	renderer_gl_render_api
	renderer_renderer
	scene_scene_manager
	loader_texture_loader
	loader_model_loader
	renderer_shader_manager
)