#pragma once
#include "Vector.h"
#include "Event.h"

class Dialog : public Vector
{
protected:
    int EndState;
public:
    Dialog() : Vector(), EndState(0) {}
    virtual ~Dialog() {}
    virtual void GetEvent(TEvent& event);
    virtual void HandleEvent(TEvent& event);
    virtual int Execute();
    virtual void ClearEvent(TEvent& event);
    virtual int Valid() { return EndState != 0; }
    virtual void EndExec() { EndState = 1; }
};
