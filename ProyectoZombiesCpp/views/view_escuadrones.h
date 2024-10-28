#include <iostream>
using namespace std;

void menu_escuadrones(bool gestion, int opcion, Escuadrones*& lista_de_escuadrones, Zombie*& lista_de_zombies, Soldado*& lista_de_soldados)
{
    Escuadrones* nuevo_escuadron_soldados;
    Escuadrones* nuevo_escuadron_zombies;
    Escuadrones* escuadron_soldados;
    Escuadrones* escuadron_zombies;
    string nombre_escuadron_soldados;
    string nombre_escuadron_zombies;
    Escuadrones* anterior = nullptr;
    // string verificar_nombre_soldado;
    size_t verificar_id_zombie;
    size_t verificar_id_soldado;

    
    
    do
    {   
        system("cls");
        cout << "---------Aqui se gestionan los escuadrones---------" << endl << endl; //*SUBMENU DE ESCUADRONES
        cout << "1) Agregar escuadron" << endl;
        cout << "2) Eliminar escuadron" << endl;
        cout << "3) Modificar escuadron" << endl;
        cout << "4) Ver escuadron" << endl;
        cout << "0) **Salir al menu principal**" << endl << endl;
        cout << "---------------------------------------------------" << endl;
        opcion = validar_numero("Introduce la opcion: ");

        switch (opcion)
        {
        case 1:

            do 
            {
                cout << "Aqui se AGREGAN ESCUADRONES" << endl;
                cout << "1) Crear escuadron de soldados" << endl;
                cout << "2) Crear escuadron de zombies" << endl;
                cout << "0) Volver" << endl;
                opcion = validar_numero("Introduce la opcion: ");
                switch (opcion) 
                {
                case 1:

                    nombre_escuadron_soldados = validar_entrada_vacia("Introduce el nombre del escuadron: ");
                    nuevo_escuadron_soldados = crear_escuadron_soldados(nombre_escuadron_soldados);
                    agregar_escuadron_soldados(lista_de_escuadrones, crear_escuadron_soldados(nombre_escuadron_soldados));

                    break;

                case 2:

                    nombre_escuadron_zombies = validar_entrada_vacia("Introduce el nombre del escuadron: ");
                    nuevo_escuadron_zombies = crear_escuadron_zombie(nombre_escuadron_zombies);
                    agregar_escuadron_zombie(lista_de_escuadrones, crear_escuadron_zombie(nombre_escuadron_zombies));
                    
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

        case 2:
          
            do
            {
                cout << "Aqui se ELIMINAN ESCUADRONES" << endl;
                cout << "1) Eliminar escuadron de soldados" << endl;
                cout << "2) Eliminar escuadron de zombies" << endl;
                cout << "0) Volver" << endl;
                opcion = validar_numero("Introduce una opcion: ");
                switch (opcion)
                {
                case 1:
                    
                    break;
                case 2:
                    do
                    {
                        cout << "Aqui se ELIMINAN ESCUADRONES" << endl;
                        cout << "1) Eliminar todos los zombies de todos los escuadrones" << endl;
                        cout << "2) Eliminar un zombie de un escuadron de zombies" << endl;
                        cout << "3) Eliminar todos los zombies de un escuadron" << endl;
                        cout << "0) Volver" << endl;
                        opcion = validar_numero("Introduce una opcion: ");

                        switch (opcion)
                        {
                        case 1:

                            eliminar_todos_escuadron_zombie(lista_de_escuadrones);
                            cout << " Se eliminaron todos los zombies de todos los escuadrones zombies" <<endl;
                            system("PAUSE");

                            break;
                        case 2:

                            mostrar_nombre_escuadrones_zombies(lista_de_escuadrones);
                            nombre_escuadron_zombies = validar_entrada_vacia("Introduce el nombre del escuadron: ");
                            verificar_id_zombie = validar_numero("Introduce el ID del zombie: ");
                            eliminar_un_zombie_escuadron(lista_de_escuadrones, verificar_id_zombie, nombre_escuadron_zombies);
                            break;
                        
                        case 3:

                            mostrar_nombre_escuadrones_zombies(lista_de_escuadrones);
                            nombre_escuadron_zombies = validar_entrada_vacia("Introduce el nombre del escuadron: ");
                            eliminar_todos_zombies_un_escuadron(lista_de_escuadrones, nombre_escuadron_zombies);
                            
                            break;

                        case 0:
                            gestion = false;
                        
                        default:
                            break;
                        }
                    } while (gestion);
                    gestion = true;
                    
                    break;
                case 0:
                    gestion = false;
                    break;
                
                default:
                    cout << "Introduce una opcion valida" << endl;
                    break;
                }
            } while (gestion);
            gestion = true;

            break;

        case 3:
            do
            {
                system("cls");
                cout << "----------Aqui se MODIFICAN ESCUADRONES---------" << endl; // Si se va a crear el escuadron es porque ya los soldados/zombies estan listos para "combatir"
                cout << "1) Agregar soldado a un escuadron de soldados" << endl;
                cout << "2) Agregar zombie a un escuadron de zombies" << endl;
                cout << "0) Volver" << endl;
                opcion = validar_numero("Introduce una opcion: ");
                switch (opcion)
                {
                case 1:
                    
                    mostrar_nombre_escuadrones_soldados(lista_de_escuadrones);
                    nombre_escuadron_soldados = validar_entrada_vacia("Introduce el nombre del escuadron: ");
                    escuadron_soldados = buscar_escuadron_soldados(lista_de_escuadrones, nombre_escuadron_soldados, anterior);
                    if (escuadron_soldados != nullptr)
                    {
                        MostrarSoldado(lista_de_soldados);
                        verificar_id_soldado = validar_numero("Introduce el ID del soldado: ");
                        mover_soldado_escuadron_soldado(lista_de_soldados, escuadron_soldados, verificar_id_soldado);
                    }
                    
                    
                    break;
                case 2:

                    mostrar_nombre_escuadrones_zombies(lista_de_escuadrones);
                    nombre_escuadron_zombies = validar_entrada_vacia("Introduce el nombre del escuadron: ");
                    escuadron_zombies = buscar_escuadron_zombies(lista_de_escuadrones, nombre_escuadron_zombies, anterior);
                    if (escuadron_zombies != nullptr)
                    {
                        mostrar_zombies(lista_de_zombies);
                        verificar_id_zombie = validar_numero("Introduce el id del zombie: ");
                        mover_zombie_escuadron_zombie(lista_de_zombies, escuadron_zombies, verificar_id_zombie);
                    }
                    else
                    {
                        cout << "No se encontro el escuadron" << endl;
                    }

                    break;
                case 0:
                    gestion = false;
                    break;
                
                default:
                    cout << "Introduce una opcion valida" << endl;
                    break;
                }
            } while (gestion);
            gestion = true;
            
            
            break;

        case 4:
            do
            {
                system("cls");
                cout << "Aqui se VEN ESCUADRONES" << endl;
                cout << "1) Ver escuadrones de soldados" << endl;
                cout << "2) Ver escuadrones de zombies" << endl;
                cout << "0) Volver" << endl;
                opcion = validar_numero("Introduce la opcion: ");

                switch (opcion)
                {
                case 1:

                    mostrar_nombre_escuadrones_soldados(lista_de_escuadrones);
                    system("PAUSE");
                                        
                    break;
                case 2:

                    mostrar_nombre_escuadrones_zombies(lista_de_escuadrones);
                    system("PAUSE");

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
        
        case 0:

            gestion = false;
        
        default:

            cout << "**Introduce una opcion correcta**" << endl;
            break;

        }
    } while (gestion);
}
