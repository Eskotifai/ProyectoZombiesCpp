//*------------------Gestion de Estaciones------------------
//Todo: Agregar, Eliminar y Modificar ESTACIONES
//Todo: Validar si existe una ESTACION
//Todo: Permitir la repeticion de zombies en una estacion para contabilizar todos los zombies por tipo, posible cambio en el struct de zombie

#include <iostream>
#include <string>
#include "../utilities/utility_validaciones.h"
#include "model_structs.h"
using namespace std;

#ifndef MODEL_ESTACIONES_H
#define MODEL_ESTACIONES_H

Estacion* Crear_Estacion(string nombre)
{
    Estacion* nueva_estacion = new Estacion;
    nueva_estacion -> nombre_estacion = nombre;
    nueva_estacion -> siguiente_estacion = nullptr;
    nueva_estacion -> escuadron = nullptr;

    return nueva_estacion;
}

void agregar_estacion(Estacion *&lista_de_estaciones, Estacion* nueva_estacion)
{
    if (lista_de_estaciones == nullptr)
    {
        lista_de_estaciones = nueva_estacion;
    }
    
    else
    {
        Estacion* actual = lista_de_estaciones;

        while (actual -> siguiente_estacion != nullptr)
        {
            actual = actual -> siguiente_estacion;
        }
        actual -> siguiente_estacion = nueva_estacion;
        
    }
    
}

void escuadron_a_estacion(Estacion*& lista_de_estaciones, string nombre, Escuadrones* escuadron)
{
    // Estacion* actual = lista_de_estaciones;
    // while (actual != nullptr)
    // {
    //     if (actual -> nombre_estacion == nombre)
    //     {
            
    //     }
        
    // }
    
}

Estacion* buscar_estacion_por_nombre(Estacion*& lista, string nombre, Estacion*& anterior)
{
    Estacion* actual = lista;
    anterior = nullptr;

    while (actual != nullptr && actual -> nombre_estacion != nombre)
    {
        anterior = actual;
        actual = actual -> siguiente_estacion;
    }
    return actual;
    
}

void mostrar_informacion_estacion(Estacion*& lista_de_estaciones)
{
    Estacion* actual = lista_de_estaciones;
    while (actual != nullptr)
    {
        cout << "Estacion: " << actual ->nombre_estacion << endl;
        Escuadrones* escuadron_actual = actual -> escuadron;
        while (escuadron_actual != nullptr)
        {
            cout << "Escuadron de Soldados: " << escuadron_actual->nombre_escuadron_soldados << endl;
            cout << "Escuadron de Zombies: " << escuadron_actual->nombre_escuadron_soldados << endl;
            escuadron_actual = escuadron_actual ->siguiente_escuadron;
        }
        actual = actual -> siguiente_estacion;
    }
    
}



#endif