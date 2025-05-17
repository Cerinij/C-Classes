#include "Student.h"
#include "Vector.h"
#include <iostream>
#include <clocale>
#include <windows.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Vector group(3);
    Student s1, s2;

    cout << "Введите данные первого студента:" << endl;
    cin >> s1;

    cout << endl << "Введите данные второго студента:" << endl;
    cin >> s2;

    group.Add(&s1);
    group.Add(&s2);

    cout << endl << "Список студентов:" << endl;
    cout << group;

    cout << endl << "Проверка оценки:" << endl;
    cout << s1.get_name() << ": ";
    s1.CheckMark();
    cout << endl << s2.get_name() << ": ";
    s2.CheckMark();

    return 0;
}
