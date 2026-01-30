#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

const int N = 9;

void intercambio(int *a, int* b){
    
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutacion(int *matriz){

    for(int i=0; i<N; i++){
        *(matriz + i) = i + 1; 
    }

    for(int i=N-1; i>0; i--){
        int j = rand() % i + 1;

        intercambio((matriz + i), (matriz + j));
    }
}

void imprimir(int **matriz){

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cout<<*(*(matriz + i) + j) << " ";
        }
        cout<<endl;
    }
}

int buscarIndice(int *fila, int valor){

    for(int i=0; i<N; i++){
        if(*(fila + i) == valor){
            return i;
        }
    }

    return -1;
}

void rotar(int *fila, int valor, int colDestino){

    int colActual = buscarIndice(fila, valor);
    if(colActual == colDestino){
        return;
    }

    int dif = colActual - colDestino;
    int temp[9];

    for(int i=0; i<N; i++){
        int indOrigen = (i + dif + N) % N;
        *(temp + i) = *(fila + indOrigen);
    }

    for(int i=0; i<N; i++){
        *(fila + i) = *(temp + i);
    }
}


int main(){

    int datos[N][N];
    int* matriz[N];

    srand(time(NULL));

    for(int i=0; i<N; i++){
        *(matriz + i) = *(datos + i);

        permutacion(*(matriz + i));
    }

    cout<<"Arreglo Original: "<<endl;
    imprimir(matriz);

    int fil, col;

    cout<<"Fila inicial (1 - 9): "; 
    cin>>fil;

    cout<<"Columna inicial (1 - 9): ";
    cin>>col;

    cout<<"El valor seleccionado es "<<*(*(matriz + fil ) + col);
    int valor = *(*(matriz + fil ) + col);

    for(int i=0; i<N; i++){
        rotar(*(matriz + i), valor, col+1);
    }
    
    cout<<"Arreglo rotado";
    imprimir(matriz);


    return 0;
}
