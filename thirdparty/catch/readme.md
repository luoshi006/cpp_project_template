> refs: https://github.com/catchorg/Catch2/blob/v2.x/docs/tutorial.md

## Quick start

Download single header file

```shell
curl https://raw.githubusercontent.com/catchorg/Catch2/v2.x/single_include/catch2/catch.hpp -O
```

## Notes
- **Catch2** is too slowly when Linking.
- **Doctest** is not beautiful.

## Usage

test_main.cpp

```cpp
#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_FAST_COMPILE
#include "catch.hpp"
```

test_true.cpp

```cpp
#include "catch.hpp"

TEST_CASE("test true")
{
  REQUIRE(true == (1>0));
}
```