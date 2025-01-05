#ifndef MISIONES_H
#define MISIONES_H

#include <string>

using namespace std;

// Estructura que representa una conexión entre estaciones
struct Conexion {
    string destino;                // Nombre de la estación destino
    int distancia;                 // Distancia a la estación destino
    Conexion* siguiente_conexion;  // Puntero a la siguiente conexión
};

// Estructura que representa una estación
struct Estacion {
    string nombre;                 // Nombre de la estación
    Conexion* conexiones = nullptr; // Puntero a la lista de conexiones
    int zombies;                   // Número de zombies en la estación
    Estacion* siguiente_estacion = nullptr; // Puntero a la siguiente estación
};

// Estructura que representa un soldado
struct Soldado {
    size_t id_soldado;             // ID único del soldado
    string nombre_soldado;         // Nombre del soldado
    int vida;                      // Vida del soldado
    Soldado* siguiente_soldado = nullptr; // Puntero al siguiente soldado
};

// Estructura que representa un escuadrón
struct Escuadrones {
    string nombre_escuadron;       // Nombre del escuadrón
    Soldado* soldados_escuadron = nullptr; // Puntero a la lista de soldados
    Escuadrones* siguiente_escuadron = nullptr; // Puntero al siguiente escuadrón
};

// Funciones para gestionar estaciones y soldados
void agregarEstacion(Estacion*& listaEstaciones, const string& nombre, int zombies);
void agregarConexion(Estacion* listaEstaciones, const string& origen, const string& destino, int distancia);
Estacion* buscarEstacion(Estacion* listaEstaciones, const string& nombre);
void agregarSoldado(Soldado*& listaSoldados, const string& nombre, int vida);
bool equipoSobrevive(Escuadrones* equipo, Estacion* estacion);
void caminoMasCorto(Estacion* listaEstaciones, const string& inicio, const string& destino);

#endif // MISIONES_H
