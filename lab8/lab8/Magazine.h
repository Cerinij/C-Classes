#pragma once
#include "Print.h"

class Magazine : public Print
{
protected:
    int pages;
public:
    Magazine() : Print(), pages(0) {}
    Magazine(string t, string a, int p) : Print(t, a), pages(p) {}
    Magazine(const Magazine& m) : Print(m), pages(m.pages) {}
    ~Magazine() override {}
    void Input() override;
    void Show() override;
    void HandleEvent(const TEvent& e) override;
};
