#pragma once
#include <iostream>
using namespace std;

template <class T>
class List
{
    T* data;
    int size;

public:
    List(int s = 0, T val = T())
    {
        size = s;
        data = new T[size];
        for (int i = 0; i < size; ++i)
            data[i] = val;
    }

    List(const List& other)
    {
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    ~List() {
        delete[] data;
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

    void push_back(T val) {
        T* newData = new T[size + 1];
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];
        newData[size] = val;
        delete[] data;
        data = newData;
        size++;
    }

    void remove_range(T low, T high)
    {
        int new_size = 0;
        T* temp = new T[size];
        for (int i = 0; i < size; ++i)
        {
            if (!(data[i] >= low && data[i] <= high))
            {
                temp[new_size++] = data[i];
            }
        }
        delete[] data;
        size = new_size;
        data = new T[size];
        for (int i = 0; i < size; ++i)
            data[i] = temp[i];
        delete[] temp;
    }

    void add_to_each(T val)
    {
        for (int i = 0; i < size; ++i)
            data[i] += val;
    }

    T sum() const
    {
        T result = T();
        for (int i = 0; i < size; ++i)
            result += data[i];
        return result;
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
