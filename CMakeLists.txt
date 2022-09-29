cmake_minimum_required(VERSION 3.5)

project(helloworld
        VERSION 0.0.1
        LANGUAGES CXX)
set(TARGET_NAME ${PROJECT_NAME})

set(PROJ_SOURCE_DIR ${PROJECT_SOURCE_DIR})
set(PROJ_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(common)

# Options.
    # send option definitions to cmake cache
    option(BUILD_ARMHL "arm-hl plantform" OFF)
    option(BUILD_CLANG "using llvm clang" OFF)
    #Build tests by default. We want run tests whether we are developing or building a release. I mean... why wouldn't you? :)
    option(BUILD_TESTS "Build all tests." ON)
    option(BUILD_COVERAGE "Build coverage." ON)

    option(BUILD_ASAN  "Build with ASAN" OFF)
    option(BUILD_MSAN  "Build with LSAN" OFF)
    option(BUILD_TSAN  "Build with TSAN" OFF)
    option(BUILD_UBSAN "Build with UBSAN" OFF)

# choose toolchain
    if (BUILD_ARMHL)
        include(${CMAKE_MODULE_PATH}/toolchains/linux_armhl.toolchain.cmake)
        set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Build type" FORCE)
        SET(TARGET_NAME ${TARGET_NAME}_armhl)
        message(STATUS "Plantform: arm-hl")
    endif()

    if (BUILD_CLANG)
        include(${CMAKE_MODULE_PATH}/toolchains/linux_clang.toolchain.cmake)
        message(STATUS "Compiler: clang")
    endif()

# code coverage
    # Can't build for coverage without the test.
    if (${BUILD_COVERAGE})
        SET(BUILD_TESTS "ON" CACHE BOOL "" FORCE)
        # Code coverage results with an optimized (non-Debug) build may be misleading
        SET(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE )

        include(code-coverage)
        add_code_coverage_all_targets(EXCLUDE
                                        /usr/*
                                        /opt/*
                                        ${PROJECT_SOURCE_DIR}/thirdparty/* )
        message(STATUS "BUILD COVERAGE")
    endif()

# Sanitizel
    if (BUILD_ASAN)
        include(SanitizeAddress)
    endif()
    if (BUILD_MSAN)
        include(SanitizeMemory)
    endif()
    if (BUILD_TSAN)
        include(SanitizeThreads)
    endif()
    if (BUILD_UBSAN)
        include(SanitizeUndefinedBehaviour)
    endif()

message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

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
add_subdirectory(src/modules/logger)
add_subdirectory(src/examples)
# add_dependencies(${TARGET_NAME} git_version_tgt)

# google test
if (${BUILD_TESTS})
    enable_testing()
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
    add_subdirectory(thirdparty/googletest-release-1.12.1)
    add_subdirectory(tests)
endif()
