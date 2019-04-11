cmake_minimum_required(VERSION 3.4.1)

add_library(rkcodec
             SHARED
             ${CMAKE_SOURCE_DIR}/rkcodecjni.cpp)


add_library(aw_api SHARED
            IMPORTED)

set_target_properties(aw_api
                      PROPERTIES IMPORTED_LOCATION
                      ${CMAKE_SOURCE_DIR}/${ANDROID_ABI}/libaw_api.so
                      )

include_directories(${CMAKE_SOURCE_DIR}/include)

target_link_libraries( # Specifies the target library.
                       rkcodec
                       aw_api
                       # Links the log library to the target library.
                       ${log-lib})