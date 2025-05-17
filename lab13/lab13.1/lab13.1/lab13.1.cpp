#include <iostream>
#include <list>
#include <algorithm>
#include "Pair.h"
using namespace std;

void add_average(list<Pair>& lst)
{
    Pair sum;
    for_each(lst.begin(), lst.end(), [&](const Pair& p) { sum += p; });
    Pair avg = sum / lst.size();
    lst.push_back(avg);
    cout << "Добавлено среднее: " << avg << endl;
}

void remove_range(list<Pair>& lst, const Pair& low, const Pair& high)
{
    lst.remove_if([&](const Pair& p)
        {
        return p >= low && p <= high;
        });
    cout << "Удалены элементы в диапазоне [" << low << ", " << high << "]" << endl;
}

void add_min_max_sum(list<Pair>& lst)
{
    if (lst.empty()) return;

    auto result = minmax_element(lst.begin(), lst.end());
    auto min_it = result.first;
    auto max_it = result.second;
    Pair total = *min_it + *max_it;

    for (auto& p : lst)
        p += total;

    cout << "К каждому элементу прибавлено: " << total << " (min + max)" << endl;
}


void print_list(const list<Pair>& lst)
{
    for_each(lst.begin(), lst.end(), [](const Pair& p) { cout << p << " "; });
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите количество пар: ";
    cin >> n;

    list<Pair> lst;
    for (int i = 0; i < n; ++i)
    {
        Pair p;
        cin >> p;
        lst.push_back(p);
    }

    cout << endl << "Исходный список:" << endl;
    print_list(lst);

    add_average(lst);
    print_list(lst);

    Pair low, high;
    cout << endl << "Введите границы диапазона для удаления:" << endl;
    cin >> low >> high;
    remove_range(lst, low, high);
    print_list(lst);

    add_min_max_sum(lst);
    print_list(lst);

    return 0;
}
