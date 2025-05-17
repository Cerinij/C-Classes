#include <iostream>
#include <queue>
#include <vector>
#include <clocale>
using namespace std;

void print_queue(priority_queue<double> q)
{
    cout << "Очередь: ";
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

vector<double> to_vector(priority_queue<double> q)
{
    vector<double> v;
    while (!q.empty())
    {
        v.push_back(q.top());
        q.pop();
    }
    return v;
}

priority_queue<double> to_queue(const vector<double>& v)
{
    return priority_queue<double>(v.begin(), v.end());
}

void add_average(priority_queue<double>& q)
{
    vector<double> v = to_vector(q);
    double sum = 0;
    for (double x : v) sum += x;
    double avg = sum / v.size();
    v.push_back(avg);
    cout << "Добавлено среднее: " << avg << endl;
    q = to_queue(v);
}

void remove_range(priority_queue<double>& q, double low, double high)
{
    vector<double> v = to_vector(q);
    vector<double> filtered;
    for (double x : v)
    {
        if (!(x >= low && x <= high))
            filtered.push_back(x);
    }
    cout << "Удалены элементы в диапазоне [" << low << ", " << high << "]" << endl;
    q = to_queue(filtered);
}

void add_min_max(priority_queue<double>& q)
{
    vector<double> v = to_vector(q);
    if (v.empty()) return;

    double max_val = v[0];
    double min_val = v[0];
    for (double x : v)
    {
        if (x < min_val) min_val = x;
        if (x > max_val) max_val = x;
    }

    double total = min_val + max_val;
    for (double& x : v)
        x += total;

    cout << "К каждому элементу добавлено: " << total << " (min + max)" << endl;
    q = to_queue(v);
}

int main()
{
    setlocale(LC_ALL, "ru");
    priority_queue<double> q;
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите " << n << " чисел:" << endl;
    for (int i = 0; i < n; ++i) 
   {
        double x;
        cin >> x;
        q.push(x);
    }

    cout << endl << "Исходная очередь:" << endl;
    print_queue(q);

    add_average(q);
    print_queue(q);

    double from, to;
    cout << endl << "Введите диапазон удаления (от и до): ";
    cin >> from >> to;
    remove_range(q, from, to);
    print_queue(q);

    add_min_max(q);
    print_queue(q);

    return 0;
}
