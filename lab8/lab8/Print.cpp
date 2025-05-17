#include "Print.h"
#include "Event.h"

void Print::Input()
{
    cout << "Название: "; cin >> title;
    cout << "Автор: "; cin >> author;
}

void Print::Show()
{
    cout << "Название: " << title << ", Автор: " << author << endl;
}

void Print::HandleEvent(const TEvent& e)
{
    if (e.what == evMessage && e.command == cmGet)
    {
        cout << "Название: " << title << endl;
    }
}
