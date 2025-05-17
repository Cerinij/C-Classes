#include <iostream>
#include <clocale>
#include "fraction.h"
using namespace std;

fraction make_fraction(double f, int s)
{
	fraction temp;
	if (!temp.Init(f, s))
	{
		cout << "Неверные параметры.";
		exit(1);
	}
	return temp;
}

int main()
{
	setlocale(LC_ALL, "ru");
	fraction A, B;
	A.Init(3.0, 2);
	B.Read();

	A.Show();
	B.Show();

	cout << "A.Power() = " << A.Power() << endl;
	cout << "B.Power() = " << B.Power() << endl;

	int j;
	cout << "Введите номер элемента j для вычисления: ";
	cin >> j;
	cout << "A.element(" << j << ") = " << A.element(j) << endl;

	fraction* X = new fraction;
	X->Init(2.0, 5);
	X->Show();
	cout << "X.Power() = " << X->Power() << endl;
	delete X;

	fraction mas[3];
	for (int i = 0; i < 3; i++)
	{
		mas[i].Read();
	}
	for (int i = 0; i < 3; i++)
	{
		mas[i].Show();
		cout << "mas[" << i << "].Power() = " << mas[i].Power() << endl;
	}

	fraction* p_mas = new fraction[3];
	for (int i = 0; i < 3; i++)
	{
		p_mas[i].Read();
	}
	for (int i = 0; i < 3; i++)
	{
		p_mas[i].Show();
		cout << "p_mas[" << i << "].Power() = " << p_mas[i].Power() << endl;
	}
	delete[] p_mas;
	
	double f;
	int s;
	cout << "Введите значение для make_fraction():" << endl << "first = ";
	cin >> f;
	cout << "second = ";
	cin >> s;
	fraction F = make_fraction(f, s);
	F.Show();

	return 0;
}