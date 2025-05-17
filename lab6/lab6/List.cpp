#include "List.h"

List::List() : head(nullptr), size(0) {}

List::List(const List& other) : head(nullptr), size(0)
{
    Node* current = other.head;
    while (current)
    {
        push_back(current->value);
        current = current->next;
    }
}

List::~List()
{
    while (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

List& List::operator=(const List& other)
{
    if (this == &other) return *this;
    this->~List();
    head = nullptr;
    size = 0;
    Node* current = other.head;
    while (current)
    {
        push_back(current->value);
        current = current->next;
    }
    return *this;
}

void List::push_back(int val)
{
    Node** p = &head;
    while (*p) p = &((*p)->next);
    *p = new Node(val);
    ++size;
}

int& List::operator[](int index)
{
    if (index < 0 || index >= size) throw out_of_range("Неверный индекс.");
    Node* p = head;
    while (index--) p = p->next;
    return p->value;
}

int List::operator()() const
{
    return size;
}

List List::operator*(const List& other) const
{
    List result;
    Node* a = head;
    Node* b = other.head;
    while (a && b)
    {
        result.push_back(a->value * b->value);
        a = a->next;
        b = b->next;
    }
    return result;
}

istream& operator>>(istream& in, List& l)
{
    int count;
    cout << "Введите количество элементов: ";
    in >> count;
    for (int i = 0; i < count; ++i)
    {
        int val;
        cout << "Элемент " << i + 1 << ": ";
        in >> val;
        l.push_back(val);
    }
    return in;
}

ostream& operator<<(ostream& out, const List& l)
{
    Node* p = l.head;
    while (p)
    {
        out << p->value << " ";
        p = p->next;
    }
    return out;
}

Iterator List::begin() const { return Iterator(head); }
Iterator List::end() const { return Iterator(nullptr); }
