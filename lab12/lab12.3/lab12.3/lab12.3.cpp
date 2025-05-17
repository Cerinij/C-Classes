#include <iostream>
#include <clocale>
#include "Pair.h"
#include "List.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите количество пар: ";
    cin >> n;

    List<Pair> lst(n);
    cout << "Введите пары:" << endl;
    cin >> lst;

    cout << endl << "Исходный список:" << endl << lst << endl;

    Pair avg = lst.sum() / lst();
    lst.push_back(avg);
    cout << "Добавлено среднее арифметическое: " << avg << endl;
    cout << lst << endl;

    Pair low, high;
    cout << endl << "Введите границы диапазона удаления:" << endl;
    cin >> low >> high;
    lst.remove_range(low, high);
    cout << "После удаления:" << endl << lst << endl;

    Pair add = lst.min() + lst.max();
    lst.add_to_each(add);
    cout << "К каждому прибавлено: " << add << endl;
    cout << lst << endl;

    return 0;
}
