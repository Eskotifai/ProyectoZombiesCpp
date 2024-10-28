#include <iostream>
#include <string>

using namespace std;


void mostrar_mensaje(bool mostrar, string mensaje)
{
    if (mostrar)
    {
        cout << mensaje << endl;
        mostrar = false;
    }
}    