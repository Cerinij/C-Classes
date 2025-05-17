#pragma once
#include <iostream>
using namespace std;

template <class T>
class List
{
    T* data;
    int size;

public:
    List(int size, T val);
    List(const List& other);
    ~List();

    List& operator=(const List& other);
    T& operator[](int index);
    int operator()() const;
    List operator*(const List& other) const;

    template <class U>
    friend ostream& operator<<(ostream& out, const List<U>& a);
    template <class U>
    friend istream& operator>>(istream& in, List<U>& a);
};

template <class T>
List<T>::List(int s, T val)
{
    size = s;
    data = new T[size];
    for (int i = 0; i < size; ++i)
        data[i] = val;
}

template <class T>
List<T>::List(const List& other)
{
    size = other.size;
    data = new T[size];
    for (int i = 0; i < size; ++i)
        data[i] = other.data[i];
}

template <class T>
List<T>::~List()
{
    delete[] data;
}

template <class T>
List<T>& List<T>::operator=(const List& other)
{
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    data = new T[size];
    for (int i = 0; i < size; ++i)
        data[i] = other.data[i];
    return *this;
}

template <class T>
T& List<T>::operator[](int index)
{
    if (index >= 0 && index < size)
        return data[index];
    throw out_of_range("Неверный индекс");
}

template <class T>
int List<T>::operator()() const
{
    return size;
}

template <class T>
List<T> List<T>::operator*(const List<T>& other) const
{
    int minSize = (size < other.size) ? size : other.size;
    List<T> result(minSize, T());
    for (int i = 0; i < minSize; ++i)
        result.data[i] = data[i] * other.data[i];
    return result;
}

template <class U>
ostream& operator<<(ostream& out, const List<U>& a)
{
    for (int i = 0; i < a.size; ++i)
        out << a.data[i] << " ";
    return out;
}

template <class U>
istream& operator>>(istream& in, List<U>& a)
{
    for (int i = 0; i < a.size; ++i)
        in >> a.data[i];
    return in;
}
