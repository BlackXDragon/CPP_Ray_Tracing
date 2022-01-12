add_library(sphere sphere.cpp sphere.h)

target_include_directories(sphere
	PUBLIC ${PROJECT_SOURCE_DIR}/src/vector3d
	PUBLIC ${PROJECT_SOURCE_DIR}/src/color
	PUBLIC ${PROJECT_SOURCE_DIR}/src/material
	PUBLIC ${PROJECT_SOURCE_DIR}/src/ray)

target_include_directories(sphere
	PUBLIC ${PROJECT_SOURCE_DIR}/src/vector3d
	PUBLIC ${PROJECT_SOURCE_DIR}/src/color
	PUBLIC ${PROJECT_SOURCE_DIR}/src/material
	PUBLIC ${PROJECT_SOURCE_DIR}/src/ray)

target_link_libraries(sphere material vector3d color ray)