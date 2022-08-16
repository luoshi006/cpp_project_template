# cpp project template

# usage
```sh
# build
    $ cmake -S . -B build
    $ cmake --build build

# debug cmake
    $ cmake -S . -B build --trace-source=CMakeLists.txt
    $ cmake --build build --verbose # CMake 3.14+ only

# test
    $ cmake -S . -B build -DEN_TEST=ON
    $ cmake --build build --target tests_build
    $ cmake --build build --target test
```

## TODO
- tests
  - ctest
- coverage