#include <iostream>
#include <list>
#include <clocale>
#include "Pair.h"
using namespace std;

void printList(const list<Pair>& lst)
{
    for (const Pair& p : lst)
        cout << p << " ";
    cout << endl;
}

void addAverage(list<Pair>& lst)
{
    if (lst.empty()) return;

    Pair sum;
    int count = 0;
    for (const Pair& p : lst)
    {
        sum = sum + p;
        count++;
    }

    Pair avg = sum / count;
    lst.push_back(avg);

    cout << "Добавлено среднее арифметическое: " << avg << endl;
}

void removeInRange(list<Pair>& lst, const Pair& low, const Pair& high)
{
    for (auto it = lst.begin(); it != lst.end(); )
    {
        if (*it >= low && *it <= high)
            it = lst.erase(it);
        else
            ++it;
    }

    cout << "Удалены элементы в диапазоне от " << low << " до " << high << endl;
}

void addMinMaxSum(list<Pair>& lst)
{
    if (lst.empty()) return;

    auto it = lst.begin();
    Pair min_p = *it;
    Pair max_p = *it;

    for (; it != lst.end(); ++it)
    {
        if (*it <= min_p) min_p = *it;
        if (*it >= max_p) max_p = *it;
    }

    Pair sum = min_p + max_p;

    for (Pair& p : lst)
        p = p + sum;

    cout << "К каждому элементу добавлена сумма min + max: " << sum << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    list<Pair> lst;
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        Pair p;
        cin >> p;
        lst.push_back(p);
    }

    cout << endl << "Исходный список:" << endl;
    printList(lst);

    addAverage(lst);
    printList(lst);

    Pair low, high;
    cout << endl << "Введите границы диапазона для удаления:" << endl;
    cin >> low >> high;
    removeInRange(lst, low, high);
    printList(lst);

    addMinMaxSum(lst);
    printList(lst);

    return 0;
}
