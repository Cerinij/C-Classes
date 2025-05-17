#include "Person.h"

Person::Person() : name(""), age(0) {}
Person::Person(string n, int a) : name(n), age(a) {}
Person::Person(const Person& p) : name(p.name), age(p.age) {}
Person::~Person() {}

string Person::get_name() const { return name; }
int Person::get_age() const { return age; }

void Person::set_name(string n) { name = n; }
void Person::set_age(int a) { age = a; }

Person& Person::operator=(const Person& p)
{
    if (this == &p) return *this;
    name = p.name;
    age = p.age;
    return *this;
}

istream& operator>>(istream& in, Person& p)
{
    cout << "Введите имя: ";
    in >> ws;
    getline(in, p.name);
    cout << "Введите возраст: ";
    in >> p.age;
    return in;
}

ostream& operator<<(ostream& out, const Person& p)
{
    out << "Имя: " << p.name << endl << "Возраст: " << p.age << endl;
    return out;
}
