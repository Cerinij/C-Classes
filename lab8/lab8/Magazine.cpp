#include "Magazine.h"
#include <iostream>
using namespace std;

void Magazine::Input()
{
    Print::Input();
    cout << "���������� �������: "; cin >> pages;
}

void Magazine::Show()
{
    Print::Show();
    cout << "���������� �������: " << pages << endl;
}

void Magazine::HandleEvent(const TEvent& e)
{
    Print::HandleEvent(e);
}
