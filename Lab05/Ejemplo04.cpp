#include <iostream>
#include <string>

using namespace std;

// --- ABSTRACCIÓN: Definición del modelo de datos ---
struct Proceso {
    int id;
    string nombre;
    int memoria;
    Proceso* siguiente; // Puntero al siguiente nodo
};

// --- ENCAPSULACIÓN: Control de la estructura de datos ---
struct ListaProcesos {
    Proceso* cabeza;

    // b) Inicializar la lista
    ListaProcesos() {
        cabeza = nullptr;
    }
};

// --- RESPONSABILIDAD ÚNICA: Funciones de manipulación ---

// Función auxiliar para crear un nodo
Proceso* crearProceso(int id, string nombre, int memoria) {
    Proceso* nuevo = new Proceso();
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->memoria = memoria;
    nuevo->siguiente = nullptr;
    return nuevo;
}

// Insertar al inicio
void insertarInicio(ListaProcesos& lista, int id, string nombre, int memoria) {
    Proceso* nuevo = crearProceso(id, nombre, memoria);
    nuevo->siguiente = lista.cabeza;
    lista.cabeza = nuevo;
}

// Insertar al final
void insertarFinal(ListaProcesos& lista, int id, string nombre, int memoria) {
    Proceso* nuevo = crearProceso(id, nombre, memoria);
    if (!lista.cabeza) {
        lista.cabeza = nuevo;
        return;
    }
    Proceso* temp = lista.cabeza;
    while (temp->siguiente) temp = temp->siguiente;
    temp->siguiente = nuevo;
}

// Insertar ordenado por consumo de memoria (Ascendente)
void insertarOrdenado(ListaProcesos& lista, int id, string nombre, int memoria) {
    Proceso* nuevo = crearProceso(id, nombre, memoria);
    if (!lista.cabeza || lista.cabeza->memoria >= memoria) {
        nuevo->siguiente = lista.cabeza;
        lista.cabeza = nuevo;
        return;
    }
    Proceso* actual = lista.cabeza;
    while (actual->siguiente && actual->siguiente->memoria < memoria) {
        actual = actual->siguiente;
    }
    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
}

// Mostrar lista
void mostrarLista(ListaProcesos lista) {
    Proceso* temp = lista.cabeza;
    cout << "\n--- ESTADO DEL SISTEMA DISTRIBUIDO ---" << endl;
    while (temp) {
        cout << "[ID: " << temp->id << " | " << temp->nombre << " | " << temp->memoria << " MB] -> ";
        temp = temp->siguiente;
    }
    cout << "NULL" << endl;
}

// Buscar por ID
void buscarProceso(ListaProcesos lista, int id) {
    Proceso* temp = lista.cabeza;
    while (temp) {
        if (temp->id == id) {
            cout << "Proceso " << id << " encontrado: " << temp->nombre << endl;
            return;
        }
        temp = temp->siguiente;
    }
    cout << "Proceso con ID " << id << " no existe en el sistema." << endl;
}

// Eliminar por ID (Cubre cabeza, intermedio, final y no existente)
void eliminarProceso(ListaProcesos& lista, int id) {
    if (!lista.cabeza) return;

    Proceso* temp = lista.cabeza;
    Proceso* anterior = nullptr;

    // Caso 1: Es la cabeza
    if (temp->id == id) {
        lista.cabeza = temp->siguiente;
        delete temp;
        cout << "ID " << id << " eliminado (Cabeza)." << endl;
        return;
    }

    // Caso 2 y 3: Intermedio o Final
    while (temp && temp->id != id) {
        anterior = temp;
        temp = temp->siguiente;
    }

    if (!temp) {
        cout << "Error: El ID " << id << " no fue encontrado para eliminar." << endl;
        return;
    }

    anterior->siguiente = temp->siguiente;
    delete temp;
    cout << "ID " << id << " eliminado del sistema." << endl;
}

// Contar procesos
int contarProcesos(ListaProcesos lista) {
    int contador = 0;
    Proceso* temp = lista.cabeza;
    while (temp) {
        contador++;
        temp = temp->siguiente;
    }
    return contador;
}

// Liberar memoria
void liberarMemoria(ListaProcesos& lista) {
    while (lista.cabeza) {
        Proceso* temp = lista.cabeza;
        lista.cabeza = lista.cabeza->siguiente;
        delete temp;
    }
    cout << "Memoria liberada exitosamente." << endl;
}

// --- PROGRAMA PRINCIPAL ---
int main() {
    ListaProcesos miSistema;

    // Insertar 3 al inicio
    insertarInicio(miSistema, 10, "Kernel", 128);
    insertarInicio(miSistema, 5, "Driver_Wifi", 64);
    insertarInicio(miSistema, 1, "Init", 32);

    // Insertar 2 al final
    insertarFinal(miSistema, 20, "Browser", 512);
    insertarFinal(miSistema, 25, "Database", 1024);

    mostrarLista(miSistema);
    cout << "Total procesos: " << contarProcesos(miSistema) << endl;

    // Búsqueda
    buscarProceso(miSistema, 20);
    
    // Eliminación
    eliminarProceso(miSistema, 1);   // Cabeza
    eliminarProceso(miSistema, 20);  // Intermedio
    eliminarProceso(miSistema, 99);  // No existe

    // Inserción ordenada por memoria
    cout << "\nInsertando proceso ordenado (75 MB)..." << endl;
    insertarOrdenado(miSistema, 15, "Logger", 75);

    mostrarLista(miSistema);
    
    // Finalización
    liberarMemoria(miSistema);

    return 0;
}
