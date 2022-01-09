add_library(imgui.window window.cc)
target_link_libraries(imgui.window
	${IMGUI_LIBRARIES}
)

add_library(imgui.object_inspector object_inspector.cc)
target_link_libraries(imgui.object_inspector
	imgui.window
)

add_library(imgui.scene_explorer scene_explorer.cc)
target_link_libraries(imgui.scene_explorer
	imgui.window
	scene.scene_manager
)

add_library(imgui.gui_base gui_base.cc)
target_link_libraries(imgui.gui_base
	imgui.window
)

add_library(imgui.gui_manager gui_manager.cc)
target_link_libraries(imgui.gui_manager
	imgui.gui_base
	imgui.scene_explorer
	imgui.object_inspector
)

add_library(imgui.gui_system gui_system.cc)
target_link_libraries(imgui.gui_system
	imgui.gui_manager
	core.engine
)

# add_library(gui_imgui
# 	gui_base.cc
# 	gui_main.cc
# 	gui.cc
# 	object_inspector.cc
# 	scene_explorer.cc
# 	window.cc
# )

# target_link_libraries(gui_imgui
# 	core_engine
# 	${IMGUI_LIBRARIES}
# )
