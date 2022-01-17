# add_library(renderer.geometry geometry.cc)

add_library(renderer.gl_render_api gl_render_api.cc)
target_link_libraries(renderer.gl_render_api
	${GLAD_LIBRARIES}
)

add_gtest(renderer.gl_render_api_test gl_render_api_test.cc)
target_link_libraries(renderer.gl_render_api_test
	renderer.gl_render_api
)

add_library(renderer.shader_manager shader_manager.cc)

add_gtest(renderer.shader_manager_test shader_manager_test.cc)
target_link_libraries(renderer.shader_manager_test
	renderer.shader_manager
)

add_library(renderer.rendering_pipeline rendering_pipeline.cc)
target_link_libraries(renderer.rendering_pipeline
	renderer.shader_manager
	base.camera_comp
	base.mesh_basic_material
	base.mesh_flat_material
	scene.scene_node
)

add_gtest(renderer.rendering_pipeline_test rendering_pipeline_test.cc)
target_link_libraries(renderer.rendering_pipeline_test
	renderer.rendering_pipeline
)

add_library(renderer.renderer renderer.cc)
target_link_libraries(renderer.renderer
	renderer.rendering_pipeline
	scene.scene_manager
)

add_gtest(renderer.renderer_test renderer_test.cc)
target_link_libraries(renderer.renderer_test
	renderer.renderer
)
