//*Posibles Structs que se usaran
using namespace std;

#ifndef MODEL_STRUCTS_H
#define MODEL_STRUCTS_H
 
struct Soldado {
    uintptr_t id_soldado;
    string nombre_soldado;
    int vida;
    Soldado* siguiente_soldado;
    // Todo: Agregar posible puntero que acceda a cada accesorio de la mochila de cada soldado
};

struct Zombie
{   
    uintptr_t id_zombie; //*El ID se asigna de esta manera para no hacer una funcion aparte que asigne un ID para ahorrar codigo, siendo este unico y de tipo size_t
    string tipo_zombie;
    int fortaleza;
    int ataque;
    Zombie* siguiente_zombie;

};

//*mochila que guarde accesorios como una lista y luego pasarle la mochila al soldado

struct Accesorio
{
    uintptr_t id_accesorio;
    string tipo_accesorio;
    string nombre_accesorio;
    int usos;
    Accesorio* siguiente_accesorio;
    //*Recordar, usos = -1 el item no se desgasta
};

struct Escuadrones
{
    string nombre_escuadron_zombie;
    string nombre_escuadron_soldados;
    Zombie* zombies_escuadron;
    Soldado* soldados_escuadron;
    Escuadrones* siguiente_escuadron;
    Estacion* estacion;
};
struct Inventario{
    Soldado *soldado_prox;
    Accesorio *accesorio_prox;
    Inventario *inventario_prox;
};


struct Estacion
{
    string nombre_estacion;
    Escuadrones* escuadron;
    Estacion* siguiente_estacion;

};

//Todo: Implementar el inventario/mochila de cada soldado que tendran 3 espacios, posible uso de arrays de structs
//*Debe tener: Nombre del soldado, Accesorios, Valores de Uso de cada Accesorio

//Todo: Creacion del Mapa, el cual estara conformado por eventos(estaciones y mas adelante las misiones) y escuadrones

#endif