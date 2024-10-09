#include <filesystem>

#include "src/database/database.h"
#include "gtest/gtest.h"

TEST(DbTest, BasicTest)
{
    std::filesystem::path db_path{ "hello_world.db" };
    if (std::filesystem::exists(db_path)) {
        std::filesystem::remove(db_path);
    }

    // create database
    buried::BuriedDb db{ db_path.string() };

    // test InsertData()
    {
        buried::BuriedDb::Data data{ -1, 1, 2, std::vector<char>{ 'h', 'e', 'l', 'l', 'o' } };
        db.InsertData(data);
    }
    auto datas = db.QueryData(10);
    EXPECT_EQ(datas.size(), 1);

    {
        buried::BuriedDb::Data data{ -1, 2, 3, std::vector<char>{ 'h', 'e', 'l', 'l', 'o' } };
        db.InsertData(data);
    }
    datas = db.QueryData(10);
    EXPECT_EQ(datas.size(), 2);

    {
        buried::BuriedDb::Data data{ -1, 3, 4, std::vector<char>{ 'h', 'e', 'l', 'l', 'o' } };
        db.InsertData(data);
    }
    datas = db.QueryData(10);
    EXPECT_EQ(datas.size(), 3);

    {
        buried::BuriedDb::Data data{ -1, 4, 5, std::vector<char>{ 'h', 'e', 'l', 'l', 'o' } };
        db.InsertData(data);
    }
    datas = db.QueryData(10);
    EXPECT_EQ(datas.size(), 4);

    // double-check priority to ensure InsertData() work well
    EXPECT_EQ(datas[0].priority, 4);
    EXPECT_EQ(datas[1].priority, 3);
    EXPECT_EQ(datas[2].priority, 2);
    EXPECT_EQ(datas[3].priority, 1);

    // test DeleteData()
    db.DeleteData(datas[0]);
    datas = db.QueryData(10);
    EXPECT_EQ(datas.size(), 3);

    // test QueryData() to check whether it returns 10 limited data
    for (int i = 0; i < 100; ++i) {
        buried::BuriedDb::Data data{ -1, i, i, std::vector<char>{ 'h', 'e', 'l', 'l', 'o' } };
        db.InsertData(data);
    }
    datas = db.QueryData(10);
    EXPECT_EQ(datas.size(), 10);

    // remove db_path
    std::filesystem::remove(db_path);
}
