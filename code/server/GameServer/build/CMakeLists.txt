cmake_minimum_required(VERSION 2.6)
project(GAMESERVER)

#MESSAGE
message(STATUS "This is SOURCE dir " ${GAMESERVER_SOURCE_DIR})

include(${GAMESERVER_SOURCE_DIR}/../../odin.cmake)

ODIN_BUILD_OPTION()
ODIN_BUILD()
ODIN_COMMON_INCLUDE(${GAMESERVER_SOURCE_DIR})
ODIN_INSTALL_PATH(${GAMESERVER_SOURCE_DIR})
ODIN_LIBRARY_PATH(${GAMESERVER_SOURCE_DIR})

#INCLUDE
include_directories(${GAMESERVER_SOURCE_DIR}/../include)

#SOURCE
aux_source_directory(${GAMESERVER_SOURCE_DIR}/../. MAIN_SRC)
aux_source_directory(${GAMESERVER_SOURCE_DIR}/../source SUB_SRC)

#GENERATE EXE
add_executable(gameserver ${MAIN_SRC} ${SUB_SRC})

#LINK LIBRARIES
target_link_libraries(gameserver servercore rt shared lua dl z crypt
  protobuf message mongoclient boost_system boost_filesystem boost_thread)

