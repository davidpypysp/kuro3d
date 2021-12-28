
add_subdirectory(base)
add_subdirectory(renderer)
add_subdirectory(elements)
add_subdirectory(loader)
add_subdirectory(scene)

add_library(Core_Engine engine.cc)
target_link_libraries(Core_Engine
	gl_render_api
	renderer
	scene_manager
	texture_loader
	model_loader
	shader_manager
)