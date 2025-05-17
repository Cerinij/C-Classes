#pragma once

struct Node
{
    int value;
    Node* next;
    Node(int val, Node* nxt = nullptr) : value(val), next(nxt) {}
};
