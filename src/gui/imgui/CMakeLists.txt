add_library(imgui.window window.cc)
target_link_libraries(imgui.window)

add_library(imgui.object_inspector object_inspector.cc)
target_link_libraries(imgui.object_inspector
	imgui.window
	scene.scene_node
)

add_library(imgui.scene_explorer scene_explorer.cc)
target_link_libraries(imgui.scene_explorer
	imgui.window
	scene.scene_manager
)

add_library(imgui.gui_base gui_base.cc)
target_link_libraries(imgui.gui_base
	imgui.window
	${IMGUI_LIBRARIES}
)

add_library(imgui.gui_manager gui_manager.cc)
target_link_libraries(imgui.gui_manager
	imgui.gui_base
	imgui.scene_explorer
	imgui.object_inspector
	core.engine
)

add_gtest(imgui.gui_manager_test gui_manager_test.cc)
target_link_libraries(imgui.gui_manager_test
	imgui.gui_manager
)

add_library(imgui.gui_system gui_system.cc)
target_link_libraries(imgui.gui_system
	imgui.gui_manager
)

add_gtest(imgui.gui_system_test gui_system_test.cc)
target_link_libraries(imgui.gui_system_test
	imgui.gui_system
)

add_library(imgui.context context.cc)
target_link_libraries(imgui.context
	imgui.gui_system
	imgui.gui_manager
)

add_library(imgui.app app.cc)
target_link_libraries(imgui.app
	imgui.context
)

add_gtest(imgui.app_test app_test.cc)
target_link_libraries(imgui.app_test
	imgui.app
)
