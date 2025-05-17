#include "Magazine.h"
#include <iostream>
using namespace std;

void Magazine::Input()
{
    Print::Input();
    cout << "Количество страниц: "; cin >> pages;
}

void Magazine::Show()
{
    Print::Show();
    cout << "Количество страниц: " << pages << endl;
}

void Magazine::HandleEvent(const TEvent& e)
{
    Print::HandleEvent(e);
}
