#pragma once
#include "Person.h"

class Student : public Person
{
protected:
    string subject;
    int mark;

public:
    Student();
    Student(string, int, string, int);
    Student(const Student&);
    ~Student();

    void Show() const override;
    void CheckMark() const;

    string get_subject() const;
    int get_mark() const;

    void set_subject(string);
    void set_mark(int);

    Student& operator=(const Student&);
    friend istream& operator>>(istream&, Student&);
    friend ostream& operator<<(ostream&, const Student&);
};
