#include <gtest/gtest.h>

TEST(test_true, test_true1)
{
    EXPECT_TRUE(true);
}

TEST(test_true, test_true2)
{
    EXPECT_TRUE(!false);
}
