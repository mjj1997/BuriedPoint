#include "include/buried.h"
#include "gtest/gtest.h"

TEST(BuriedBasicTest, Test1)
{
    Buried_Create("G:/dev/cpp/BuriedPoint");
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
