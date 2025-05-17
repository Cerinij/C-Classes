#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;

class Print : public Object
{
protected:
    string title;
    string author;
public:
    Print() : title(""), author("") {}
    Print(string t, string a) : title(t), author(a) {}
    Print(const Print& p) : title(p.title), author(p.author) {}
    virtual ~Print() {}
    void Input() override;
    void Show() override;
    void HandleEvent(const TEvent& e) override;
    string GetTitle() const { return title; }
};
