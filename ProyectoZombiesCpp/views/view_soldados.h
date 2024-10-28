#include <iostream>
#include "../utilities/utility_validaciones.h"
using namespace std;

string nombre; 
// Soldado* Lista_Soldados = nullptr;
Soldado* anterior = nullptr;  // Mover inicialización aquí
Soldado* actual = nullptr; 

void menu_soldados(bool gestion, int opcion,Soldado *&Lista_Soldados)
{
    // bool gestion = true;
    // int opcion;
    string nombre_soldado, nuevoNombre;
    int vida;
    size_t verificar_id_soldado;

    
    

    do
    {
    system("Pause");
    system("cls");
    cout << "---------Aqui se gestionan los soldados---------" << endl << endl; //*SUBMENU DE SOLDADOS
    cout << "1) Agregar soldado" << endl;
    cout << "2) Eliminar soldado" << endl;
    cout << "3) Modificar soldado" << endl;
    cout << "4) Ver soldado" << endl;
    cout << "0) **Salir al menu principal**" << endl << endl;
    cout << "------------------------------------------------" << endl;
        // string nombre;
        opcion = validar_numero("Introduce la opcion: ");

        switch (opcion)
        {
        case 1:
                cout<<endl;
                nombre_soldado=validar_entrada_vacia("Ingrese el nombre del soldado: ");
                cout << "SOLDADO " << nombre_soldado << " AGREGADO :D" << endl;
                cout<<endl;
                vida=validar_numero("Ingrese la vida del soldado: ");
                cout << "VIDA AGREGADA" << endl;
                insertarPrincipio(Lista_Soldados, CrearNodo(nombre_soldado, vida));
                cout<<endl;
                cout<<"SOLDADO CREADO CON EXITO UWU"<<endl;
                
            break;

        case 2:
            do
            {
                system("Pause");
                system("cls");
                cout << "-----------ELIMINAR SOLDADOS-----------" << endl << endl;
                cout << "1) Eliminar todos los soldados" << endl;
                cout << "2) Eliminar un soldado de los agregados" << endl; 
                cout << "0) Volver" << endl; 
                cout << endl << "--------------------------------------" << endl;
                    opcion = validar_numero("Introduce la opcion: ");
                    switch (opcion)
                    {
                    case 1:
                        cout << "*Se eliminaron todos los soldados agregados*" << endl;
                        liberaSoldados(Lista_Soldados);
                    break;

                case 2:

                    if (Lista_Soldados != nullptr)
                    {   
                        MostrarSoldado(Lista_Soldados);
                        verificar_id_soldado = validar_numero("Introduce el ID del soldado a eliminar: ");//!corregir todo pq es con id y no con nombre
                        buscarYEliminarSoldado(Lista_Soldados, verificar_id_soldado);
                    }
                    else
                    {
                        cout << "Lista vacia" << endl;
                    }
                    
                    break;

                case 0:
                
                    gestion = false;
                    break;
                
                default:

                    cout << "*Introduce una opcion correcta*" << endl; 
                    break;
                }
            } while (gestion);
            gestion = true;
            
            break;
            //eliminar soldado()

        case 3:
                verificar_id_soldado = validar_numero("Introduce el ID del soldado a modificar: ");
                actual = buscarSoldadoPorID(Lista_Soldados, verificar_id_soldado, anterior);
                if (actual != nullptr) {
                    modificarSoldado(actual, opcion);
                } else {
                    cout << "Soldado no encontrado" << endl;
                }
            break;
            //modificar_soldado()

        case 4:
            cout << "-----------SOLDADOS CREADOS-----------" << endl;
            MostrarSoldado(Lista_Soldados);
            cout << "-------------------------------------" << endl;
            break;
            //ver_soldados()

        case 0:

            gestion = false;
        
        default:

            cout << "**Introduce una opcion correcta**" << endl;                    
            break;

            }
    } while (gestion);
}

//Todo: Hacer y llamar a la funcion segun el case