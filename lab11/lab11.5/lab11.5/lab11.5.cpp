#include <iostream>
#include <clocale>
#include "Container.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    Container<double> c;
    c.input(n);

    cout << endl << "Исходная очередь:" << endl;
    c.print();

    c.add_average();
    c.print();

    double from, to;
    cout << endl << "Введите диапазон для удаления: ";
    cin >> from >> to;
    c.remove_range(from, to);
    c.print();

    c.add_min_max_sum();
    c.print();

    return 0;
}
