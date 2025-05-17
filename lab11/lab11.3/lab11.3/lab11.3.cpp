#include <iostream>
#include "List.h"
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    List<double> lst(n);
    cout << "Введите " << n << " вещественных чисел:" << endl;
    cin >> lst;

    cout << endl << "Исходный список:" << endl << lst << endl;

    double avg = lst.sum() / lst();
    lst.push_back(avg);
    cout << "Среднее добавлено: " << avg << endl;
    cout << lst << endl;

    double low, high;
    cout << endl << "Введите границы диапазона для удаления:" << endl;
    cin >> low >> high;
    lst.remove_range(low, high);
    cout << lst << endl;

    double minmax = lst.min() + lst.max();
    lst.add_to_each(minmax);
    cout << "Добавлена сумма min + max: " << minmax << endl;
    cout << lst << endl;

    return 0;
}
