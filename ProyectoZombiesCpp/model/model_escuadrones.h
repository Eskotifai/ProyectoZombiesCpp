//*------------------Gestion de Escuadrones------------------

Escuadrones* crear_escuadron_zombie(string nombre_escuadron_zombie)
{
    Escuadrones* nuevo_escuadron_zombie = new Escuadrones;
    nuevo_escuadron_zombie-> nombre_escuadron_zombie = nombre_escuadron_zombie;
    nuevo_escuadron_zombie -> zombies_escuadron = nullptr;

    return nuevo_escuadron_zombie;

}

Escuadrones* crear_escuadron_soldados(string nombre_escuadron_soldados)
{
    Escuadrones* nuevo_escuadron_soldado = new Escuadrones;
    nuevo_escuadron_soldado -> nombre_escuadron_soldados = nombre_escuadron_soldados;
    nuevo_escuadron_soldado -> soldados_escuadron = nullptr;

    return nuevo_escuadron_soldado;
}

void agregar_escuadron_zombie(Escuadrones*& lista_de_escuadrones, Escuadrones* nuevo_escuadron_zombie)
{
    if (lista_de_escuadrones == nullptr)
    {
        lista_de_escuadrones = nuevo_escuadron_zombie;
    }
    else
    {
        Escuadrones* actual = lista_de_escuadrones;
    while (actual -> siguiente_escuadron != nullptr)
        {
            actual = actual -> siguiente_escuadron;
        }
        actual->siguiente_escuadron = nuevo_escuadron_zombie;
    }
    nuevo_escuadron_zombie -> siguiente_escuadron = nullptr;
    
}

void agregar_escuadron_soldados(Escuadrones*& lista_de_escuadrones, Escuadrones* nuevo_escuadron_soldados)
{
    if (lista_de_escuadrones == nullptr)
    {
        lista_de_escuadrones = nuevo_escuadron_soldados;
    }
    else
    {
        Escuadrones* actual = lista_de_escuadrones;
    while (actual -> siguiente_escuadron != nullptr)
        {
            actual = actual -> siguiente_escuadron;
        }
        actual->siguiente_escuadron = nuevo_escuadron_soldados;
    }
    nuevo_escuadron_soldados -> siguiente_escuadron = nullptr;
    
}

void mostrar_nombre_escuadrones_soldados(Escuadrones* lista_de_escuadrones)
{   
    Escuadrones* actual = lista_de_escuadrones;
    if (actual != nullptr)
    {
        while (actual != nullptr)
        {
            if (!actual->nombre_escuadron_soldados.empty()) //*ignora los escuadrones zombies
            {
                cout << "Escuadron de Soldados: " << actual -> nombre_escuadron_soldados << endl; 
                MostrarSoldado(actual -> soldados_escuadron);               
            }
            actual = actual -> siguiente_escuadron;           
        }
    }
    else
    {
        cout << "Escuadrones de soldados vacios" << endl;
    }
           
}

void mostrar_nombre_escuadrones_zombies(Escuadrones* lista_de_escuadrones)
{   
    Escuadrones* actual = lista_de_escuadrones;
    if (actual != nullptr)
    {
        while (actual != nullptr)
        {
            if (!actual->nombre_escuadron_zombie.empty()) //*ignora los escuadrones de soldados
            {
                cout << "Escuadron de Zombies: " << actual -> nombre_escuadron_zombie << endl;  
                mostrar_zombies(actual -> zombies_escuadron);           
            }
            actual = actual -> siguiente_escuadron;
        }
    }
    else
    {
        cout << "Escuadrones de Zombies vacios" << endl;
    }
           
}

Escuadrones* buscar_escuadron_soldados(Escuadrones*& lista, string& nombre, Escuadrones*& anterior)
{
    Escuadrones* actual = lista;
    anterior = nullptr;

    while (actual != nullptr && actual -> nombre_escuadron_soldados != nombre)
    {
        anterior = actual;
        actual = actual -> siguiente_escuadron;
    }
    return actual;
    
}

Escuadrones* buscar_escuadron_zombies(Escuadrones*& lista, string& nombre, Escuadrones*& anterior)
{
    Escuadrones* actual = lista;
    anterior = nullptr;

    while (actual != nullptr && actual -> nombre_escuadron_zombie != nombre)
    {
        anterior = actual;
        actual = actual -> siguiente_escuadron;
    }
    return actual;
    
}

void eliminar_todos_escuadron_zombie(Escuadrones* lista_de_escuadrones)
{
    Escuadrones* actual = lista_de_escuadrones;
    while (actual != nullptr)
    {
        if (!actual->nombre_escuadron_zombie.empty()) //*ignora los escuadrones de soldados
        {
            eliminar_todos_los_zombies(actual -> zombies_escuadron);
        }
        actual = actual -> siguiente_escuadron;
    }
    
}

void eliminar_un_zombie_escuadron(Escuadrones* lista_de_escuadrones, size_t id, string nombre)
{
    Escuadrones* anterior = nullptr;
    Escuadrones* escuadron = buscar_escuadron_zombies(lista_de_escuadrones, nombre, anterior);
    if (escuadron != nullptr)
    {
        buscar_y_eliminar_zombie(escuadron ->zombies_escuadron, id);
    }
    else
    {
        cout << "Zombie no encontrado" << endl;
    }
}

void eliminar_todos_zombies_un_escuadron(Escuadrones* lista_de_escuadrones, string nombre)
{
    Escuadrones* anterior = nullptr;
    Escuadrones* escuadron = buscar_escuadron_zombies(lista_de_escuadrones, nombre, anterior);
    if (escuadron != nullptr)
    {
        eliminar_todos_los_zombies(escuadron ->zombies_escuadron);
    }
    else
    {
        cout << "Escuadron no encontrado" << endl;
    }
}


