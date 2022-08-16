#include <gtest/gtest.h>

TEST(test_false, test_false1) {
  EXPECT_FALSE(false);
}

TEST(test_false, test_false2) {
  EXPECT_FALSE(!true);
}
