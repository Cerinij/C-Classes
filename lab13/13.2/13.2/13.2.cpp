#include <iostream>
#include <clocale>
#include "Pair.h"
#include "PriorityAdapter.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    PriorityAdapter<Pair> pqa;
    pqa.input(n);

    cout << endl << "Исходная очередь:" << endl;
    pqa.print();

    pqa.add_average();
    pqa.print();

    Pair low, high;
    cout << endl << "Введите диапазон для удаления:" << endl;
    cin >> low >> high;
    pqa.remove_range(low, high);
    pqa.print();

    pqa.add_min_max_sum();
    pqa.print();

    return 0;
}
