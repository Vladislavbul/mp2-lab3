#include "gtest.h"
#include "Postfix.h"

TEST(Postfix, constructor)
{
	ASSERT_NO_THROW(Postfix s("1+1"));
}

TEST(Postfix, IsCorrect_1)
{
	Postfix s("()");
	EXPECT_EQ(s.IsCorrect(), true);
}

TEST(Postfix, IsCorrect_2)
{
	Postfix s("(()");
	EXPECT_EQ(s.IsCorrect(), false);
}

TEST(Postfix, IsCorrect_3)
{
	Postfix s("5++5");
	EXPECT_EQ(s.IsCorrect(), false);
}

TEST(Postfix, GetPostfix)
{
	Postfix s("5+5-6");
	ASSERT_NO_THROW(s.GetPostfix());
}

TEST(Postfix, can_calculate)
{
	string tmp = "1+2*3";
	Postfix parse(tmp);
	parse.ToPostfix();
	EXPECT_EQ("1 2 3 * +", parse.GetPostfix());
	double result = parse.Calculate();
	EXPECT_EQ(7, result);
}