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

m:	cout << "������� ���������: ";

	cin >> expression;
	Postfix postfix(expression);

	if (!postfix.IsCorrect())
	{
	cout << "��������� �� ���������, ���������." << endl;
	goto m;
	}
	
	postfix.ToPostfix();

	cout << "��������� ����������: " << postfix.Calculate() << endl;
	cout << "����������� �����: " << postfix.GetPostfix() << endl;
	cout << "�������� ����������� ��������:" << endl;
	cout << "1. ������ ������ �������������� ���������" << endl;
	cout << "2. ����� �� ���������" << endl;
	cin >> x;

	switch (x)
	{
	case 1: goto m;
	case 2: break;
	}
		
	return 0;
}