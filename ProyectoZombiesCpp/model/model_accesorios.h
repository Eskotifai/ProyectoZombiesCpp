//*------------------Gestion de Accesorios------------------
//Todo: Modificar ACCESORIOS

#include <iostream>
#include <string>
#include "../utilities/utility_validaciones.h"
#include "model_structs.h"
using namespace std;

#ifndef MODEL_ACCESORIOS_H
#define MODEL_ACCESORIOS_H

Accesorio* Crear_Accesorio(string tipo, string nombre, int usos)
{
    Accesorio* nuevo_accesorio = new Accesorio;
    nuevo_accesorio -> id_accesorio = reinterpret_cast<uintptr_t>(nuevo_accesorio); //*Almacena la direccion de memoria como un entero sin signo, siendo ese entero de tipo size_t
    nuevo_accesorio -> tipo_accesorio = tipo;
    nuevo_accesorio -> nombre_accesorio = nombre;
    nuevo_accesorio -> usos = usos;
    nuevo_accesorio -> siguiente_accesorio = nullptr;

    return nuevo_accesorio;
}

//crear la lista

void agregar_accesorio(Accesorio *&lista_de_accesorios, Accesorio* nuevo_accesorio)
{
    if (lista_de_accesorios == nullptr)
    {
        lista_de_accesorios = nuevo_accesorio;
    }
    
    else
    {
        Accesorio* actual = lista_de_accesorios;

        while (actual -> siguiente_accesorio != nullptr)
        {
            actual = actual -> siguiente_accesorio;
        }
        actual -> siguiente_accesorio = nuevo_accesorio;
        
    }
    
}

void mostrar_accesorios(Accesorio* lista_de_accesorios)
{
    
    if (lista_de_accesorios != nullptr)
    {
        while (lista_de_accesorios != nullptr)
        {
            cout << "---------------------------------------------------" << endl;
            cout << "Tipo: " << lista_de_accesorios -> tipo_accesorio << endl;
            cout << "Nombre: " << lista_de_accesorios -> nombre_accesorio << endl;
            cout << "Usos: " << lista_de_accesorios -> usos << endl;
            cout << "ID Accesorio: " << lista_de_accesorios -> id_accesorio << endl;
            // cout << "Direccion de la lista: " << &lista_de_accesorios << " Direccion del nodo: "<< lista_de_accesorios << endl;
            cout << "---------------------------------------------------" << endl;
            lista_de_accesorios = lista_de_accesorios -> siguiente_accesorio;
        }
    }
    else
    {
        // cout << &lista_de_accesorios << endl;
        cout << "Lista vacia" << endl;
    }
    
    
}

void eliminar_todos_los_accesorios(Accesorio*& lista_de_accesorios)
{
    while (lista_de_accesorios != nullptr)
    {
        Accesorio* puntero_temporal = lista_de_accesorios;
        lista_de_accesorios = lista_de_accesorios -> siguiente_accesorio;
        delete puntero_temporal;
    }
    lista_de_accesorios = nullptr;
}

void eliminar_accesorio(Accesorio*& lista_de_accesorios, Accesorio* actual, Accesorio* anterior)
{
    if (actual == nullptr) //!Por si acaso
    {
        cout << "Accesorio no encontrado" << endl;
        return;
    }
    if (anterior == nullptr)
    {
        lista_de_accesorios = actual -> siguiente_accesorio;
    }
    else
    {
        anterior -> siguiente_accesorio = actual -> siguiente_accesorio;
    }
    delete actual;
    
    cout << "Accesorio eliminado" << endl;
    system("PAUSE");
}



Accesorio* buscar_accesorio_por_id(Accesorio*& lista, size_t id, Accesorio*& anterior)
{
    Accesorio* actual = lista;
    anterior = nullptr;

    while (actual != nullptr && actual -> id_accesorio != id)
    {
        anterior = actual;
        actual = actual -> siguiente_accesorio;
    }
    return actual;
    
}

void buscar_y_eliminar_accesorio(Accesorio*& lista_de_accesorios, size_t id)
{
    Accesorio* anterior = nullptr;
    Accesorio* actual = buscar_accesorio_por_id(lista_de_accesorios, id, anterior);

    if (actual != nullptr)
    {
        eliminar_accesorio(lista_de_accesorios, actual, anterior);
    }
    else
    {
        cout << "Accesorio no encontrado" << endl;
        return;
    }
    
}

void editar_accesorio(bool gestion, Accesorio*& lista_de_accesorios, size_t id)
{
    int opcion;
    gestion = true;
    Accesorio* anterior = nullptr;
    Accesorio* actual = buscar_accesorio_por_id(lista_de_accesorios, id, anterior);
    string Tipos_Accesorios_Predefinidos[] = {"Ataque ", "Defensa ", "Supervivencia "};
    int cantidad_tipos_accesorios = sizeof(Tipos_Accesorios_Predefinidos) / sizeof(Tipos_Accesorios_Predefinidos[0]); //Obteniendo la longitud de la lista, de alguna forma se obtiene la cantidad de elementos del array



    if (actual != nullptr)
    {
        do
        {
            system("cls");
            cout << "--------------Modificar Accesorio--------------" << endl << endl;
            cout << "1) Modificar tipo" << endl;
            cout << "2) Modificar nombre" << endl;
            cout << "3) Modificar usos" << endl;
            cout << "0) Volver" << endl << endl;
            cout << "--------------------------------------------" << endl;
            opcion = validar_numero("Introduce la opcion: ");

            switch (opcion)
            {
            case 1:
            
                while (gestion) 
                { 
                    cout << endl << "---------------------------" << endl;
                    for (int i = 0; i < cantidad_tipos_accesorios; i++) //*Imprime los zombies del array predefinido
                    {
                        cout << i+1 << ") "<< Tipos_Accesorios_Predefinidos[i] << endl;
                    }
                    cout << endl << "---------------------------" << endl;
            
                    opcion = validar_numero("Cambia el tipo de Accesorio: "); //*validar que la opcion este dentro del numero de tipos de accesorios
                    
                    if (opcion <= cantidad_tipos_accesorios && opcion > 0)
                    {                   
                        for (int i = 0; i < cantidad_tipos_accesorios; i++) //*Guarda el tipo de accesorio segun su posicion en el array
                        {
                            if (opcion - 1 == i)
                            {
                                actual -> tipo_accesorio = Tipos_Accesorios_Predefinidos[i];
                                break;
                            }
                        }
                        gestion = false;
                        cout << "Tipo de accesorio cambiado" << endl;
                    }
                    else
                    {
                        cout << "**Introduce un accesorio valido**" << endl;
                    }
                }
                gestion = true;

                
                system("PAUSE");
                break;

            case 2:

                actual -> nombre_accesorio = validar_entrada_vacia("Cambia el nombre: "); //!El nombre se debe cambiar para todos los accesorios de la lista, aunque no parezca tan intuitivo
                cout << "Nombre del accesorio cambiado" << endl;
                system("PAUSE");
                break;

            case 3:

                actual -> usos = validar_numero("Cambia los usos: ");
                cout << "Usos del accesorio cambiados" << endl;
                system("PAUSE");
                break;

            case 0:

                gestion = false;
            
            default:

                cout << "**Introduce una opcion correcta**" << endl;
                break;

            }
        } while (gestion);
        
    }
    else
    {
        cout << "El Accesorio no existe" << endl;
        system("PAUSE");
    }
    
}

#endif