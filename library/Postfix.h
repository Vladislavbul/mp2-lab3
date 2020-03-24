#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Stack.h"

using namespace std;

class Postfix
{
private:
	//queue<string> infix;
	//queue<string> postfix;

	string infix; // строка, хранящая выражение в инфексной форме
	string postfix; // строка, хранящая выражение в постфиксной форме

	Stack<char> stackOp; // для преобразования в постфикс и проверки на корректность
	Stack<double> stackValue; // для хранения соответствующих значений
	Stack<double> stackValuePostfix; // для высчитывания результата

public:
	Postfix(string inf);
	string GetInfix(); // доступ к инфексной форме
	string GetPostfix(); // доступ к постфикной форме
	void ToPostfix(); // получение постфикса
	double Calculate(); // вычисление
	bool IsCorrect(); // проверка на корректность выражения
};