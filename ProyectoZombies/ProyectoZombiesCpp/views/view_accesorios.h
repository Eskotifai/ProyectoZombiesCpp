#include <iostream>
#include "../model/model_structs.h"
#include "../model/model_accesorios.h"

using namespace std;

void menu_accesorios(bool gestion, int opcion, Accesorio*& lista_de_accesorios)
{
    string tipo_accesorio;
    string nombre;
    int usos;
    Accesorio* accesorio;
    size_t verificar_id_accesorio;

    string Tipos_Accesorios_Predefinidos[] = {"Ataque ", "Defensa ", "Supervivencia "};
    int cantidad_tipos_accesorios = sizeof(Tipos_Accesorios_Predefinidos) / sizeof(Tipos_Accesorios_Predefinidos[0]); //Obteniendo la longitud de la lista, de alguna forma se obtiene la cantidad de elementos del array

    

    do
    {   system("cls");
        cout << "---------Aqui se gestionan los accesorios---------" << endl << endl; //*SUBMENU DE ACCESORIOS
        cout << "1) Agregar accesorio" << endl;
        cout << "2) Eliminar accesorio" << endl;
        cout << "3) Modificar accesorio" << endl;
        cout << "4) Ver Accesorios" << endl;
        cout << "0) **Salir al menu principal**" << endl << endl;
        cout << "--------------------------------------------------" << endl;
        opcion = validar_numero("Introduce la opcion: ");

        switch (opcion)
        {
        case 1:

            system("cls");
            cout << "------TIPOS DE ACCESORIOS------" << endl << endl; //* Mejorar la pedida de entradas, por lo menos no rompe el programa

            for (int i = 0; i < cantidad_tipos_accesorios; i++) //*Imprime los zombies del array predefinido
            {
                cout << i+1 << ") "<< Tipos_Accesorios_Predefinidos[i] << endl;
            }
     
            cout << endl << "---------------------------" << endl;

            while (gestion) 
            {               
                opcion = validar_numero("Agrega el tipo de accesorio: "); //validar que la opcion este dentro del numero de tipos de zombies
                
                if (opcion <= cantidad_tipos_accesorios && opcion > 0)
                {
                    
                for (int i = 0; i < cantidad_tipos_accesorios; i++) //*Guarda el tipo de zombie segun su posicion en el array
                {
                    if (opcion - 1 == i)
                    {
                        tipo_accesorio = Tipos_Accesorios_Predefinidos[i];
                        break;
                    }
                    
                }

                    nombre = validar_entrada_vacia("Nombre del accesorio: ");
                    usos = validar_numero("Usos del accesorio: ");

                    accesorio = Crear_Accesorio(tipo_accesorio, nombre, usos);
                    
                    cout << "Tipo de Accesorio: "<< accesorio->tipo_accesorio << endl;
                    cout << "Nombre: "<< accesorio->nombre_accesorio << endl;
                    cout << "Usos: "<< accesorio->usos << endl;
                    cout << "ID del Accesorio: " << accesorio->id_accesorio << endl;           

                    agregar_accesorio(lista_de_accesorios, Crear_Accesorio(tipo_accesorio, nombre, usos));

                    cout << "ACCESORIO CREADO CON EXITO" << endl;
                    system("PAUSE");
                    gestion = false;
                    // mostrar_zombies(lista_de_zombies);
                }
                else
                {
                    cout << "**Introduce un tipo de accesorio valido**" << endl;
                }
            }
            gestion = true;
            break;

        case 2:

            system("cls");
            cout << "-----------ELIMINAR ACCESORIOS-----------" << endl << endl;
            cout << "1) Eliminar todos los accesorios agregados" << endl;
            cout << "2) Eliminar un accesorio de los agregados" << endl; 
            cout << "0) Volver" << endl; 
            cout << endl << "--------------------------------------" << endl;


            do
            {
                opcion = validar_numero("Introduce la opcion: ");
                switch (opcion)
                {
                case 1:

                    eliminar_todos_los_accesorios(lista_de_accesorios);
                    cout << "**Se eliminaron los accesorios agregados**" << endl;
                    break;

                case 2:

                    if (lista_de_accesorios != nullptr)
                    {   
                        mostrar_accesorios(lista_de_accesorios);
                        verificar_id_accesorio = validar_numero("Introduce el id del accesorio: ");
                        buscar_y_eliminar_accesorio(lista_de_accesorios, verificar_id_accesorio);
                    }
                    else
                    {
                        cout << "Lista vacia" << endl;
                    }
                    
                    break;

                case 0:
                
                    gestion = false;
                    break;
                
                default:

                    cout << "**Introduce una opcion correcta**" << endl; 
                    break;
                }
            } while (gestion);
            gestion = true;
            
            break;

        case 3:

            mostrar_accesorios(lista_de_accesorios);
            verificar_id_accesorio = validar_numero("Introduce el id del accesorio: ");
            editar_accesorio(gestion, lista_de_accesorios, verificar_id_accesorio);
            break;

        case 4:

            cout << "Aqui se VEN ACCESORIOS" << endl;
            mostrar_accesorios(lista_de_accesorios);
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
//Todo: Hacer y llamar a la funcion segun el case