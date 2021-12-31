# add_library(renderer_geometry geometry.cc)

add_library(renderer_gl_render_api gl_render_api.cc)
target_link_libraries(renderer_gl_render_api
	${GLAD_LIBRARIES}
)

add_gtest(renderer_gl_render_api_test gl_render_api_test.cc)
target_link_libraries(renderer_gl_render_api_test
	renderer_gl_render_api
)

# add_library(renderer_shader_manager shader_manager.cc)

# add_library(renderer_renderer renderer.cc)
# target_link_libraries(renderer_renderer
# 	elements_visual_pack
# 	base_shader
# )

