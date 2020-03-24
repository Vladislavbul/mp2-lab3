#pragma once
#include <iostream>

using namespace std;

const int MaxStackSize = 100;

template <class ValType>
class Stack
{
private:
	ValType* pStack; // указатель на стэк
	int size; // размер
	int top; // вершина стека
public:
	Stack(int s = 10);// конструктор
	Stack(const Stack& st); // конструктор копирования
	~Stack(); // деструктор
	
	void Push(ValType e); // добовление элемента в стек
	ValType Pop(); // получение верхнего элемента с удалением из стека
	ValType Top(); // доступ к верхнему элементу стека
	void Deltop(); // удалить последний элемент

	bool IsEmpty()const; // проверка на пустоту стека
	bool IsFull()const; // проверка на заполненность стека

	void Clear(); // очистить
	int Length();
};

//-------------------------------------------------------------------

template <class ValType>
Stack<ValType>::Stack(int s) // конструктор
{
	if ((s < 1) || (s > MaxStackSize)) // проверка
	{
		throw "error: data is not correct";
	}
	size = s; // инициализировать размер стека
	pStack = new ValType[size]; // выделить память
	top = -1; // значение -1 говорит о том, что стек пуст
}

template <class ValType> // конструктор копирования
Stack<ValType>::Stack(const Stack<ValType>& st)
{
	size = st.size;
	top = st.top;
	pStack = new ValType[size]; // выделить память под новый стек
	for (int i = 0; i < top; i++)
	{
		pStack[i] = st.pStack[i];
	}
}

template <class ValType>
Stack<ValType>::~Stack() // деструктор
{
	delete[] pStack;
}

template <class ValType>
bool Stack <ValType>::IsEmpty() const // stack пуст
{
	return (top == -1);
}

template <class ValType>
bool Stack <ValType>::IsFull() const // stack полон
{
	return (top == size - 1);
}

template <class ValType>
void Stack<ValType>::Push(ValType e) // добовление элемента в стек
{
	if (IsFull())
	{
		throw "error: stack is full";
	}
	top++;
	pStack[top] = e; // помещаем элемент в стек
}

template <class ValType>
ValType Stack<ValType>::Pop() // получение верхнего элемента с удалением из стека
{
	if (IsEmpty())
	{
		throw "error: stack is empty";
	}
	return pStack[top--];
}

template <class ValType>
ValType Stack<ValType>::Top() // получение верхнего элемента без удаления 
{
	if (IsEmpty())
	{
		throw "error: stack is empty";
	}
	return pStack[top];
}

template <class ValType>
void Stack<ValType>::Deltop() // удалить последний элемент
{
	if (IsEmpty())
	{
		throw "error: stack is empty";
	}
	top--;
}

template <class ValType>
int Stack<ValType>::Length() //элементов в стэке в момент времени t.
{
	return top + 1;
}

template <class ValType>
void Stack<ValType>::Clear() // очистить
{
	top = -1;
}