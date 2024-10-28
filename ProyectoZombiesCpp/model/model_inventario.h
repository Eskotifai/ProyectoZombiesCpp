//*------------------Gestion de Inventarios------------------
//Todo: Agregar, Eliminar y Modificar INVENTARIOS
//Todo: Validar si existe un INVENTARIO
#include <iostream>
#include <string>

using namespace std;

#include "../utilities/utility_validaciones.h"
#include "model_structs.h"

#ifndef MODEL_INVENTARIO_H
#define MODEL_INVENTARIO_H

bool VacioInventario(Inventario* inicio) {
    return inicio == nullptr;
}

Inventario* CrearInventario(Soldado* soldado) {
    Inventario* nuevo_inventario = new Inventario;
    nuevo_inventario->soldado_prox = soldado;
    nuevo_inventario->accesorio_prox = nullptr;
    nuevo_inventario->inventario_prox = nullptr;
    return nuevo_inventario;
}

void agregarAccesorioInventario(Inventario*& inventario, Accesorio* accesorio) {
    if (inventario->accesorio_prox == nullptr) {
        inventario->accesorio_prox = accesorio;
    } else {
        Accesorio* actual = inventario->accesorio_prox;
        while (actual->siguiente_accesorio != nullptr) {
            actual = actual->siguiente_accesorio;
        }
        actual->siguiente_accesorio = accesorio;
    }
}

void mostrarInventario(Inventario* inventario) { //*REVISAR ESTA FUNCION CON EL MENU DE INVENTARIO
    cout << "Inventario del Soldado: " << inventario->soldado_prox->nombre_soldado << endl;
    Accesorio* actual = inventario->accesorio_prox;
    while (actual != nullptr) {
        cout << "---------------------------------------------------" << endl;
        cout << "Tipo: " << actual->tipo_accesorio << endl;
        cout << "Nombre: " << actual->nombre_accesorio << endl;
        cout << "Usos: " << actual->usos << endl;
        cout << "ID Accesorio: " << actual->id_accesorio << endl;
        cout << "---------------------------------------------------" << endl;
        actual = actual->siguiente_accesorio;
    }
}

void eliminarTodosAccesorios(Inventario*& inventario) {
    while (inventario->accesorio_prox != nullptr) {
        Accesorio* actual = inventario->accesorio_prox;
        inventario->accesorio_prox = inventario->accesorio_prox->siguiente_accesorio;
        delete actual;
    }
    inventario->accesorio_prox = nullptr;
}

void eliminarAccesorioInventario(Inventario*& inventario, size_t id_accesorio) {
    Accesorio* actual = inventario->accesorio_prox;
    Accesorio* anterior = nullptr;

    while (actual != nullptr && actual->id_accesorio != id_accesorio) {
        anterior = actual;
        actual = actual->siguiente_accesorio;
    }

    if (actual == nullptr) {
        cout << "Accesorio no encontrado en el inventario del soldado." << endl;
        return;
    }

    if (anterior == nullptr) {
        inventario->accesorio_prox = actual->siguiente_accesorio;
    } else {
        anterior->siguiente_accesorio = actual->siguiente_accesorio;
    }
    delete actual;
    cout << "Accesorio eliminado del inventario del soldado." << endl;
}


#endif