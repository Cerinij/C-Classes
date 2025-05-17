#include "List.h"
#include "Error.h"
#include <stdexcept>

List::List(int s)
{
    if (s > MAX_SIZE) throw runtime_error("Размер превышает MAX_SIZE");
    size = s;
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = 0;
}

List::List(const List& other)
{
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = other.data[i];
}

List::~List()
{
    delete[] data;
}

List& List::operator=(const List& other)
{
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++) data[i] = other.data[i];
    return *this;
}

int List::operator[](int i)
{
    if (i < 0 || i >= size) throw IndexError();
    return data[i];
}

int List::operator()()
{
    return size;
}

List List::operator*(const List& other)
{
    if (size != other.size) throw SizeMismatch();
    List result(size);
    for (int i = 0; i < size; i++)
        result.data[i] = data[i] * other.data[i];
    return result;
}

int List::operator+(int index)
{
    if (index < 0 || index >= size) throw RangeError();
    return data[index];
}

ostream& operator<<(ostream& out, const List& l)
{
    for (int i = 0; i < l.size; i++) out << l.data[i] << " ";
    return out << endl;
}

istream& operator>>(istream& in, List& l)
{
    for (int i = 0; i < l.size; i++)
    {
        cout << "[" << i << "]: ";
        in >> l.data[i];
    }
    return in;
}
