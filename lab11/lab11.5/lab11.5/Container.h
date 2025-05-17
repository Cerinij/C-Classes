#pragma once
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

template <class T>
class Container
{
private:
    priority_queue<T> data;

public:
    void input(int n)
    {
        T value;
        for (int i = 0; i < n; ++i)
        {
            cout << "Введите элемент " << i + 1 << ": ";
            cin >> value;
            data.push(value);
        }
    }

    void print() const
    {
        priority_queue<T> temp = data;
        cout << "Элементы очереди: ";
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    void add_average()
    {
        vector<T> v = to_vector();
        if (v.empty()) return;

        T sum = 0;
        for (T x : v) sum += x;
        T avg = sum / v.size();

        v.push_back(avg);
        update(v);

        cout << "Добавлено среднее арифметическое: " << avg << endl;
    }

    void remove_range(T low, T high)
    {
        vector<T> v = to_vector();
        vector<T> result;
        for (T x : v)
            if (!(x >= low && x <= high))
                result.push_back(x);

        update(result);

        cout << "Удалены элементы из диапазона [" << low << ", " << high << "]" << endl;
    }

    void add_min_max_sum()
    {
        vector<T> v = to_vector();
        if (v.empty()) return;

        T min = v[0], max = v[0];
        for (T x : v)
        {
            if (x < min) min = x;
            if (x > max) max = x;
        }

        T sum = min + max;
        for (T& x : v) x += sum;

        update(v);

        cout << "К каждому элементу добавлена сумма наименьшего и наибольшего: " << endl;
    }

private:
    vector<T> to_vector() const
    {
        vector<T> v;
        priority_queue<T> temp = data;
        while (!temp.empty())
        {
            v.push_back(temp.top());
            temp.pop();
        }
        return v;
    }

    void update(const vector<T>& v)
    {
        data = priority_queue<T>(v.begin(), v.end());
    }
};
