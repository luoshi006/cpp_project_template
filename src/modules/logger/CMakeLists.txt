
add_subdirectory(${PROJ_SOURCE_DIR}/thirdparty/quill ${PROJ_BINARY_DIR}/thirdparty/quill)

add_library(lib_log log.cpp)

# CMP0076
target_sources(lib_log
                PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/log.h
                PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/log.cpp)
target_include_directories(lib_log PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lib_log PUBLIC quill::quill)
target_compile_features(lib_log PUBLIC cxx_std_17)