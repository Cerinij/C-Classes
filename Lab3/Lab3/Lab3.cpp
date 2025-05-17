#include "Pair.h"
#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    Pair a, b, c;
    cout << "Введите пару a:" << endl;
    cin >> a;
    cout << "Введите пару b:" << endl;
    cin >> b;

    c = a - b;
    cout << "Результат вычитания a - b: " << endl << c << endl;

    c = a + 5;
    cout << "a + 5: " << endl << c << endl;

    c = a + 3.14;
    cout << "a + 3.14:" << endl << c << endl;

    return 0;
}
