add_library(ray ray.cpp ray.h)

target_include_directories(ray
	PUBLIC ${PROJECT_SOURCE_DIR}/src/vector3d)

target_include_directories(ray
	PUBLIC ${PROJECT_SOURCE_DIR}/src/vector3d)

target_link_libraries(ray vector3d)