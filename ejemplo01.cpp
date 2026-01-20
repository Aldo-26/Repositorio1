#include <iostream>
using namespace std;

int main() {
    int a = 42;  // Variable en la memoria stack
    int* ptr = &a; // ptr guarda la dirección de a

    cout << "Valor de a: " << a << endl;
    cout << "Dirección de a: " << &a << endl;
    cout << "Valor desde el puntero: " << *ptr << endl;


    char mensaje[] = "Hola Mundo";
    char* pm = mensaje;  //el nombre del arreglo es un puntero mensaje[0]

    while (*pm != '\0') {
    cout << *pm;
    pm++;
    }

    cout << endl;
    return 0;
}