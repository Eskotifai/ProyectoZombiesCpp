#include "model_structs.h"
#include "misiones.h"
#include <iostream>
#include <climits>
using namespace std;

void agregarEstacion(Estacion*& listaEstaciones, const string& nombre, int zombies) {
    Estacion* nueva = new Estacion{nombre, nullptr, zombies, listaEstaciones};
    listaEstaciones = nueva;
}

void agregarConexion(Estacion* listaEstaciones, const string& origen, const string& destino, int distancia) {
    Estacion* estacion = listaEstaciones;
    while (estacion != nullptr && estacion->nombre != origen) {
        estacion = estacion->siguiente_estacion;
    }
    if (estacion != nullptr) {
        Conexion* nueva = new Conexion{destino, distancia, estacion->conexiones};
        estacion->conexiones = nueva;
    }
}

// Buscar una estación en la lista
Estacion* buscarEstacion(Estacion* listaEstaciones, const string& nombre) {
    while (listaEstaciones != nullptr) {
        if (listaEstaciones->nombre == nombre) {
            return listaEstaciones;
        }
        listaEstaciones = listaEstaciones->siguiente_estacion;
    }
    return nullptr;
}


bool equipoSobrevive(Escuadrones* equipo, Estacion* estacion) {
    Soldado* actual = equipo->soldados_escuadron;
    while (actual != nullptr) {
        if (actual->vida > 0) {
            actual->vida -= estacion->zombies * 10; // Daño fijo por zombie
            if (actual->vida <= 0) {
                actual->vida = 0;
            }
        }
        actual = actual->siguiente_soldado;
    }

    actual = equipo->soldados_escuadron;
    while (actual != nullptr) {
        if (actual->vida > 0) {
            return true; // Al menos un soldado sobrevive
        }
        actual = actual->siguiente_soldado;
    }
    return false;
}


void caminoMasCorto(Estacion* listaEstaciones, const string& inicio, const string& destino) {
    struct Nodo {
        Estacion* estacion;
        int distancia;
        string previo;
        bool visitado;
    };

    Nodo nodos[22]; // Supongamos un máximo de 10 estaciones
    int numEstaciones = 0;

    // Construir la tabla de nodos
    Estacion* actual = listaEstaciones;
    while (actual != nullptr) {
        nodos[numEstaciones++] = {actual, INT_MAX, "", false};
        actual = actual->siguiente_estacion;
    }

 
