#include "Print.h"
#include "Event.h"

void Print::Input()
{
    cout << "��������: "; cin >> title;
    cout << "�����: "; cin >> author;
}

void Print::Show()
{
    cout << "��������: " << title << ", �����: " << author << endl;
}

void Print::HandleEvent(const TEvent& e)
{
    if (e.what == evMessage && e.command == cmGet)
    {
        cout << "��������: " << title << endl;
    }
}
