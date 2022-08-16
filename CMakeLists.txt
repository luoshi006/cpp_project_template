cmake_minimum_required(VERSION 3.5)

project(helloworld
        VERSION 0.0.1
        LANGUAGES CXX)
set(TARGET_NAME ${PROJECT_NAME})

# send option definitions to cmake cache
option(ARMHL "arm-hl plantform" OFF)

# choose toolchain
if (ARMHL)
    include(${PROJECT_SOURCE_DIR}/cmake/toolchains/linux_armhl.toolchain.cmake)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Build type" FORCE)
    SET(TARGET_NAME ${TARGET_NAME}_armhl)
    message(STATUS "Plantform: arm-hl")
endif()

include(${PROJECT_SOURCE_DIR}/cmake/common.cmake)

# get git version
add_custom_target( git_version_tgt
                    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_SOURCE_DIR}/cmake/version/git_version.cmake
                    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/git_version.h ${CMAKE_CURRENT_BINARY_DIR}
                    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_CURRENT_SOURCE_DIR}/git_version.h
                    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/cmake/version/git_version.cmake
                            ${CMAKE_CURRENT_SOURCE_DIR}/cmake/version/git_version.h.in)



message(STATUS "target: ${TARGET_NAME}")
message(STATUS "build type: ${CMAKE_BUILD_TYPE}")

# add_subdirectory(thirdparty/catch)
# add_subdirectory(test)

add_executable(${TARGET_NAME} src/examples/hello_version.cpp )
add_dependencies(${TARGET_NAME} git_version_tgt)
target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
