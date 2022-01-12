add_library(read_config read_config.cpp read_config.h)

target_include_directories(read_config
	PUBLIC ${PROJECT_SOURCE_DIR}/src/renderer
	PUBLIC ${PROJECT_SOURCE_DIR}/src/json)

target_include_directories(read_config
	PUBLIC ${PROJECT_SOURCE_DIR}/src/renderer)

target_link_libraries(read_config renderer)