#include "Dialog.h"
#include <clocale>
#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Доступные команды:" << endl << "mn - создать группу на n элементов" << endl;
    cout << "+ - добавить элемент в группу" << endl << "- - Удалить последний элемент из группы" << endl;
    cout << "s - Отобразить все элементы группы" << endl << "z - Отобразить названия всех книг группы" << endl << "q - Завершить программу" << endl;
    Dialog d;
    d.Execute();
    return 0;
}
