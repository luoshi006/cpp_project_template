cmake_minimum_required(VERSION 3.10)

set(TESTS_SRCS
    test_true.cpp
    test_false.cpp
)

include(GoogleTest)

# https://blog.csdn.net/10km/article/details/50508184
add_custom_target(tests_build)
string(REPLACE ".cpp" "" tests "${TESTS_SRCS}")
foreach(test_name ${tests})
    add_executable(${test_name} EXCLUDE_FROM_ALL ${test_name}.cpp)
    target_link_libraries(${test_name} PRIVATE gtest_main)
    add_dependencies(tests_build ${test_name})

    # automatic discovery of unit tests
    gtest_discover_tests(${test_name}
                            PROPERTIES
                                LABELS "unit"
                            DISCOVERY_TIMEOUT  # how long to wait (in seconds) before crashing
                                240)
endforeach()

