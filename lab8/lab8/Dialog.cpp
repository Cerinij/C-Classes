#include "Dialog.h"
#include <iostream>
#include <string>
using namespace std;

void Dialog::GetEvent(TEvent& event)
{
    string s;
    char code;
    cout << "¬ведите команду: ";
    cin >> s;
    code = s[0];
    string param = s.substr(1);
    event.what = evMessage;
    event.command = 0;
    switch (code)
    {
    case 'm': event.command = cmMake; event.a = stoi(param); break;
    case '+': event.command = cmAdd; break;
    case '-': event.command = cmDel; break;
    case 's': event.command = cmShow; break;
    case 'z': event.command = cmGet; break;
    case 'q': event.command = cmQuit; break;
    default: event.what = evNothing; break;
    }
}

void Dialog::HandleEvent(TEvent& event)
{
    if (event.what == evMessage)
    {
        switch (event.command)
        {
        case cmMake:
            size = event.a;
            beg = new Object * [size];
            cur = 0;
            ClearEvent(event);
            break;
        case cmAdd:
            Add();
            ClearEvent(event);
            break;
        case cmDel:
            Del();
            ClearEvent(event);
            break;
        case cmShow:
            Show();
            ClearEvent(event);
            break;
        case cmGet:
            Vector::HandleEvent(event);
            ClearEvent(event);
            break;
        case cmQuit:
            EndExec();
            ClearEvent(event);
            break;
        default:
            Vector::HandleEvent(event);
        }
    }
}

void Dialog::ClearEvent(TEvent& event)
{
    event.what = evNothing;
}

int Dialog::Execute()
{
    TEvent event;
    do {
        EndState = 0;
        GetEvent(event);
        HandleEvent(event);
    } while (!Valid());
    return EndState;
}
