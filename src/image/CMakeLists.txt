add_library(image image.cpp image.h)

target_include_directories(image
	PUBLIC ${PROJECT_SOURCE_DIR}/src/color)

target_include_directories(image
	PUBLIC ${PROJECT_SOURCE_DIR}/src/color)

target_link_libraries(image color)