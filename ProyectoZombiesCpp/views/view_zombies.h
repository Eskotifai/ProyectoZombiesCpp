#include <iostream>
#include "../model/model_zombies.h"
#include "../model/model_structs.h"
// #include "../utilities/utility_validaciones.h"

using namespace std;

void menu_zombies(bool gestion, int opcion, Zombie*& lista_de_zombies) //!La lista se debe pasar por referencia para no perderla, si se usa Zombie* lista_de_zombies se pierde la lista
{
    
    // mostrar_zombies(lista_de_zombies);


    //*VARIABLES LOCALES

    string tipo_zombie;
    int fortaleza;
    int ataque;
    Zombie* zombie;
    size_t verificar_id_zombie;

    string Zombies_Predefinidos[] = {"Agil ", "Tanque ", "Inteligente ", "Infectado ", "Bioluminiscente "};
    int cantidad_tipos_zombies = sizeof(Zombies_Predefinidos) / sizeof(Zombies_Predefinidos[0]); //Obteniendo la longitud de la lista, de alguna forma se obtiene la cantidad de elementos del array

    do
    {   
        system("cls");
        cout << "---------Aqui se gestionan los zombies---------" << endl << endl; //*SUBMENU DE ZOMBIES
        cout << "1) Agregar zombie" << endl;
        cout << "2) Eliminar zombies" << endl;
        cout << "3) Modificar zombie" << endl;
        cout << "4) Ver zombies" << endl;
        cout << "0) **Salir al menu principal**" << endl << endl;
        cout << "-----------------------------------------------" << endl;

        opcion = validar_numero("Introduce la opcion: ");
        
        switch (opcion)
        {
        case 1:

            system("cls");
            cout << "-----TIPOS DE ZOMBIES------" << endl << endl; //* Mejorar la pedida de entradas, por lo menos no rompe el programa

            for (int i = 0; i < cantidad_tipos_zombies; i++) //*Imprime los zombies del array predefinido
            {
                cout << i+1 << ") "<< Zombies_Predefinidos[i] << endl;
            }
     
            cout << endl << "---------------------------" << endl;

            while (gestion) 
            {               
                opcion = validar_numero("Agrega el tipo de zombie: "); //validar que la opcion este dentro del numero de tipos de zombies
                
                if (opcion <= cantidad_tipos_zombies && opcion > 0)
                {
                    
                for (int i = 0; i < cantidad_tipos_zombies; i++) //*Guarda el tipo de zombie segun su posicion en el array
                {
                    if (opcion - 1 == i)
                    {
                        tipo_zombie = Zombies_Predefinidos[i];
                        break;
                    }
                    
                }

                    fortaleza = validar_numero("Fortaleza del Zombie: ");
                    ataque = validar_numero("Ataque del zombie: ");

                    zombie = Crear_Zombie(tipo_zombie, fortaleza, ataque);
                    
                    cout << "Tipo de zombie: "<< zombie->tipo_zombie << endl;
                    cout << "Fortaleza: "<< zombie->fortaleza << endl;
                    cout << "Ataque: "<< zombie->ataque << endl;
                    cout << "ID del Zombie: " << zombie->id_zombie << endl;           

                    agregar_zombie(lista_de_zombies, Crear_Zombie(tipo_zombie, fortaleza, ataque));

                    cout << "ZOMBIE CREADO CON EXITO" << endl;
                    system("PAUSE");
                    gestion = false;
                    // mostrar_zombies(lista_de_zombies);
                }
                else
                {
                    cout << "**Introduce un zombie valido**" << endl;
                }
            }
            gestion = true;
            

            break;

        case 2:

            system("cls");
            cout << "-----------ELIMINAR ZOMBIES-----------" << endl << endl;
            cout << "1) Eliminar todos los zombies" << endl;
            cout << "2) Eliminar un zombie de los agregados" << endl; 
            cout << "0) Volver" << endl; 
            cout << endl << "--------------------------------------" << endl;


            do
            {
                opcion = validar_numero("Introduce la opcion: ");
                switch (opcion)
                {
                case 1:

                    eliminar_todos_los_zombies(lista_de_zombies);
                    cout << "**Se eliminaron los zombies agregados**" << endl;
                    break;

                case 2:

                    if (lista_de_zombies != nullptr)
                    {   
                        mostrar_zombies(lista_de_zombies);
                        verificar_id_zombie = validar_numero("Introduce el id zombie: ");
                        buscar_y_eliminar_zombie(lista_de_zombies, verificar_id_zombie);
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

            mostrar_zombies(lista_de_zombies);
            // do
            // {
            verificar_id_zombie = validar_numero("Introduce el id del zombie a modificar: ");
            editar_zombie(gestion, lista_de_zombies, verificar_id_zombie);
            // } while (gestion);
            
            
            break;

        case 4:
            
            cout << "-------------------ZOMBIES CREADOS-------------------" << endl;
            mostrar_zombies(lista_de_zombies);
            cout << "-----------------------------------------------------" << endl;
            system("PAUSE");

            break;
        
        case 0:

            // mostrar_zombies(lista_de_zombies);
            // system("PAUSE");
            gestion = false;
            // mostrar_zombies(lista_de_zombies);
            // system("PAUSE");
        
        default:

            cout << "**Introduce una opcion correcta**" << endl;
            // mostrar_zombies(lista_de_zombies);

            break;

        }
    } while (gestion);

}