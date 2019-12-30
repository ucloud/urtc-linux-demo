
project(urtcenginedemo)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_BUILD_TYPE "release")
set(CMAKE_CXX_FLAGS "-Wall -std=gnu++11 -g -o3 -fpermissive -fPIC")
set(ENGINEDEMO_LDFLAGS "-Wl,-rpath ")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(THIRDPARTY ${PROJECT_SOURCE_DIR}/third_party/rapid)
set(RAPIDJSON ${THIRDPARTY}/rapidjson/include)
set(URTC_MEDIA_PATH ${PROJECT_SOURCE_DIR}/urtclib/interface)
set(URTC_MEDIA_LIB ${PROJECT_SOURCE_DIR}/urtclib/lib)


aux_source_directory(
  ${PROJECT_SOURCE_DIR}/
  SRCS
)

include_directories(
  ${PROJECT_SOURCE_DIR}
)

include_directories(
  ${URTC_MEDIA_PATH}
  ${RAPIDJSON}
)

link_directories(
  ${URTC_MEDIA_LIB}
)

set (ALL_LDFLAGS
  ${ENGINEDEMO_LDFLAGS}
)

link_libraries(
    "liburtcmediaengine.so"
)

add_executable(enginedemo ${SRCS})
target_link_libraries(enginedemo dl pthread stdc++)
