// Sistema de gestion de notas
#include <iostream>
using namespace std;


// 1.1. Solicitar al usuario el número n de estudiantes.

void leerEstudiantes(int& n) {
    cout << "Ingrese el numero de estudiantes: ";
    cin >> n;
}

// 1.2. Reservar memoria dinámica para almacenar las notas float notas[n]

float * reservarMemoria(int n) {
    return new float[n]; 

}


// 1.3. Leer las notas desde el teclado

void leerNotas(float * notas, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Ingrese la nota " << i + 1 << ": ";
        cin >> notas[i];
    }
}

// 1.4. Calcular: Promedio del curso
float calculoPromedio(float *notas, int n ) {
    float suma = 0;
    for (int i = 0; i < n; ++i) {
        suma += notas[i];
    }
    return suma/n;
}

// Nota máxima y mínima

void calculoMinMax(float * notas, int n, float & maxi, float & mini) {
    mini = notas[0];
    maxi = notas[0]; 
    for (int i = 0; i < n; ++i) {
        if (notas[i] > maxi)
            maxi = notas[i];

        if (notas[i] < mini)
            mini = notas[i];
        
    }
}


// 1.5. Redimensionar dinámicamente el arreglo para agregar k estudiantes.

void redimensionar(float * &notas, int &n, int k) {
    // asignar memoria dinamica de tamanio n + k
   float * nuevo = new float[n + k];

   //Copiar los valores antiguos
   for (int i = 0; i < n; ++i) {
        nuevo[i] = notas[i];
   }

   // actualizar notas (puntero) y n
   delete [] notas;
   notas = nuevo; // perdemos referencia al bloque antiguo
   n += k;
}


// 1.8. Liberar correctamente la memoria

void liberarMemoria(float *& notas) {
    delete [] notas;
    notas = nullptr;
}





int main(){

    int n;

    float*  notas = nullptr;

    leerEstudiantes(n);
    notas = reservarMemoria(n);
    leerNotas(notas, n);

    cout << "Promedio inicial: " << calculoPromedio(notas, n) <<endl; 

    float maxi, mini;
    calculoMinMax(notas, n, maxi, mini);

    //------------- 
    int k;
    cout << "Ingrese la cantidad de estudiante a agregar: ";
    cin >> k;

    redimensionar(notas, n, k);

    leerNotas(notas +  n - k, k);


    cout << "Promedio final: " << calculoPromedio(notas, n) <<endl; 

    calculoMinMax(notas, n, maxi, mini);

    cout << "Nota minima: " << mini << " Nota maxima: " << maxi <<endl;

    liberarMemoria(notas);

    return 0;
}
