#include <iostream>
#include <cmath>
#include "fraction.h"
using namespace std;

bool fraction::Init(double f, int s)
{
	if (s <= 0)
	{
		cout << "������: ��������� ������ ���� �������������" << endl;
		return false;
	}
	first = f;
	second = s;
	return true;
}

void fraction::Read()
{
	double f;
	int s;
	cout << endl << "������� ������ ������� ����������: ";
	cin >> f;
	cout << "������� ���������� ���������: ";
	cin >> s;

	if (!Init(f, s))
	{
		exit(1);
	}
}

void fraction::Show() const
{
	cout << endl << "first = " << first << ", second = " << second << endl;
}

double fraction::Power() const
{
	return pow(first, second);
}

double fraction::element(int j) const
{
	return first * pow(second, j);
}