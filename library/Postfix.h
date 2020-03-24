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

	string infix; // ������, �������� ��������� � ��������� �����
	string postfix; // ������, �������� ��������� � ����������� �����

	Stack<char> stackOp; // ��� �������������� � �������� � �������� �� ������������
	Stack<double> stackValue; // ��� �������� ��������������� ��������
	Stack<double> stackValuePostfix; // ��� ������������ ����������

public:
	Postfix(string inf);
	string GetInfix(); // ������ � ��������� �����
	string GetPostfix(); // ������ � ���������� �����
	void ToPostfix(); // ��������� ���������
	double Calculate(); // ����������
	bool IsCorrect(); // �������� �� ������������ ���������
};