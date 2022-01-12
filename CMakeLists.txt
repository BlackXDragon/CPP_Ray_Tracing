cmake_minimum_required(VERSION 3.19.2)

project(CRT VERSION 1.0)

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