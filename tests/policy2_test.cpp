#include <gtest/gtest.h>
#include <iostream>
#include "../src/caches/include/policy.hpp"

TEST(PolicyTest, Negative)
{
    Policy p(-1);
    EXPECT_EQ(p.GetVersion(), -1);
}

TEST(PolicyTest, Positive)
{
    Policy p(1);
    EXPECT_EQ(p.GetVersion(), 2);
}

TEST(PolicyTest, Zero)
{
    Policy p(0);
    EXPECT_EQ(p.GetVersion(), 0);
}

TEST(PolicyTest, Default)
{
    Policy p;
    EXPECT_EQ(p.GetVersion(), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}