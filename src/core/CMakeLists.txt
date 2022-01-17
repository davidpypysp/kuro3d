
add_subdirectory(base)
add_subdirectory(renderer)
add_subdirectory(loader)
add_subdirectory(scene)

add_library(core.context context.cc)
target_link_libraries(core.context
	renderer.renderer_controller
	loader.loader_controller
	scene.scene_controller
)

add_library(core.default_scenario default_scenario.cc)
target_link_libraries(core.default_scenario
	scene.scene_manager
	loader.model_loader
)

add_library(core.engine engine.cc)
target_link_libraries(core.engine
	core.context
	core.default_scenario
)

add_gtest(core.engine_test engine_test.cc)
target_link_libraries(core.engine_test
	core.engine
)