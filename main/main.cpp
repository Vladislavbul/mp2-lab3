#include <iostream>
#include <string>
#include "Postfix.h"
#include "Stack.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");

	int x = 0;
	string expression;

m:	cout << "Введите выражение: ";

	cin >> expression;
	Postfix postfix(expression);

	if (!postfix.IsCorrect())
	{
	cout << "Выражение не корректно, повторите." << endl;
	goto m;
	}
	
	postfix.ToPostfix();

	cout << "Результат вычисления: " << postfix.Calculate() << endl;
	cout << "Постфиксная форма: " << postfix.GetPostfix() << endl;
	cout << "Выберите дальнейшнее действие:" << endl;
	cout << "1. Ввести другое арифметическое выражение" << endl;
	cout << "2. Выйти из программы" << endl;
	cin >> x;

	switch (x)
	{
	case 1: goto m;
	case 2: break;
	}
		
	return 0;
}