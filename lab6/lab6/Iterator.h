#pragma once
#include "Node.h"

class Iterator
{
    Node* node;
public:
    Iterator(Node* p = nullptr) : node(p) {}

    Iterator& operator++()
    {
        if (node) node = node->next;
        return *this;
    }

    Iterator operator+(int n)
    {
        Iterator temp = *this;
        while (n-- && temp.node) ++temp;
        return temp;
    }

    bool operator!=(const Iterator& it) const { return node != it.node; }
    int& operator*() const { return node->value; }

    friend class List;
};
