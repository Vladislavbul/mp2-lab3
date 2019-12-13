#include "gtest.h"
#include "Stack.h"

TEST(Stack, can_create_stack_plus)
{
	ASSERT_NO_THROW (Stack <int> s(5));
}

TEST(Stack, can_create_stack_min)
{
	ASSERT_ANY_THROW(Stack <int> s(-5));
}

TEST(Stack, can_push)
{
	Stack <int> s(3);
	ASSERT_NO_THROW(s.Push(2));
}

TEST(Stack, can_pop)
{
	Stack <int> s(3);
	for (int i = 0; i < 3; i++)
	{
		s.Push(i);
	}
	ASSERT_NO_THROW(s.Pop());
}

TEST(Stack, stack_empty)
{
	Stack <int> s(3);
	EXPECT_EQ(1, s.IsEmpty());
}

TEST(Stack, stack_full)
{
	Stack <int> s(3);
	for (int i = 0; i < 3; i++)
	{
		s.Push(i);
	}
	EXPECT_EQ(1, s.IsFull());
}