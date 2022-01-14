cmake_minimum_required(VERSION 3.16.2)

project(CRT VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(THREADING "Use multithreading" ON)

IF(THREADING)
	add_compile_definitions("THREADING")
    set(THREAD_POOL_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/external/thread-pool")
ENDIF(THREADING)

add_subdirectory(external)
add_subdirectory(src)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set (CPACK_NSIS_EXTRA_INSTALL_COMMANDS "
	CreateShortCut '$SMPROGRAMS\\$STARTMENU_FOLDER\\CRT.lnk' '$INSTDIR\\bin\\CRT.exe'
    ")

set (CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS "
    Delete '$SMPROGRAMS\\$STARTMENU_FOLDER\\CRT.lnk'
    ")
include(CPack)