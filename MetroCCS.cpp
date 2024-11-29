#include <iostream>
#include <string>
using namespace std;

struct Conexion {
	string estacionDestino;
	Conexion* siguiente;
};

struct NodoEstacion {
	string nombre;
	Conexion* conexiones;
	NodoEstacion* siguiente;
};

struct MetroCaracas {
	NodoEstacion* estaciones;
	int numEstaciones;

	MetroCaracas() : estaciones(nullptr), numEstaciones(0) {}

	void agregarEstacion(const string& nombre) {
		NodoEstacion* nuevaEstacion = new NodoEstacion{ nombre, nullptr, nullptr };
		if (estaciones == nullptr) {
			estaciones == nuevaEstacion;
		} else {
			NodoEstacion* actual = estaciones;
			while (actual->siguiente != nullptr) {
				actual = actual->siguiente;
			}
			actual->siguiente = nuevaEstacion;
		}
		numEstaciones++;
	}

	NodoEstacion* buscarEstacion(const string& nombre) {
		NodoEstacion* actual = estaciones;
		while (actual != nullptr) {
			if (actual->nombre == nombre) {
				return actual;
			}
			actual = actual->siguiente;
		}
		return nullptr;
	}

	void agregarConexion(NodoEstacion* estacion, const string& destino) {
		Conexion* nuevaConexion = new Conexion{ destino, nullptr };
		if (estacion->conexiones == nullptr) {
			estacion->conexiones = nuevaConexion;
		} else {
			Conexion* actual = estacion->conexiones;
			while (actual->siguiente != nullptr) {
				actual = actual->siguiente;
			}
			actual->siguiente = nuevaConexion;
		}
	}

	void conectarEstaciones(const string& estacion1, const string& estacion2) {
		NodoEstacion* nodo1 = buscarEstacion(estacion1);
		NodoEstacion* nodo2 = buscarEstacion(estacion2);

		if (nodo1 != nullptr && nodo2 != nullptr) {
			agregarConexion(nodo1, estacion2);
			agregarConexion(nodo2, estacion1);
		} else {
			cout  << estacion1 << " - " << estacion2 << endl;
		}
	}

	void mostrarGrafo() {
		NodoEstacion* actual = estaciones;
		while (actual != nullptr) {
			cout << actual->nombre << "->";
			Conexion* conexionActual = actual->conexiones;
			while (conexionActual != nullptr) {
				cout << conexionActual->estacionDestino << " ";
				conexionActual = conexionActual->siguiente;
			}
			cout << endl;
			actual = actual->siguiente;
		}
	}

	//Liberar memoria de conexiones y estaciones
	~MetroCaracas() {
		NodoEstacion* actual = estaciones;
		while (actual != nullptr) {
			Conexion* conexionActual = actual->conexiones;
			while (conexionActual != nullptr) {
				Conexion* tempConexion = conexionActual;
				conexionActual = conexionActual->siguiente;
				delete tempConexion;
			}
			NodoEstacion* tempEstacion = actual;
			actual = actual->siguiente;
			delete tempEstacion;
		}
	}

};

int main() {
	MetroCaracas metro;

	string nombresEstaciones[] = {
		"Propatria", "Perez Bonalde", "Plaza Sucre", "Gato Negro", "Agua Salud",
		"Cano Amarillo", "Capitolio", "La Hoyada", "Parque Carabobo",
		"Bellas Artes", "Colegio de Ingenieros", "Plaza Venezuela", "Sabana Grande",
		"Chacaito", "Chacao", "Altamira", "Miranda", "Los Dos Caminos", "Los Cortijos",
		"La California", "Petare", "Palo Verde"
	};

	for (const string& estacion : nombresEstaciones) {
		metro.agregarEstacion(estacion);
	}

	for (size_t i = 0; i < sizeof(nombresEstaciones) / sizeof(nombresEstaciones[0]) - 1; i++) {
		metro.conectarEstaciones(nombresEstaciones[i], nombresEstaciones[i + 1]);
	}

	metro.mostrarGrafo();

	return 0;
}