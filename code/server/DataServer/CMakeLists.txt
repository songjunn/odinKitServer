cmake_minimum_required(VERSION 2.6)
project(DATASERVER)

#MESSAGE
message(STATUS "This is SOURCE dir " ${DATASERVER_SOURCE_DIR})

include(${DATASERVER_SOURCE_DIR}/../../odin.cmake)

ODIN_BUILD_OPTION()
ODIN_BUILD()
ODIN_COMMON_INCLUDE(${DATASERVER_SOURCE_DIR})
ODIN_INSTALL_PATH(${DATASERVER_SOURCE_DIR})
ODIN_LIBRARY_PATH(${DATASERVER_SOURCE_DIR})

#INCLUDE
include_directories(${DATASERVER_SOURCE_DIR}/../include)
include_directories(${DATASERVER_SOURCE_DIR}/../../common/template)

#SOURCE
aux_source_directory(${DATASERVER_SOURCE_DIR}/../. MAIN_SRC)
aux_source_directory(${DATASERVER_SOURCE_DIR}/../source SUB_SRC)

#GENERATE EXE
add_executable(dataserver ${MAIN_SRC} ${SUB_SRC})

#LINK LIBRARIES
target_link_libraries(dataserver servercore rt shared lua dl z crypt
  protobuf message mongoclient boost_system boost_filesystem boost_thread)
