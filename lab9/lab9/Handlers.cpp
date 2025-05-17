#include <iostream>
#include <exception>
#include <cstdlib>
using namespace std;

void F()
{
    cout << "Вызвана пользовательская функция завершения (terminate/unexpected)" << endl;
    exit(1);
}
