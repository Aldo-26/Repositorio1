#include <iostream>

using namespace std;

const int N = 5;

// 1. Fila Dominante
bool esFilaDominante(int (*M)[N], int fila) {
    for (int c = 0; c < N; c++) {
        int valorActual = *(*(M + fila) + c);
        for (int r = 0; r < N; r++) {
            if (r == fila) continue;
            // Comparación estricta usando aritmética de punteros
            if (valorActual <= *(*(M + r) + c)) {
                return false;
            }
        }
    }
    return true;
}

// 2. Columnas Críticas (Sin usar <climits>)
int contarColumnasCriticas(int (*M)[N]) {
    // Calculamos la suma de la primera fila para inicializar el máximo
    int maxSumaFila = 0;
    for (int c = 0; c < N; c++) {
        maxSumaFila += *(*(M + 0) + c);
    }

    // Buscamos el máximo real comparando con las filas restantes
    for (int r = 1; r < N; r++) {
        int sumaF = 0;
        for (int c = 0; c < N; c++) {
            sumaF += *(*(M + r) + c);
        }
        if (sumaF > maxSumaFila) {
            maxSumaFila = sumaF;
        }
    }

    // Contamos las columnas críticas
    int criticas = 0;
    for (int c = 0; c < N; c++) {
        int sumaC = 0;
        for (int r = 0; r < N; r++) {
            sumaC += *(*(M + r) + c);
        }
        if (sumaC > maxSumaFila) {
            criticas++;
        }
    }
    return criticas;
}

// 3. Matriz Escalonada
bool esMatrizEscalonada(int (*M)[N]) {
    int posAnterior = -1;

    for (int r = 0; r < N; r++) {
        int posActual = -1;
        for (int c = 0; c < N; c++) {
            if (*(*(M + r) + c) != 0) {
                posActual = c;
                break;
            }
        }

        if (posActual != -1) {
            if (posActual <= posAnterior) return false;
        } else {
            // Manejo de filas nulas: deben estar al final
            posActual = N + r; 
            if (posActual <= posAnterior) return false;
        }
        posAnterior = posActual;
    }
    return true;
}

// 4. Valor Núcleo (Punto de silla)
int valorNucleo(int (*M)[N]) {
    for (int r = 0; r < N; r++) {
        // Inicializamos con el primer elemento de la fila actual
        int maxFila = *(*(M + r) + 0);
        int colMax = 0;

        for (int c = 1; c < N; c++) {
            if (*(*(M + r) + c) > maxFila) {
                maxFila = *(*(M + r) + c);
                colMax = c;
            }
        }

        bool esMinCol = true;
        for (int i = 0; i < N; i++) {
            if (*(*(M + i) + colMax) < maxFila) {
                esMinCol = false;
                break;
            }
        }

        if (esMinCol) return maxFila;
    }
    return -1;
}

int main() {
    int M[N][N] = {
        {10, 20, 30, 40, 50},
        {5,  15, 25, 35, 45},
        {2,  8,  12, 18, 22},
        {1,  4,  6,  9,  11},
        {0,  2,  3,  5,  7}
    };

    cout << "Columnas criticas: " << contarColumnasCriticas(M) << endl;
    
    int nucleo = valorNucleo(M);
    if (nucleo != -1) cout << "Valor nucleo encontrado: " << nucleo << endl;
    else cout << "No existe valor nucleo." << endl;

    return 0;
}
