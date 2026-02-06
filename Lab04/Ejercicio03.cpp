#include<iostream>
#include<cstring>

using namespace std;

// 1. Prototipos de funciones (Declaraciones)
void Minuscula(char* p, int n);
void Ordenar(char* p, int n);
void intercambio(char* p1, char *p2);
bool anagrama(char* p1, char* p2, int n1, int n2);

int main(){

    // 2. Usar char[] para que el texto sea modificable
    char p1[] = "Amor"; 
    char p2[] = "Ramo";

    int n1 = strlen(p1);
    int n2 = strlen(p2);

    // 3. Llamar a la función correctamente pasando los argumentos
    if(anagrama(p1, p2, n1, n2)){
        cout << "Es anagrama" << endl;
    } else {
        cout << "No es anagrama" << endl;
    }

    return 0;
}

bool anagrama(char* p1, char* p2, int n1, int n2){

    if(n1 != n2){
        return false;
    }

    // Convertimos a minúsculas y ordenamos los arreglos originales
    Minuscula(p1, n1);
    Minuscula(p2, n2);

    Ordenar(p1, n1);
    Ordenar(p2, n2);

    for(int i=0; i<n1; i++){
        // Si encontramos una diferencia, retornamos false inmediatamente
        if(*(p1 + i) != *(p2 + i)){
            return false;
        }
    }
    
    // 4. El return true va FUERA del for (si pasó todo el ciclo, son iguales)
    return true;
}

void Minuscula(char* p, int n){
    // Usamos aritmética de punteros en el índice
    for(int i=0; i<n; i++){
        // *(p + i) accede al caracter en la posición i
        if( *(p + i) <= 'Z' && *(p + i) >= 'A'){
            *(p + i) = *(p + i) + 32;
        }
    }
}

void Ordenar(char* p, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            // Comparar elemento actual con el siguiente
            if(*(p + j) > *(p + j + 1)){
                intercambio((p + j), (p + j + 1));
            }
        }
    }
}

void intercambio(char* p1, char *p2){
    char temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
