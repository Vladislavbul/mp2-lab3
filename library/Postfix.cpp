#include "Postfix.h"
#include "Stack.h"

using namespace std;


bool IsForbiddenSymbols(char x) // запрещенные символы
{
	if (x == '^' || x == '!' || x == '@' || x == '#' || x == '$' || x == '%' || x == '&' || x == '[' || x == ']' || x == '{' || x == '}' || x == '=' || x == '_') { return true; }
	else { return false; }
}


bool IsOperation(char x) // операции
{
	if (x == '(' || x == ')' || x == '+' || x == '-' || x == '*' || x == '/' || x == '^') { return true; }
	else { return false; }
}

bool IsCompute(char x) // вычисления
{
	if (x == '+' || x == '-' || x == '*' || x == '/') { return true; }
	else { return false; }
}

bool IsNumber(char x) // цифры
{
	for (char i = '0'; i <= '9'; i++)
	{
		if (x == i)
		{
			return true;
		}
	}
	return false;
}

int Priority(char x) // приоритет
{
	if (!IsOperation(x)) { throw "error: data is not correct"; }

	if (x == '(') { return 0; }
	else if (x == ')') { return 1; }
	else if (x == '+' || x == '-') { return 2; }
	else { return 3; }
}

double Total(double op1, double op2, char operation) // выражения
{
	if (operation == '+') { return op1 + op2; }
	else if (operation == '-') { return op1 - op2; }
	else if (operation == '*') { return op1 * op2; }
	else if (operation == '/') { return op1 / op2; }
	else { return 0; }
}

//------------------------------------------------------------------------------------

Postfix::Postfix(string inf)
{
	infix = inf;
	postfix = "";
}

string Postfix::GetInfix() // доступ к инфексной форме
{
	return infix;
}

string Postfix::GetPostfix() // доступ к постфикной форме
{
	return postfix;
}

bool Postfix::IsCorrect() //проверка на корректность выражения
{
	int x = 0;

	for (int i = 0; i < infix.size(); i++)
	{
		if (IsForbiddenSymbols(infix[i])) // запрещенные символы
		{
			return false;
		}

		if (IsCompute(infix[0]) || IsCompute(infix[infix.size() - 1])) // выражение не начинается и не заканчивается операцией
		{
			return false;
		}

		if (IsCompute(infix[i]) && IsCompute(infix[i + 1])) // в выражении нет двух операций подряд
		{
			return false;
		}

		// проверка корректность скобок
		if (infix[i] == '(')
		{
			x++;
		}

		if (infix[i] == ')')
		{
			x--;
		}
	}
	if (x != 0)
	{
		return false;
	}

	return true;
}

void Postfix::ToPostfix() // получение постфикса
{
	int x = 0;
	stackOp.Clear();

	for (int i = 0; i < infix.size(); i++)
	{
		if (!IsOperation(infix[i]))
		{
			postfix += infix[i];

			if (i == infix.size() - 1 || IsOperation(infix[i + 1]))
			{
				postfix += ' ';
			}
		}
		else
		{
			if (infix[i] != ')')
			{
				if (Priority(infix[i]) == 0 || stackOp.IsEmpty() || Priority(infix[i]) > Priority(stackOp.Top()))
				{
					stackOp.Push(infix[i]);
				}
				else
				{
					x = stackOp.Length();
					for (int j = 0; j < x; j++)
					{
						if (Priority(stackOp.Top()) >= Priority(infix[i]))
						{
							postfix += stackOp.Pop();
							postfix += ' ';
						}
						else
						{
							break;
						}
					}
					stackOp.Push(infix[i]);
				}
			}
			else
			{
				x = stackOp.Length();
				for (int j = 0; j < x; j++)
				{
					if (stackOp.Top() != '(')
					{
						postfix += stackOp.Pop();
						postfix += ' ';
					}
					else
					{
						stackOp.Deltop();
						break;
					}
				}
			}
		}
	}
	x = stackOp.Length();
	for (int j = 0; j < x; j++)
	{
		postfix += stackOp.Pop();
		if (j != x - 1)
			postfix += ' ';
	}
}

double Postfix::Calculate() // вычисление
{
	stackValuePostfix.Clear();
	double tmp = 0;
	string ss;

	for (int i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] != ' ')
		{
			if (!IsOperation(postfix[i]) && !IsNumber(postfix[i]) && postfix[i] != '.')
			{
				if (i != postfix.size() - 1 && postfix[i + 1] != ' ')
					continue;
				stackValuePostfix.Push(stackValue.Pop());
			}
			else if (IsNumber(postfix[i]) || postfix[i] == '.')
			{
				ss += postfix[i];
				if (i != postfix.size() - 1 && IsNumber(postfix[i + 1]))
					continue;
				if (postfix[i + 1] == '.')
					continue;
				tmp = stod(ss);
				stackValuePostfix.Push(tmp);
				ss.clear();
			}
			else
			{
				tmp = Total(stackValuePostfix.Pop(), stackValuePostfix.Pop(), postfix[i]);
				stackValuePostfix.Push(tmp);
			}
		}
		else continue;
	}
	return stackValuePostfix.Pop();
}