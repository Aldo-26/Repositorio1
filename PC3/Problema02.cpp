#include <iostream>
#include <cstring>

using namespace std;

int separar_palabras(char* texto, char* palabras[]) {
    int i = 0;
    char* p = texto;

    while (*p != '\0') {
        // Detecta inicio de palabra
        if ((p == texto && *p != ' ') || (*(p - 1) == ' ' && *p != ' ')) {
            *(palabras + i) = p;
            i++;
        }
        // Reemplaza espacios por '\0' para delimitar palabras
        if (*p == ' ') {
            *p = '\0';
        }
        p++;
    }
    return i;
}

void imprimir(char* palabras[], int n) {
    for (int i = 0; i < n; i++) {
        char* p = *(palabras + i);
        while (*p != '\0') {
            cout << *p;
            p++;
        }
        cout << endl;
    }
}

int contar(char* palabras[], int n) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        char* p = *(palabras + i);
        char c = *p; // primera letra
        if (c == 'A' || c == 'a' || c == 'E' || c == 'e' ||
            c == 'I' || c == 'i' || c == 'O' || c == 'o' ||
            c == 'U' || c == 'u') {
            cont++;
        }
    }
    return cont;
}

int main() {
    char texto[] = "Este es un  ejemplo en c++   END";
    char* palabras[20];

    int n = separar_palabras(texto, palabras);

    cout << "Palabras encontradas:" << endl;
    imprimir(palabras, n);

    cout << "Palabras que empiezan con vocal: " << contar(palabras, n) << endl;

    return 0;
}
