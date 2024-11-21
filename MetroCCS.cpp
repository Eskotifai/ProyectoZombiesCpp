#include <iostream>
#include <string>
using namespace std;

const int NUM_ESTACIONES = 22;

struct Conexion {
    string estacionDestino;
    Conexion* siguiente;
};

struct Estacion {
    string nombre;
    Conexion* conexiones;
};

struct MetroCaracas {
    Estacion estaciones[NUM_ESTACIONES];
    int numEstaciones = 0;

    void agregarEstacion(const string& nombre) {
        if (numEstaciones < NUM_ESTACIONES) {
            estaciones[numEstaciones].nombre = nombre;
            estaciones[numEstaciones].conexiones = nullptr;
            numEstaciones++;
        }
        else {
            cout << "No se pueden agregar más estaciones" << endl;
        }
    }

    void conectarEstaciones(const string& estacion1, const string& estacion2) {
        int indice1 = buscarEstacion(estacion1);
        int indice2 = buscarEstacion(estacion2);

        if (indice1 != -1 && indice2 != -1) {
            agregarConexion(indice1, estacion2);
            agregarConexion(indice2, estacion1);
        }
        else {
            cout << "Una o ambas estaciones no existen" << endl;
        }
    }

    void mostrarGrafo() {
        for (int i = 0; i < numEstaciones; i++) {
            cout << estaciones[i].nombre << " -> ";
            Conexion* actual = estaciones[i].conexiones;
            while (actual != nullptr) {
                cout << actual->estacionDestino << " ";
                actual = actual->siguiente;
            }
            cout << endl;
        }
    }

    int buscarEstacion(const string& nombre) {
        for (int i = 0; i < numEstaciones; i++) {
            if (estaciones[i].nombre == nombre) {
                return i;
            }
        }
        return -1;
    }

    void agregarConexion(int indice, const string& destino) {
        Conexion* nuevaConexion = new Conexion{ destino, nullptr };
        if (estaciones[indice].conexiones == nullptr) {
            estaciones[indice].conexiones = nuevaConexion;
        }
        else {
            Conexion* actual = estaciones[indice].conexiones;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevaConexion;
        }
    }

    // Destructor para liberar la memoria ocupada por las conexiones
    ~MetroCaracas() {
        for (int i = 0; i < numEstaciones; i++) {
            Conexion* actual = estaciones[i].conexiones;
            while (actual != nullptr) {
                Conexion* temp = actual;
                actual = actual->siguiente;
                delete temp;
            }
        }
    }
};

int main() {
    MetroCaracas metro;

    string nombresEstaciones[NUM_ESTACIONES] = {
        "Propatria", "Perez Bonalde", "Plaza Sucre", "Gato Negro", "Agua Salud",
        "Cano Amarillo", "Capitolio", "La Hoyada", "Parque Carabobo",
        "Bellas Artes", "Colegio de Ingenieros", "Plaza Venezuela",
        "Sabana Grande", "Chacaito", "Chacao", "Altamira",
        "Miranda", "Los Dos Caminos", "Los Cortijos", "La California",
        "Petare", "Palo Verde"
    };


    for (const string& estacion : nombresEstaciones) {
        metro.agregarEstacion(estacion);
    }


    for (int i = 0; i < NUM_ESTACIONES - 1; i++) {
        metro.conectarEstaciones(nombresEstaciones[i], nombresEstaciones[i + 1]);
    }


    metro.mostrarGrafo();

    return 0;
}