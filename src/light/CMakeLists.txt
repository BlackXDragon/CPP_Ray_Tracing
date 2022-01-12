add_library(light light.cpp light.h)

target_include_directories(light
	PUBLIC ${PROJECT_SOURCE_DIR}/src/color
	PUBLIC ${PROJECT_SOURCE_DIR}/src/vector3d
	PUBLIC ${PROJECT_SOURCE_DIR}/src/material
	PUBLIC ${PROJECT_SOURCE_DIR}/src/ray)

target_include_directories(light
	PUBLIC ${PROJECT_SOURCE_DIR}/src/color
	PUBLIC ${PROJECT_SOURCE_DIR}/src/vector3d
	PUBLIC ${PROJECT_SOURCE_DIR}/src/material
	PUBLIC ${PROJECT_SOURCE_DIR}/src/ray)

target_link_libraries(light color vector3d material ray)