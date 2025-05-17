#include <iostream>
#include <set>
#include "Pair.h"
#include <clocale>
using namespace std;

typedef multiset<Pair> PairSet;
typedef PairSet::iterator It;

void print(const PairSet& ms)
{
    for (It it = ms.begin(); it != ms.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void add_average(PairSet& ms)
{
    if (ms.empty()) return;
    Pair sum;
    int count = 0;
    for (It it = ms.begin(); it != ms.end(); ++it)
    {
        sum = sum + *it;
        ++count;
    }
    Pair avg = sum / count;
    ms.insert(avg);
    cout << "Добавлено среднее арифметическое: " << avg << endl;
}

void remove_range(PairSet& ms, const Pair& low, const Pair& high)
{
    for (It it = ms.begin(); it != ms.end(); )
    {
        if (*it >= low && *it <= high)
            it = ms.erase(it);
        else
            ++it;
    }
    cout << "Удалены элементы в диапазоне [" << low << ", " << high << "]" << endl;
}

void add_min_max_sum(PairSet& ms)
{
    if (ms.empty()) return;
    Pair min = *ms.begin();
    Pair max = *ms.rbegin();
    Pair total = min + max;

    PairSet result;
    for (It it = ms.begin(); it != ms.end(); ++it)
        result.insert(*it + total);

    ms = result;
    cout << "К каждому элементу добавлена сумма min + max: " << total << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    PairSet ms;
    int n;
    cout << "Введите количество пар: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        Pair p;
        cin >> p;
        ms.insert(p);
    }

    cout << endl << "Исходное множество:" << endl;
    print(ms);

    add_average(ms);
    print(ms);

    Pair low, high;
    cout << endl << "Введите границы диапазона для удаления:" << endl;
    cin >> low >> high;
    remove_range(ms, low, high);
    print(ms);

    add_min_max_sum(ms);
    print(ms);

    return 0;
}
