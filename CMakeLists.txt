cmake_minimum_required(VERSION 3.16.2)

project(CRT VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#DOWNLOAD ALL THE SUBMODULES
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

#CHECK ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/thread_pool/README.md")
    message(FATAL_ERROR "The thread_pool submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

option(THREADING "Use multithreading" ON)

IF(THREADING)
	add_compile_definitions("THREADING")
    set(THREAD_POOL_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/external/thread-pool")
ENDIF(THREADING)

set(${PROJECT_NAME}_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(external)
add_subdirectory(src)

add_executable(${PROJECT_NAME}-bin render.cpp)

target_link_libraries(${PROJECT_NAME}-bin ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}-bin PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(TARGETS ${PROJECT_NAME}-bin DESTINATION bin)
install(DIRECTORY ${${PROJECT_NAME}_INCLUDE_DIR} DESTINATION .)
install(DIRECTORY ${THREAD_POOL_INCLUDE_DIR} DESTINATION external)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set (CPACK_NSIS_EXTRA_INSTALL_COMMANDS "
	CreateShortCut '$SMPROGRAMS\\\\$STARTMENU_FOLDER\\\\CRT.lnk' '$INSTDIR\\\\bin\\\\CRT.exe'
    ")

set (CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS "
    Delete '$SMPROGRAMS\\\\$STARTMENU_FOLDER\\\\CRT.lnk'
    ")
include(CPack)
