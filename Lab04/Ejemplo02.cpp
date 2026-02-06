#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 2.1 Reservar memoria dinámica
int** reservarMemoria(int n, int m) {
    int** matriz = new int*[n];
    for (int i = 0; i < n; i++) {
        *(matriz + i) = new int[m];
    }
    return matriz;
}

// 2.2 Llenar con valores aleatorios (incluyendo negativos para probar validación)
void llenarAleatorio(int** M, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(*(M + i) + j) = rand() % 21 - 10; // Valores entre -10 y 10
        }
    }
}

// Función auxiliar para imprimir matrices
void imprimirMatriz(int** M, int n, int m) {
    if (n == 0 || m == 0) {
        cout << "[ Matriz vacia ]" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << *(*(M + i) + j) << "\t";
        }
        cout << endl;
    }
}

// 2.3 y 2.4 Detección y Construcción de nueva matriz
int** filtrarMatriz(int** M, int& n, int& m) {
    bool* filaValida = new bool[n];
    bool* colValida = new bool[m];
    int nNueva = 0, mNueva = 0;

    // Validar Filas (Suma par)
    for (int i = 0; i < n; i++) {
        int suma = 0;
        for (int j = 0; j < m; j++) {
            suma += *(*(M + i) + j);
        }
        *(filaValida + i) = (suma % 2 == 0);
        if (*(filaValida + i)) nNueva++;
    }

    // Validar Columnas (Máximo positivo)
    for (int j = 0; j < m; j++) {
        int maxCol = *(*(M + 0) + j);
        for (int i = 1; i < n; i++) {
            if (*(*(M + i) + j) > maxCol) maxCol = *(*(M + i) + j);
        }
        *(colValida + j) = (maxCol > 0);
        if (*(colValida + j)) mNueva++;
    }

    // Construir nueva matriz
    int** nuevaM = reservarMemoria(nNueva, mNueva);
    int rNueva = 0;
    for (int i = 0; i < n; i++) {
        if (*(filaValida + i)) {
            int cNueva = 0;
            for (int j = 0; j < m; j++) {
                if (*(colValida + j)) {
                    *(*(nuevaM + rNueva) + cNueva) = *(*(M + i) + j);
                    cNueva++;
                }
            }
            rNueva++;
        }
    }

    // Actualizar dimensiones por referencia y limpiar auxiliares
    n = nNueva;
    m = mNueva;
    delete[] filaValida;
    delete[] colValida;

    return nuevaM;
}

void liberarMemoria(int** M, int n) {
    for (int i = 0; i < n; i++) delete[] *(M + i);
    delete[] M;
}

int main() {
    srand(time(0));
    int n = 4, m = 4;

    int** matriz = reservarMemoria(n, m);
    llenarAleatorio(matriz, n, m);

    cout << "--- MATRIZ ORIGINAL (" << n << "x" << m << ") ---" << endl;
    imprimirMatriz(matriz, n, m);

    int** matrizFiltrada = filtrarMatriz(matriz, n, m);

    cout << "\n--- MATRIZ FILTRADA (" << n << "x" << m << ") ---" << endl;
    imprimirMatriz(matrizFiltrada, n, m);

    liberarMemoria(matriz, 4); // El 'n' original era 4
    liberarMemoria(matrizFiltrada, n);

    return 0;
}
