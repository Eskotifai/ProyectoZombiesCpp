#include <iostream>
using namespace std;

//!FALTA ESTA VAINA PROFE

void menu_estaciones(bool gestion, int opcion)
{
    system("cls");
    cout << "---------Aqui se gestionan las estaciones---------" << endl << endl; //*SUBMENU DE ESTACIONES
    cout << "1) Agregar estacion" << endl;
    cout << "2) Eliminar estacion" << endl;
    cout << "3) Modificar estacion" << endl;
    cout << "4) Ver estaciones" << endl;
    cout << "0) **Salir al menu principal**" << endl << endl;
    cout << "--------------------------------------------------" << endl;

    do
    {
        opcion = validar_numero("Introduce la opcion: ");

        switch (opcion)
        {
        case 1:

            cout << "Aqui se AGREGAN ESTACIONES" << endl;
            //agregar_estacion()
            break;

        case 2:

            cout << "Aqui se ELIMINAN ESTACIONES" << endl;
            //eliminar_estacion()
            break;

        case 3:

            cout << "Aqui se MODIFICAN ESTACIONES" << endl;
            //modificar_estacion()
            break;

        case 4:

            cout << "Aqui se VEN ESTACIONES" << endl;
            //ver_estaciones()
            break;
        
        case 0:

            gestion = false;
        
        default:

            cout << "**Introduce una opcion correcta**" << endl;
            break;

        }
    } while (gestion);
}
//Todo: Hacer y llamar a la funcion segun el case