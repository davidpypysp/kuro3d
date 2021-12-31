# add_library(renderer_geometry geometry.cc)

add_library(renderer_gl_render_api gl_render_api.cc)
target_link_libraries(renderer_gl_render_api
	${GLAD_LIBRARIES}
)

add_gtest(renderer_gl_render_api_test gl_render_api_test.cc)
target_link_libraries(renderer_gl_render_api_test
	renderer_gl_render_api
)

add_library(renderer_shader_manager shader_manager.cc)

add_gtest(renderer_shader_manager_test shader_manager_test.cc)
target_link_libraries(renderer_shader_manager_test
	renderer_shader_manager
)

add_library(renderer_rendering_pipeline rendering_pipeline.cc)
target_link_libraries(renderer_rendering_pipeline
	renderer_shader_manager
	base_camera_comp
	scene_scene_node
)

add_gtest(renderer_rendering_pipeline_test rendering_pipeline_test.cc)
target_link_libraries(renderer_rendering_pipeline_test
	renderer_rendering_pipeline
)

# add_library(renderer_renderer renderer.cc)
# target_link_libraries(renderer_renderer
# 	elements_visual_pack
# 	base_shader
# )

