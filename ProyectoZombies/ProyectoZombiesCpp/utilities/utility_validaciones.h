#include <iostream>
#include <string>
#include <limits>
using namespace std;

#ifndef UTILITY_VALIDACIONES_H
#define UTILITY_VALIDACIONES_H

//*-----------Validaciones para entradas validas--------------

string validar_entrada_vacia(string texto) //Todo: La funcion sirve pero tiene un error de impresion, es probable que se este llamando mal a la funcion
{
    string entrada;
    
    while (true)
    {
        cout << texto;
        getline(cin, entrada);

        if (entrada.empty())
        {
            cout << "**No se aceptan entradas vacias**" << endl;
        }
        else
        {
            break;
        }
        
    }
    return entrada;
}

int validar_numero(string texto)
{
    int opc;

    while (true)
    {   
        cout << texto;
        cin >> opc;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); //*Ignora la mayor cantidad posible de caracteres de la entrada para limpiar el buffer de entrada.
            cout << "**No se aceptan letras**" << endl;
        }
        //*mejorar en un futuro para no permitir entradas vacias, pero al parecer, introducir una entrada vacia al pedir enteros no rompe el programa        
        else
        {
            break;
        }
        
    }
    return opc;
    
}

#endif
