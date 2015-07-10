cmake_minimum_required(VERSION 2.6)
project(CENTRALSERVER)

#MESSAGE
message(STATUS "This is SOURCE dir " ${CENTRALSERVER_SOURCE_DIR})

include(${CENTRALSERVER_SOURCE_DIR}/../../odin.cmake)

ODIN_BUILD_OPTION()
ODIN_BUILD()
ODIN_COMMON_INCLUDE(${CENTRALSERVER_SOURCE_DIR})
ODIN_INSTALL_PATH(${CENTRALSERVER_SOURCE_DIR})
ODIN_LIBRARY_PATH(${CENTRALSERVER_SOURCE_DIR})

#INCLUDE
include_directories(${CENTRALSERVER_SOURCE_DIR}/../include)

#SOURCE
aux_source_directory(${CENTRALSERVER_SOURCE_DIR}/../ MAIN_SRC)

#GENERATE EXE
add_executable(centralserver ${MAIN_SRC} )

#LINK LIBRARIES
target_link_libraries(centralserver servercore rt shared lua dl z crypt
  protobuf message mongoclient boost_system boost_filesystem boost_thread)

