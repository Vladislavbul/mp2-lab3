#pragma once

class Stack 
{
	int lenght;
	int* m;
	int i;

public:

	bool isEmpty()
	{
		return (i == -1);
	}

	bool isFull()
	{
		return (i >= lenght);
	}

	Stack(int len)
	{
		i = -1;
		this->lenght = len;
		m = new int[len];
	}

	Stack(const Stack &st)
	{
		lenght = st.lenght;
		i = st.i;
		m = new int[lenght];
		for (int j = 0; j <= i; j++)
		{
			m[j] = st.m[j];
		}
	}

	~Stack()
	{
		delete[] m;
	}

	void push(int element)
	{
		if (isFull())
		{
			throw "error";
		}
		i++;
		m[i] = element;
	}

	int pop()
	{
		if (isEmpty)
		{
			throw "error";
		}
		int a = m[i];
		i--;
		return a;
	}
};