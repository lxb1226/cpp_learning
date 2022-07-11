#include <gmock/gmock.h>
#include <string>
using namespace std;
using namespace testing;

class AVector : public Test
{
public:
    vector<int> vec;
};

TEST_F(AVector, EmptyWhenInit)
{
    ASSERT_TRUE(vec.empty());
}

TEST_F(AVector, NotEmptyAfterPush)
{
    vec.push_back(0);
    ASSERT_FALSE(vec.empty());
}

class AVectorContainOneElement : public Test
{
public:
    void SetUp() override
    {
        vec.push_back(0);
    }

    vector<int> vec;
};

TEST_F(AVectorContainOneElement, NotEmpty)
{
    ASSERT_FALSE(vec.empty());
}

TEST_F(AVectorContainOneElement, EmptyAfterPop)
{
    vec.pop_back();

    ASSERT_TRUE(vec.empty());
}

TEST(AddTest, OnePlusOneEqTwo)
{
    ASSERT_THAT(1 + 1, Eq(2));
}

// Hamcrest 断言
TEST(StringTest, StringEq)
{
    string actual = string("al") + "pha";
    ASSERT_THAT(actual, Eq("alpha"));
}

TEST(StringTest, ALLOf)
{
    string actual = string("al") + "pha";
    ASSERT_THAT(actual, AllOf(StartsWith("al"), EndsWith("ha"), Ne("aloha")));
}
