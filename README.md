# cpp project template

# Usage
```sh
# build
    $ cmake -S . -B build
    $ cmake --build build
    $ -------------------------
    $ mkdir build -p && cd build && cmake ..
    $ make

# debug cmake
    $ cmake -S . -B build --trace-source=CMakeLists.txt
    $ cmake --build build --verbose # CMake 3.14+ only

# test
    $ cmake -S . -B build -DBUILD_TESTS=ON
    $ cmake --build build --target tests_build
    $ cmake --build build --target test
    $ -------------------------
    $ cmake -DBUILD_TESTS=ON ..
    $ make tests_build && make test

# coverage
    $ cmake -S . -B build -DBUILD_TESTS=ON -DBUILD_COVERAGE=ON
    $ cmake --build build --target ccov-all
    $ -------------------------
    $ cmake -DBUILD_TESTS=ON -DBUILD_COVERAGE=ON ..
    $ make ccov-all

# AddressSanitizer
    $ cmake .. -DBUILD_ASAN=ON
    $ make use_after_free && ./src/examples/use_after_free
    # Note:
    #    - ASAN, MSAN, TSAN, UBSAN
    #    - TSAN could not work with ASAN, because of "ASAN_OPTIONS"
    #    - MSAN
    #       - should working with Clang
    #       - you must rebuild libcxx with '-fsanitize=memory',
    #       - refs: https://github.com/google/sanitizers/wiki/MemorySanitizerLibcxxHowTo

# Clang
    $ cmake -G "Unix Makefiles" -UCMAKE_C_COMPILER -DCMAKE_C_COMPILER=clang -UCMAKE_CXX_COMPILER -DCMAKE_CXX_COMPILER=clang++ ..

# Ninja
    $ cmake -G "Ninja" -UCMAKE_C_COMPILER -DCMAKE_C_COMPILER=clang -UCMAKE_CXX_COMPILER -DCMAKE_CXX_COMPILER=clang++ ..

# fix code format
    $ ./tools/scripts/fix_code_style.sh
```

# Library
```sh
├── thirdparty
│   ├── catch @v2.13.9
│   ├── googletest-release-1.12.1
│   └── quill @v2.1.0
```

