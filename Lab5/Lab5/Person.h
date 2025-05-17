#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person();
    Person(string, int);
    Person(const Person&);
    virtual ~Person();

    string get_name() const;
    int get_age() const;
    void set_name(string);
    void set_age(int);

    virtual void Show() const = 0;
    Person& operator=(const Person&);
    friend istream& operator>>(istream&, Person&);
    friend ostream& operator<<(ostream&, const Person&);
};
