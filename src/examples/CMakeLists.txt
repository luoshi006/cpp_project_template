add_executable(hello_version ${CMAKE_CURRENT_SOURCE_DIR}/hello_version.cpp)
target_link_libraries(hello_version
                        PRIVATE
                            lib_version
                            lib_log)
target_compile_options(hello_version PRIVATE "-Wall")
set_target_properties(hello_version PROPERTIES
                        CXX_STANDARD            11
                        CXX_STANDARD_REQUIRED   YES
                        CXX_EXTENSIONS          NO
                        POSITION_INDEPENDENT_CODE ON)

# Use after free
add_executable(use_after_free ${CMAKE_CURRENT_SOURCE_DIR}/use_after_free.cpp)
# target_link_libraries(use_after_free
#                         PRIVATE
#                             lib_version
#                             lib_log)
target_compile_options(use_after_free PRIVATE "-Wall")
set_target_properties(use_after_free PROPERTIES
                        CXX_STANDARD            11
                        CXX_STANDARD_REQUIRED   YES
                        CXX_EXTENSIONS          NO
                        POSITION_INDEPENDENT_CODE ON)