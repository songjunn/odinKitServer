cmake_minimum_required(VERSION 2.6)
project(LOGINSERVER)

#MESSAGE
message(STATUS "This is SOURCE dir " ${LOGINSERVER_SOURCE_DIR})

include(${LOGINSERVER_SOURCE_DIR}/../../odin.cmake)

ODIN_BUILD_OPTION()
ODIN_BUILD()
ODIN_COMMON_INCLUDE(${LOGINSERVER_SOURCE_DIR})
ODIN_INSTALL_PATH(${LOGINSERVER_SOURCE_DIR})
ODIN_LIBRARY_PATH(${LOGINSERVER_SOURCE_DIR})

#INCLUDE
include_directories(${LOGINSERVER_SOURCE_DIR}/../include)

#SOURCE
aux_source_directory(${LOGINSERVER_SOURCE_DIR}/../. MAIN_SRC)
aux_source_directory(${LOGINSERVER_SOURCE_DIR}/../source SUB_SRC)

#GENERATE EXE
add_executable(loginserver ${MAIN_SRC} ${SUB_SRC})

#LINK LIBRARIES
target_link_libraries(loginserver servercore rt shared lua dl z crypt
  protobuf message mongoclient boost_system boost_filesystem boost_thread curl)
