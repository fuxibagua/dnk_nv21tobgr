cmake_minimum_required(VERSION 3.4.1)

add_library(pose
             SHARED
             ${CMAKE_SOURCE_DIR}/posejni.cpp)


add_library(poseEstimation SHARED
            IMPORTED)

set_target_properties(poseEstimation
                      PROPERTIES IMPORTED_LOCATION
                      ${CMAKE_SOURCE_DIR}/${ANDROID_ABI}/libPoseEstimation.so
                      )

include_directories(${CMAKE_SOURCE_DIR}/include)

find_library(
        log-lib
        log
)

target_link_libraries( # Specifies the target library.
                       pose
                       poseEstimation
                       # Links the log library to  the target library.
                       ${log-lib})