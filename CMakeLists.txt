cmake_minimum_required(VERSION 3.5)

project(helloworld
        VERSION 0.0.1
        LANGUAGES CXX)
set(TARGET_NAME ${PROJECT_NAME})

set(PROJ_SOURCE_DIR ${PROJECT_SOURCE_DIR})
set(PROJ_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# send option definitions to cmake cache
option(ARMHL "arm-hl plantform" OFF)
option(EN_TEST "enable test" OFF)

# choose toolchain
if (ARMHL)
    include(${PROJECT_SOURCE_DIR}/cmake/toolchains/linux_armhl.toolchain.cmake)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Build type" FORCE)
    SET(TARGET_NAME ${TARGET_NAME}_armhl)
    message(STATUS "Plantform: arm-hl")
endif()

include(${PROJECT_SOURCE_DIR}/cmake/common.cmake)

# get git version
add_custom_target(  git_version_tgt ALL
                    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_SOURCE_DIR}/cmake/version/git_version.cmake
                    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/git_version.h ${CMAKE_CURRENT_BINARY_DIR}
                    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_CURRENT_SOURCE_DIR}/git_version.h
                    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/cmake/version/git_version.cmake
                            ${CMAKE_CURRENT_SOURCE_DIR}/cmake/version/git_version.h.in)


message(STATUS "target: ${TARGET_NAME}")
message(STATUS "build type: ${CMAKE_BUILD_TYPE}")

add_subdirectory(src/lib/version)
add_subdirectory(src/examples)
# add_dependencies(${TARGET_NAME} git_version_tgt)


# google test
if (${EN_TEST})
    enable_testing()
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
    add_subdirectory(thirdparty/googletest-release-1.12.1)
    add_subdirectory(tests)
endif()