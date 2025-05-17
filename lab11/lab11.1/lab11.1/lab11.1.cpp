#include <iostream>
#include <list>
#include <clocale>
using namespace std;

void printList(const list<double>& lst)
{
    for (double x : lst)
    {
        cout << x << " ";
    }
    cout << endl;
}

void addAverage(list<double>& lst)
{
    if (lst.empty()) return;
    double sum = 0.0;
    int count = 0;
    for (double x : lst)
    {
        sum += x;
        count++;
    }
    double avg = sum / count;
    lst.push_back(avg);
    cout << "Добавление среднего арифметического: " << avg << endl;
}


void removeInRange(list<double>& lst, double low, double high)
{
    for (auto it = lst.begin(); it != lst.end(); )
    {
        if (*it >= low && *it <= high)
            it = lst.erase(it);
        else
            ++it;
    }
    cout << "Удаление элементов в диапазоне [" << low << ", " << high << "]" << endl;
}


void addMinMaxSum(list<double>& lst)
{
    if (lst.empty()) return;

    double min_val = *lst.begin();
    double max_val = *lst.begin();
    for (double x : lst)
    {
        if (x < min_val) min_val = x;
        if (x > max_val) max_val = x;
    }

    double total = min_val + max_val;
    for (double& x : lst) x += total;

    cout << "После добавления суммы максимального и минимального: " << total << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    list<double> data;
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите " << n << " элементов:" << endl;
    for (int i = 0; i < n; ++i)
    {
        double val;
        cin >> val;
        data.push_back(val);
    }

    cout << endl << "Начальный список:" << endl ;
    printList(data);

    addAverage(data);
    printList(data);

    double from, to;
    cout << endl << "Введите диапазон для удаления: ";
    cin >> from >> to;
    removeInRange(data, from, to);
    printList(data);

    addMinMaxSum(data);
    printList(data);

    return 0;
}
