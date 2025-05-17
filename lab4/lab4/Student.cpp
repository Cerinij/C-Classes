#include "Student.h"

Student::Student() : Person(), subject(""), mark(0) {}
Student::Student(string n, int a, string s, int m) : Person(n, a), subject(s), mark(m) {}
Student::Student(const Student& s) : Person(s), subject(s.subject), mark(s.mark) {}
Student::~Student() {}

string Student::get_subject() const { return subject; }
int Student::get_mark() const { return mark; }

void Student::set_subject(string s) { subject = s; }
void Student::set_mark(int m) { mark = m; }

void Student::check_mark() const
{
    if (mark < 3)
        cout << "������ ��������������������!" << endl;
    else
        cout << "������ ������������������ ��� ����." << endl;
}

Student& Student::operator=(const Student& s)
{
    if (this == &s) return *this;
    Person::operator=(s);
    subject = s.subject;
    mark = s.mark;
    return *this;
}

istream& operator>>(istream& in, Student& s)
{
    in >> (Person&)s;
    cout << "������� �������: ";
    in >> ws;
    getline(in, s.subject);
    cout << "������� ������: ";
    in >> s.mark;
    return in;
}

ostream& operator<<(ostream& out, const Student& s)
{
    out << (Person&)s;
    out << "�������: " << s.subject << endl << "������: " << s.mark << endl;
    return out;
}
