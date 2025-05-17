#include <iostream>
#include <set>
#include <clocale>
using namespace std;

void print_multiset(const multiset<double>& ms)
{
    cout << "Множество: ";
    for (multiset<double>::const_iterator it = ms.begin(); it != ms.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void add_average(multiset<double>& ms)
{
    if (ms.empty()) return;

    double sum = 0;
    int count = 0;
    for (multiset<double>::iterator it = ms.begin(); it != ms.end(); ++it)
    {
        sum += *it;
        ++count;
    }

    double avg = sum / count;
    ms.insert(avg);

    cout << "Добавлено среднее арифметическое: " << avg << endl;
}

void remove_range(multiset<double>& ms, double low, double high)
{
    for (multiset<double>::iterator it = ms.begin(); it != ms.end(); )
    {
        if (*it >= low && *it <= high)
            it = ms.erase(it);
        else
            ++it;
    }

    cout << "Удалены элементы из диапазона [" << low << ", " << high << "]" << endl;
}

void add_min_max_sum(multiset<double>& ms)
{
    if (ms.empty()) return;

    double min_val = *ms.begin();
    double max_val = *ms.rbegin();
    double total = min_val + max_val;

    multiset<double> result;
    for (multiset<double>::iterator it = ms.begin(); it != ms.end(); ++it)
        result.insert(*it + total);

    ms = result;
    cout << "К каждому элементу добавлено: " << total << " (min + max)" << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    multiset<double> ms;
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите " << n << " чисел:" << endl;
    for (int i = 0; i < n; ++i)
    {
        double x;
        cin >> x;
        ms.insert(x);
    }

    cout << endl << "Исходное множество:" << endl;
    print_multiset(ms);

    add_average(ms);
    print_multiset(ms);

    double from, to;
    cout << endl << "Введите диапазон для удаления (от и до): ";
    cin >> from >> to;
    remove_range(ms, from, to);
    print_multiset(ms);

    add_min_max_sum(ms);
    print_multiset(ms);

    return 0;
}
