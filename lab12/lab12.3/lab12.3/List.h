#pragma once
#include <iostream>
using namespace std;

template <class T>
class List
{
    T* data;
    int size;

public:
    List(int s = 0, const T& val = T())
    {
        size = s;
        data = new T[size];
        for (int i = 0; i < size; ++i)
            data[i] = val;
    }

    ~List()
    {
        delete[] data;
    }

    List(const List& other)
    {
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    List& operator=(const List& other)
    {
        if (this == &other) return *this;
        delete[] data;
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
        return *this;
    }

    T& operator[](int i) { return data[i]; }
    int operator()() const { return size; }

    void push_back(const T& val)
    {
        T* temp = new T[size + 1];
        for (int i = 0; i < size; ++i)
            temp[i] = data[i];
        temp[size] = val;
        delete[] data;
        data = temp;
        ++size;
    }

    void remove_range(const T& low, const T& high)
    {
        int count = 0;
        for (int i = 0; i < size; ++i)
            if (!(data[i] >= low && data[i] <= high))
                data[count++] = data[i];
        size = count;
    }

    T sum() const
    {
        T total;
        for (int i = 0; i < size; ++i)
            total = total + data[i];
        return total;
    }

    T min() const
    {
        T m = data[0];
        for (int i = 1; i < size; ++i)
            if (data[i] < m) m = data[i];
        return m;
    }

    T max() const
    {
        T m = data[0];
        for (int i = 1; i < size; ++i)
            if (data[i] > m) m = data[i];
        return m;
    }

    void add_to_each(const T& val)
    {
        for (int i = 0; i < size; ++i)
            data[i] = data[i] + val;
    }

    friend ostream& operator<<(ostream& out, const List<T>& l)
    {
        for (int i = 0; i < l.size; ++i)
            out << l.data[i] << " ";
        return out;
    }

    friend istream& operator>>(istream& in, List<T>& l)
    {
        for (int i = 0; i < l.size; ++i)
            in >> l.data[i];
        return in;
    }
};
