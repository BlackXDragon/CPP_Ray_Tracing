add_library(${PROJECT_NAME} renderer.cpp read_config.cpp objects/sphere.cpp material.cpp lights/light.cpp image.cpp ray.cpp color.cpp vector3d.cpp)

target_include_directories(${PROJECT_NAME}
	PUBLIC ${${PROJECT_NAME}_INCLUDE_DIR})

if(THREADING)
	target_link_libraries(${PROJECT_NAME} PRIVATE thread_pool)
endif()