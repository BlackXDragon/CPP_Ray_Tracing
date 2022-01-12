add_executable(${PROJECT_NAME} render.cpp)

add_subdirectory(vector3d)
add_subdirectory(color)
add_subdirectory(material)
add_subdirectory(sphere)
add_subdirectory(ray)
add_subdirectory(image)
add_subdirectory(light)
add_subdirectory(renderer)
add_subdirectory(read_config)

target_include_directories(${PROJECT_NAME}
	PUBLIC vector3d
	PUBLIC color
	PUBLIC material
	PUBLIC sphere
	PUBLIC ray
	PUBLIC image
	PUBLIC light
	PUBLIC renderer
	PUBLIC read_config
	PUBLIC ${PROJECT_SOURCE_DIR}/src)

target_link_directories(${PROJECT_NAME}
	PUBLIC vector3d
	PUBLIC color
	PUBLIC material
	PUBLIC sphere
	PUBLIC ray
	PUBLIC image
	PUBLIC light
	PUBLIC renderer
	PUBLIC read_config
	PUBLIC ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(${PROJECT_NAME}  vector3d ray image light material color sphere renderer read_config)