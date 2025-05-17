#pragma once
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
class PriorityAdapter
{
private:
    priority_queue<T> pq;

public:
    void push(const T& val)
    {
        pq.push(val);
    }

    void input(int n)
    {
        T val;
        for (int i = 0; i < n; ++i)
        {
            cout << "Элемент " << i + 1 << ": ";
            cin >> val;
            pq.push(val);
        }
    }

    void print() const
    {
        priority_queue<T> temp = pq;
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

        T sum;
        for (const T& x : v)
            sum = sum + x;

        T avg = sum / v.size();
        v.push_back(avg);
        rebuild(v);

        cout << "Добавлено среднее: " << avg << endl;
    }

    void remove_range(const T& low, const T& high)
    {
        vector<T> v = to_vector();
        vector<T> filtered;
        for (const T& x : v)
            if (!(x >= low && x <= high))
                filtered.push_back(x);

        rebuild(filtered);
        cout << "Удалены элементы из диапазона [" << low << ", " << high << "]" << endl;
    }

    void add_min_max_sum()
    {
        vector<T> v = to_vector();
        if (v.empty()) return;

        auto result = minmax_element(v.begin(), v.end());
        auto min_it = result.first;
        auto max_it = result.second;
        T total = *min_it + *max_it;

        for (T& x : v)
            x += total;

        rebuild(v);
        cout << "К каждому элементу прибавлено: " << total << " (min + max)" << endl;
    }

private:
    vector<T> to_vector() const
    {
        vector<T> v;
        priority_queue<T> temp = pq;
        while (!temp.empty())
        {
            v.push_back(temp.top());
            temp.pop();
        }
        return v;
    }

    void rebuild(const vector<T>& v)
    {
        pq = priority_queue<T>(v.begin(), v.end());
    }
};
