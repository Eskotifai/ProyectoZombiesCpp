#include <iostream> 
#include <string>

//*#Includes de las librerias

//*--------------------MODEL--------------------

#include "model/model_structs.h"
#include "model/model_soldados.h"
#include "model/model_zombies.h"
#include "model/model_accesorios.h"
#include "model/model_inventario.h"
#include "model/model_estaciones.h"
#include "model/model_escuadrones.h"

//*--------------------VIEWS--------------------

#include "views/view_soldados.h"
#include "views/view_zombies.h"
#include "views/view_accesorios.h"
#include "views/view_estaciones.h"
#include "views/view_inventario.h"
#include "views/view_escuadrones.h"

//*--------------------UTILITIES--------------------

#include "utilities/utility_mostrarmensaje.h"
#include "utilities/utility_validaciones.h"

//*Crear y agregar las librerias necesarias para la segunda entrega

using namespace std;


Zombie* lista_de_zombies = nullptr;
Accesorio* lista_de_accesorios = nullptr;
Escuadrones* lista_de_escuadrones = nullptr;
Soldado* lista_de_soldados = nullptr;
Inventario* Lista_Inventarios = nullptr;//!verificar pq la monda esa no agarra, dice unusuble variable .-.



int main()
{   //*-----------MENU PRINCIPAL-----------
    system("cls");

    //*Inicializacion de Variables en el MAIN

    bool run = true; //*booleano que inicia el ciclo principal
    int opcion;             
    bool mensaje_activo = false;  //*posible solucion para imprimir el mensaje de opcion incorrecta solo en el menu principal  
    string mensaje; 

                            
    do //*Ciclo principal
    {
        // Zombie* lista_de_zombies = nullptr;
        bool gestionando = true;  //*booleano que permite iniciar los ciclos anidados. Solucion efectiva?, Ver la posibilidad de mejorar los menus de otra forma 

        
        //Todo: Arreglar error de impresion de opcion incorrecta (no se imprime dentro del menu principal)

        system("cls");
        // mostrar_zombies(lista_de_zombies);
        // system("pause");
        
        
        
        cout << "-------------RUNNING DEAD-------------" << endl << endl; //*MENU PRINCIPAL
        cout << "1) Gestionar Soldados" << endl;
        cout << "2) Gestionar Zombies" << endl;
        cout << "3) Gestionar Accesorios" << endl;
        cout << "4) Gestionar Estaciones" << endl;
        cout << "5) Gestionar Inventario" << endl;
        cout << "6) Gestionar Escuadrones" << endl;
        cout << "0) **Salir**" << endl << endl;
        cout << "--------------------------------------" << endl;

        // mostrar_zombies(lista_de_zombies);
        
        mostrar_mensaje(mensaje_activo, mensaje); 
        
        opcion = validar_numero("Introduce la opcion: "); //*llamar a la función validar_numero, obtener su valor de retorno (un número entero) y asignar ese valor a la variable opcion, tambien se le pasa por parametro un texto cualquiera
        
        switch (opcion)
        {
        case 1:

            menu_soldados(gestionando, opcion, lista_de_soldados); //*llamando al SUBMENU DE SOLDADOS como una funcion desde view_soldados
            //*SI FURULA
            break;

        case 2:

            menu_zombies(gestionando, opcion, lista_de_zombies); //*llamando al SUBMENU DE ZOMBIES como una funcion desde view_zombies
            //*SI FURULA
            break;

        case 3:

            menu_accesorios(gestionando, opcion, lista_de_accesorios); //*llamando al SUBMENU DE ACCESORIOS como una funcion desde view_accesorios
            //*SI FURULA
            break;

        case 4:

            menu_estaciones(gestionando, opcion); //*llamando al SUBMENU DE ESTACIONES como una funcion desde view_estaciones
            //!ESTA ES LA Q NO FURULA PROFE (NOS FALTO LO QUE VIENE SIENDO EL MAPA)
            break;

        case 5:

            menu_inventario(gestionando, opcion,lista_de_soldados,lista_de_accesorios,Lista_Inventarios); //*llamando al SUBMENU DE INVENTARIO como una funcion desde view_inventario
            //? ESTE HAY QUE VER EL MOSTRAR PQ SI FURULA PERO ESE EL PROBLEMITA (EL MENU ES PASABLE TABIEN, PIEDAD)
            break;

        case 6:

            menu_escuadrones(gestionando, opcion, lista_de_escuadrones, lista_de_zombies, lista_de_soldados); //*llamando al SUBMENU DE ESCUADRONES como una funcion desde view_escuadrones
            //*SI FURULA PERO EL MENU ESTA PASABLE
            break;

        //*Agregar el resto de casos para la ultima entrega, Misiones y Bitacora(Archivos.txt) 

        case 0:

            system("cls");
            run = false;
            cout << "**Salir**" << endl;

            eliminar_todos_los_zombies(lista_de_zombies);//!NOS FALTA ELIMINAR LA MEMORIA DE LOS DEMAS PA QUE NO GUARDE MAS BASURA
            
            break;

        default:  
            
            
            mensaje_activo = true;
            mensaje = "**Opcion no Valida**";
            break;
        
        } 

    
    } while (run);

    return 0;
    
}