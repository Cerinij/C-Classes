#include "List.h"
#include "Pair.h"
#include <clocale>
#include <windows.h>

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Pair p;
    cout << "Введите пару (целое и вещественное число):\n";
    cin >> p;

    List<Pair> A(3, p);
    cout << endl << "Введите список A из 3 пар:" << endl;
    cin >> A;

    cout << endl << "Список A:" << endl << A << endl;

    List<Pair> B(3, Pair(3, 1.8));
    cout << endl << "Список B по умолчанию:" << endl << B << endl;

    List<Pair> C = A * B;
    cout << endl << "Результат поэлементного умножения A * B:" << endl << C << endl;

    cout << endl << "Размер списка A: " << A() << endl;
    cout << "Элемент A[1]: " << A[1] << endl;

    return 0;
}
