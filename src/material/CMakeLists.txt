add_library(material material.cpp material.h)

target_include_directories(material
	PUBLIC ${PROJECT_SOURCE_DIR}/src/color)

target_include_directories(material
	PUBLIC ${PROJECT_SOURCE_DIR}/src/color)

target_link_libraries(material color)