#include <iostream>
using namespace std;
#include "../utilities/utility_validaciones.h"


Soldado* soldado = nullptr;
Accesorio* accesorio = nullptr;
Inventario* inventario = nullptr;
Inventario* anterior_inventario = nullptr;
Accesorio* anterior_accesorio = nullptr;

//!Sale el menu desplazado por TODO EL TEXTO TnT
//*DIRIA QUE PARA FUTURAS ANOTACIONES SE PUEDE REDUCIR EL CODIGO PARA SER MAS LIMPIO Y EFECTIVO :)

void menu_inventario(bool gestion, int opcion,Soldado*Lista_Soldados, Accesorio* lista_de_accesorios,Inventario *&Lista_Inventarios)
{
    size_t id_soldado, id_accesorio;

    system("Pause");
    system("cls");
    cout << "---------Aqui se gestionan los inventarios---------" << endl << endl; //*SUBMENU DE INVENTARIO
    cout << "1) Agregar inventario" << endl;
    cout << "2) Eliminar inventario" << endl;
    cout << "3) Modificar inventario" << endl;
    cout << "4) Ver inventarios" << endl;
    cout << "0) **Salir al menu principal**" << endl << endl;
    cout << "---------------------------------------------------" << endl;

    do
    {
        opcion = validar_numero("Introduce la opcion: ");

        switch (opcion)
        {
        case 1:
            cout << "Soldados disponibles: " << endl;
            MostrarSoldado(Lista_Soldados);
            id_soldado= validar_numero("Introduce el ID del soldado para agrear inventario: ");//*Validamos la funcion
            soldado = buscarSoldadoPorID(Lista_Soldados, id_soldado,anterior);//*Busca el id del soldado
                if (soldado == nullptr) {
                    cout << "Soldado no encontrado." << endl;
                    break;
                }
            cout<<endl;
            
            cout << "Accesorios disponibles: " << endl;//*Nos dice que pongamos el id para saber a cual soldado a agregar
            mostrar_accesorios(lista_de_accesorios);
            id_accesorio = validar_numero("Introduce el ID del accesorio para agregar al inventario: ");
            accesorio = buscar_accesorio_por_id(lista_de_accesorios, id_accesorio,anterior_accesorio);
                if (accesorio == nullptr) {
                    cout << "Accesorio no encontrado." << endl;
                    break;
                }
                cout<<endl;
                inventario = CrearInventario(soldado);
                agregarAccesorioInventario(inventario, accesorio);//*se incluye dentro de el inventario los accesorios
                cout << "Accesorio agregado al inventario del soldado." << endl;
                system("cls");
                break;
                
            case 2:
                system("Pause");
                system("cls");
                cout << "---------Aqui se eliminan los inventarios---------" << endl << endl;
                cout << "1) Eliminar todo el inventario" << endl;
                cout << "2) Eliminar un accesorio del inventario" << endl;
                cout << "0) Volver" << endl;
                cout << "---------------------------------------------------" << endl;
                opcion = validar_numero("Introduce la opcion: ");

                if (opcion == 1) {

                    cout << "Soldados disponibles: " << endl;
                    MostrarSoldado(Lista_Soldados);
                    id_soldado= validar_numero("Introduce el ID del soldado para eliminar todo el inventario: ");
                    soldado = buscarSoldadoPorID(Lista_Soldados, id_soldado,anterior);

                    if (soldado == nullptr) {
                            cout << "Soldado no encontrado." << endl;
                            break;
                    }

                    inventario = anterior_inventario; 
                    eliminarTodosAccesorios(inventario);
                    cout << "Todo el inventario del soldado ha sido eliminado." << endl;

                    system("Pause");
                    system("cls");
                } 
                else if (opcion == 2) {

                    cout << "Soldados disponibles: " << endl;
                    MostrarSoldado(Lista_Soldados);

                    cout << "Introduce el ID del soldado para eliminar un accesorio: ";
                    id_soldado=validar_numero("Introduce el ID del soldado para eliminar un accesorio: ");
                    soldado = buscarSoldadoPorID(Lista_Soldados, id_soldado,anterior);

                        if (soldado == nullptr) {
                        cout << "Soldado no encontrado." << endl;
                        break;
                        }

                    inventario = anterior_inventario; 
                    cout << "Accesorios en el inventario del soldado: " << endl;
                    mostrarInventario(inventario);

                    id_accesorio=validar_numero("Introduce el ID del accesorio para eliminar del inventario: ");
                    eliminarAccesorioInventario(inventario, id_accesorio);
                    cout << "Accesorio eliminado del inventario del soldado." << endl;
                    }
                    break;

                    case 3:
                    //*INGRESA PRIMERO POR SOLDADO PARA DESPUES SABER Q SOLDADO MODIFICAR
                    cout << "Soldados disponibles: " << endl;
                    MostrarSoldado(Lista_Soldados);
                    cout << "Introduce el ID del soldado para modificar su inventario: ";
                    id_soldado=validar_numero("Introduce el ID del soldado para modificar su inventario: ");
                    soldado = buscarSoldadoPorID(Lista_Soldados, id_soldado,anterior);

                        if (soldado == nullptr) {
                            cout << "Soldado no encontrado." << endl;
                            break;
                        }

                    inventario = anterior_inventario; // Obtén el inventario correspondiente al soldado
                    mostrarInventario(inventario);

                    //*MUESTRA MENU DE INVENTARIOS(SI FUNCIONA POR AHORA XD)
                    cout << "---------Aqui se modifican los inventarios---------" << endl << endl;
                    cout << "1) Modificar todos los accesorios" << endl;
                    cout << "2) Modificar un accesorio específico" << endl;
                    cout << "0) Volver" << endl; 
                    cout << "---------------------------------------------------" << endl;
                    opcion = validar_numero("Introduce la opcion: ");

                    if (opcion == 1) {

                        cout << "Accesorios disponibles: " << endl;
                        cout<<endl;
                        mostrar_accesorios(lista_de_accesorios);
                        id_accesorio=validar_numero("Introduce el ID del accesorio para agregar al inventario: ");
                        accesorio = buscar_accesorio_por_id(lista_de_accesorios, id_accesorio,anterior_accesorio);

                            if (accesorio == nullptr) {
                                cout << "Accesorio no encontrado." << endl;
                                break;
                            }

                        agregarAccesorioInventario(inventario, accesorio);
                        cout << "Accesorio agregado al inventario del soldado." << endl;

                    } 

                    else if (opcion == 2) {

                        cout << "Accesorios en el inventario del soldado: " << endl;
                        mostrarInventario(inventario);
                        id_accesorio=validar_numero("Introduce el ID del accesorio a modificar: ");
                        eliminarAccesorioInventario(inventario, id_accesorio);
                        cout << "Accesorio eliminado del inventario del soldado. "<<endl;

                        cout<<"Agregue un nuevo accesorio: " << endl;
                        mostrar_accesorios(lista_de_accesorios);
                        id_accesorio=validar_numero("Introduce el ID del accesorio accesorio para agregar al inventario: ");
                        accesorio = buscar_accesorio_por_id(lista_de_accesorios, id_accesorio,anterior_accesorio);

                            if (accesorio == nullptr) {
                                cout << "Accesorio no encontrado." << endl;
                                break;
                            }
                            
                        agregarAccesorioInventario(inventario, accesorio);
                        cout << "Accesorio modificado en el inventario del soldado." << endl;
                    }
                    else(opcion==0);
                    break;

                    case 4:
                    cout << "---------Aqui se eliminan los inventarios---------" << endl << endl;
                    cout << "1) Mostrar todos los inventarios" << endl;
                    cout << "2) Mostrar el inventario de un soldado específico" << endl;//!ESTA VAINA NO MUESTRA CÑSM
                    cout << "0) Volver" << endl;
                    cout << "---------------------------------------------------" << endl;
                    opcion = validar_numero("Introduce la opcion: ");
                    if (opcion == 1) {
                        Inventario* actual_inventario = inventario;
                        while (actual_inventario != nullptr) {
                            mostrarInventario(actual_inventario);
                            actual_inventario = actual_inventario->inventario_prox;
                        }
                    } else if (opcion == 2) {
                        cout << "Soldados disponibles: " << endl;
                        MostrarSoldado(Lista_Soldados);
                        cout << "Introduce el ID del soldado para ver su inventario: ";
                        id_soldado=validar_numero("Introduce el ID del soldado para ver su inventario: ");
                        soldado = buscarSoldadoPorID(Lista_Soldados, id_soldado,anterior);
                        if (soldado == nullptr) {
                            cout << "Soldado no encontrado." << endl;
                            break;
                        }
                        inventario = anterior_inventario; // Obtén el inventario correspondiente al soldado
                        mostrarInventario(inventario);
                    }
                    break;

                    case 0:
                    gestion = false;

                    default:
                    cout<<" **Introduce una opcion correcta**\n";
                    break;

        }
    } while (gestion);
}
//Todo: Hacer y llamar a la funcion segun el case