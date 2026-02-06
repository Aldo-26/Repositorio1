#include <iostream>

using namespace std;

// Función recursiva con aritmética de punteros
int costoMinimo(int *arr, int n, int pos) {
    // Caso Base: Si llegamos al final, el costo es 0
    if (pos == n) {
        return 0;
    }

    int minCosto = -1; // Usamos -1 como bandera de "no inicializado"
    int producto = 1;

    // Intentamos particionar en cada posición posible desde 'pos'
    for (int i = pos; i < n; ++i) {
        // Producto del segmento actual [pos ... i]
        producto *= *(arr + i);

        // Llamada recursiva
        int resultadoActual = producto + costoMinimo(arr, n, i + 1);

        // Si es el primer resultado que obtenemos o es menor al guardado, actualizamos
        if (minCosto == -1 || resultadoActual < minCosto) {
            minCosto = resultadoActual;
        }
    }

    return minCosto;
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(*(arr));

    cout << "Arreglo: [1, 2, 3]" << endl;
    cout << "Costo minimo de particion: " << costoMinimo(arr, n, 0) << endl;

    return 0;
}
