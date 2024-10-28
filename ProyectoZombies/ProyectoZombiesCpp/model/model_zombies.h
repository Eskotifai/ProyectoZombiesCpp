//*------------------Gestion de Zombies------------------
#include <iostream>
#include <string>
#include "../utilities/utility_validaciones.h"
#include "model_structs.h"
using namespace std;

#ifndef MODEL_ZOMBIES_H
#define MODEL_ZOMBIES_H



Zombie* Crear_Zombie(string tipo, int fortaleza, int ataque)
{
    Zombie* nuevo_zombie = new Zombie;
    nuevo_zombie -> id_zombie = reinterpret_cast<uintptr_t>(nuevo_zombie); 
    nuevo_zombie -> tipo_zombie = tipo;
    nuevo_zombie -> fortaleza = fortaleza;
    nuevo_zombie -> ataque = ataque;
    nuevo_zombie -> siguiente_zombie = nullptr;

    return nuevo_zombie;
}

//crear la lista

void agregar_zombie(Zombie *&lista_de_zombies, Zombie* nuevo_zombie)
{
    if (lista_de_zombies == nullptr)
    {
        lista_de_zombies = nuevo_zombie;
    }
    
    else
    {
        Zombie* actual = lista_de_zombies;

        while (actual -> siguiente_zombie != nullptr)
        {
            actual = actual -> siguiente_zombie;
        }
        actual -> siguiente_zombie = nuevo_zombie;
        
    }
    
}

void mostrar_zombies(Zombie *lista_de_zombies)
{
    
    if (lista_de_zombies != nullptr)
    {
        while (lista_de_zombies != nullptr)
        {
            cout << "---------------------------------------------------" << endl;
            cout << "Tipo: " << lista_de_zombies -> tipo_zombie << endl;
            cout << "Fortaleza: " << lista_de_zombies -> fortaleza << endl;
            cout << "Ataque: " << lista_de_zombies -> ataque << endl;
            cout << "ID Zombie: " << lista_de_zombies -> id_zombie << endl;
            // cout << "Direccion de la lista: " << &lista_de_zombies << " Direccion del nodo: "<< lista_de_zombies << endl;
            cout << "---------------------------------------------------" << endl;
            lista_de_zombies = lista_de_zombies -> siguiente_zombie;
        }
    }
    else
    {
        // cout << &lista_de_zombies << endl;
        cout << "Lista vacia" << endl;
    }
    
    
}

void eliminar_todos_los_zombies(Zombie*& lista_de_zombies)
{
    while (lista_de_zombies != nullptr)
    {
        Zombie* puntero_temporal = lista_de_zombies;
        lista_de_zombies = lista_de_zombies -> siguiente_zombie;
        delete puntero_temporal;
    }
    lista_de_zombies = nullptr;
}

void eliminar_zombie(Zombie*& lista_de_zombies, Zombie* actual, Zombie* anterior)
{
    if (actual == nullptr) //!Por si acaso
    {
        cout << "Zombie no encontrado" << endl;
        return;
    }
    if (anterior == nullptr)
    {
        lista_de_zombies = actual -> siguiente_zombie;
    }
    else
    {
        anterior -> siguiente_zombie = actual -> siguiente_zombie;
    }
    delete actual;
    
    cout << "Zombie eliminado" << endl;
    system("PAUSE");
}



Zombie* buscar_zombie_por_id(Zombie*& lista, size_t id, Zombie*& anterior)
{
    Zombie* actual = lista;
    anterior = nullptr;

    while (actual != nullptr && actual -> id_zombie != id)
    {
        anterior = actual;
        actual = actual -> siguiente_zombie;
    }
    return actual;
    
}

void buscar_y_eliminar_zombie(Zombie*& lista_de_zombies, size_t id)
{
    Zombie* anterior = nullptr;
    Zombie* actual = buscar_zombie_por_id(lista_de_zombies, id, anterior);

    if (actual != nullptr)
    {
        eliminar_zombie(lista_de_zombies, actual, anterior);
    }
    else
    {
        cout << "Zombie no encontrado" << endl;
        return;
    }
    
}

void mover_zombie_escuadron_zombie(Zombie*& origen, Escuadrones* destino, size_t id)
{
    Zombie* anterior = nullptr;
    Zombie* actual = buscar_zombie_por_id(origen, id, anterior);

    if (actual)
    {
        if (!anterior)
        {
            origen = actual -> siguiente_zombie; //*Cuando el zombie es el primero de la lista
        }
        else
        {
            anterior -> siguiente_zombie = actual -> siguiente_zombie; //* Si el zombie esta en medio o al final de la lista
        }
        actual->siguiente_zombie = destino -> zombies_escuadron;
        destino -> zombies_escuadron = actual;
    }
    else
    {
        cout << "Zombie no encontrado" << endl;
    }
      
}

void editar_zombie(bool gestion, Zombie*& lista_de_zombies, size_t id)
{
    int opcion;
    gestion = true;
    Zombie* anterior = nullptr;
    Zombie* actual = buscar_zombie_por_id(lista_de_zombies, id, anterior);
    string Zombies_Predefinidos[] = {"Agil ", "Tanque ", "Inteligente ", "Infectado ", "Bioluminiscente "};
    int cantidad_tipos_zombies = sizeof(Zombies_Predefinidos) / sizeof(Zombies_Predefinidos[0]); //Obteniendo la longitud de la lista, de alguna forma se obtiene la cantidad de elementos del array


    if (actual != nullptr)
    {
        do
        {
            system("cls");
            cout << "--------------Modificar zombie--------------" << endl << endl;
            cout << "1) Modificar tipo" << endl;
            cout << "2) Modificar fortaleza" << endl;
            cout << "3) Modificar ataque" << endl;
            cout << "0) Volver" << endl << endl;
            cout << "--------------------------------------------" << endl;
            opcion = validar_numero("Introduce la opcion: ");

            switch (opcion)
            {
            case 1:
                while (gestion) 
                { 
                    cout << endl << "---------------------------" << endl;
                    for (int i = 0; i < cantidad_tipos_zombies; i++) //*Imprime los zombies del array predefinido
                    {
                        cout << i+1 << ") "<< Zombies_Predefinidos[i] << endl;
                    }
                    cout << endl << "---------------------------" << endl;
            
                    opcion = validar_numero("Cambia el tipo de zombie: "); //*validar que la opcion este dentro del numero de tipos de zombies
                    
                    if (opcion <= cantidad_tipos_zombies && opcion > 0)
                    {                   
                        for (int i = 0; i < cantidad_tipos_zombies; i++) //*Guarda el tipo de zombie segun su posicion en el array
                        {
                            if (opcion - 1 == i)
                            {
                                actual -> tipo_zombie = Zombies_Predefinidos[i];
                                break;
                            }
                        }
                        gestion = false;
                        cout << "Tipo de zombie cambiado" << endl;
                    }
                    else
                    {
                        cout << "**Introduce un zombie valido**" << endl;
                    }
                }
                gestion = true;

                
                system("PAUSE");
                break;

            case 2:

                actual -> fortaleza = validar_numero("Cambia la fortaleza: ");
                cout << "Fortaleza del zombie cambiado" << endl;
                system("PAUSE");
                break;

            case 3:

                actual -> ataque = validar_numero("Cambia el ataque: ");
                cout << "Ataque de zombie cambiado" << endl;
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
        cout << "El Zombie no existe" << endl;
        system("PAUSE");
    }
    
}

#endif