//*------------------Gestion de Soldados------------------
//Todo: Agregar, Eliminar y Modificar SOLDADOS
//Todo: Validar si existe un SOLDADO

//*------------------Gestion de Soldados------------------
//Todo: Agregar, Eliminar y Modificar SOLDADOS
//Todo: Validar si existe un SOLDADO
#include <iostream>
#include <string>

using namespace std;

#include "model_structs.h"
#include "../utilities/utility_validaciones.h"
#ifndef MODEL_SOLDADO_H
#define MODEL_SOLDADO_H


Soldado* CrearNodo(string nombre, int vida) {
Soldado* nuevo = new Soldado;
nuevo-> id_soldado = reinterpret_cast<uintptr_t>(nuevo);
nuevo->nombre_soldado = nombre;
nuevo->vida = vida;
nuevo->siguiente_soldado = nullptr;
return nuevo;
}

bool Vacio(Soldado* inicio) {
return inicio == nullptr;
}

void MostrarSoldado(Soldado* inicio) {
Soldado* actual = inicio;
while (actual != nullptr) {
    cout << "-------------------------------------" << endl;
    cout << "Nombre del Soldado: " << actual->nombre_soldado << endl;
    cout << "Vida del Soldado: " << actual->vida << endl;
    cout << "ID Soldado: " << actual ->id_soldado <<endl;
    actual = actual->siguiente_soldado;
    cout << "-------------------------------------" << endl;
}
}

void insertarPrincipio(Soldado *&inicio, Soldado* nuevo) {
nuevo->siguiente_soldado = inicio;
inicio = nuevo;
}

//**Esta funcion es para eliminar todo de la lista y que no quede flotando por ahi
void liberaSoldados(Soldado*& cabeza) {
Soldado* actual = cabeza;
while (actual != nullptr) {
    Soldado* siguiente = actual->siguiente_soldado;
    delete actual;
    actual = siguiente;
}
cabeza = nullptr; // Evitar puntero colgante
}

Soldado* modificarSoldado(Soldado* cabeza, const string& nombre, int vidanueva) {
Soldado* actual = cabeza;
while (actual != nullptr) {
    if (actual->nombre_soldado == nombre) {
        actual->vida = vidanueva;
        break;
    }
    actual = actual->siguiente_soldado;
}
return cabeza;
}


void eliminarSoldado(Soldado*& lista_de_soldados, Soldado* actual, Soldado* anterior) {
if (actual == nullptr) {
    cout << "Soldado no encontrado" << endl;
    return;
}
if (anterior == nullptr) {
    lista_de_soldados = actual->siguiente_soldado;
} else {
    anterior->siguiente_soldado = actual->siguiente_soldado;
}
delete actual;
cout << "Soldado eliminado" << endl;
}

Soldado* buscarSoldadoPorID(Soldado*& lista, size_t id_soldado, Soldado*& anterior) {
Soldado* actual = lista;
anterior = nullptr;
while (actual != nullptr && actual->id_soldado != id_soldado) {
    anterior = actual;
    actual = actual->siguiente_soldado;
}
return actual;
}


void buscarYEliminarSoldado(Soldado*& lista_de_soldados, size_t id_soldado) {
Soldado* anterior = nullptr;
Soldado* actual = buscarSoldadoPorID(lista_de_soldados, id_soldado, anterior);
if (actual != nullptr) {
    eliminarSoldado(lista_de_soldados, actual, anterior);
} else {
    cout << "Soldado no encontrado" << endl;
}
}

void mover_soldado_escuadron_soldado(Soldado*& origen, Escuadrones* destino, size_t id)
{
    Soldado* anterior = nullptr;
    Soldado* actual = buscarSoldadoPorID(origen, id, anterior);

    if (actual)
    {
        if (!anterior)
        {
            origen = actual -> siguiente_soldado; //*Cuando el zombie es el primero de la lista
        }
        else
        {
            anterior -> siguiente_soldado = actual -> siguiente_soldado; //* Si el zombie esta en medio o al final de la lista
        }

        actual->siguiente_soldado = destino -> soldados_escuadron;
        destino -> soldados_escuadron = actual;
    }
      
}

void modificarSoldado(Soldado* actual, int opcion) {
bool gestion = true;
while (gestion) {
    cout << "--------------Modificar Soldado--------------" << endl << endl;
    cout << "1) Modificar nombre" << endl;
    cout << "2) Modificar vida" << endl;
    cout << "0) Volver" << endl << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Introduce la opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            actual->nombre_soldado=validar_entrada_vacia("Ingrese el nuevo nombre del soldado: ");
            cout << "Nombre del soldado cambiado" << endl;
            break;
        case 2:
            actual->vida=validar_numero("Ingrese la nueva vida: ");
            cout << "Vida del soldado cambiada" << endl;
            break;
        case 0:
            gestion = false;
            break;
        default:
            cout << "**Introduce una opción correcta**" << endl;
            break;
    }
}
}

#endif