# cpp project template

# Usage
```sh
# build
    $ cmake -S . -B build
    $ cmake --build build

# debug cmake
    $ cmake -S . -B build --trace-source=CMakeLists.txt
    $ cmake --build build --verbose # CMake 3.14+ only

# test
    $ cmake -S . -B build -DBUILD_TESTS=ON
    $ cmake --build build --target tests_build
    $ cmake --build build --target test

# coverage
    $ cmake -S . -B build -DBUILD_TESTS=ON -DBUILD_COVERAGE=ON
    $ cmake --build build --target ccov-all
```

# Library
```sh
├── thirdparty
│   ├── catch @v2.13.9
│   ├── googletest-release-1.12.1
│   └── quill @v2.1.0
```

# TODO
- tests
  - ctest
