add_library(renderer renderer.cpp renderer.h)

target_include_directories(renderer
	PUBLIC ${PROJECT_SOURCE_DIR}/src/vector3d
	PUBLIC ${PROJECT_SOURCE_DIR}/src/color
	PUBLIC ${PROJECT_SOURCE_DIR}/src/sphere
	# PUBLIC ${PROJECT_SOURCE_DIR}/src/material
	PUBLIC ${PROJECT_SOURCE_DIR}/src/image
	PUBLIC ${PROJECT_SOURCE_DIR}/src/light)

target_include_directories(renderer
	PUBLIC ${PROJECT_SOURCE_DIR}/src/vector3d
	PUBLIC ${PROJECT_SOURCE_DIR}/src/color
	PUBLIC ${PROJECT_SOURCE_DIR}/src/sphere
	# PUBLIC ${PROJECT_SOURCE_DIR}/src/material
	PUBLIC ${PROJECT_SOURCE_DIR}/src/image
	PUBLIC ${PROJECT_SOURCE_DIR}/src/light)

target_link_libraries(renderer vector3d color sphere image light)