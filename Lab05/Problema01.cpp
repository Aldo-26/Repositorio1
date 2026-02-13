#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void llenarMatriz(int **Matriz, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            *(*(Matriz + i) + j) = rand() % 10;
        }
    }
}

int** matrizValida(int **Matriz, int n, int m, int &n_nueva){
    
    int cont = 0;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<m; j++){
            sum += *(*(Matriz + i) + j);
        }
        if(sum%2 == 0){
            cont++;
        }
    }

    n_nueva = cont;
    if(cont == 0){
        return nullptr;
    }

    int** MatrizNueva = new int*[cont];
    for(int i = 0; i<cont; i++){
        MatrizNueva[i] = new int[m];
    }

    int filaDestino = 0; 
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<m; j++){
            sum += *(*(Matriz + i) + j);
        }
        if(sum%2 == 0){
            for(int j=0; j<cont; j++){
                MatrizNueva[filaDestino][j] = Matriz[i][j];
            }
            filaDestino++;
        }
    }

    return MatrizNueva;

}

void imprimirMatriz(int **Matriz, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<*(*(Matriz + i) + j)<<" ";
        }
        cout<<endl;
    }
}

void liberarMemoria(int **Matriz, int n){
    if(!Matriz) return;

    for(int i=0; i<n; i++){
        delete []Matriz[i];
    }

    delete []Matriz;
}

int main(){

    int n = 5;
    int m = 6;

    int **Matriz = new int*[n];
    for(int i=0; i<n; i++){
        Matriz[i] = new int[m];
    }

    llenarMatriz(Matriz,n,m);
    cout<<"------Matriz Original------"<<endl;
    imprimirMatriz(Matriz,n,m);

    int n_nueva = 0;
    int** MatrizFiltrada = matrizValida(Matriz,n,m,n_nueva);

    cout<<"------Matriz Filtrada------"<<endl;
    imprimirMatriz(Matriz,n_nueva,m);

    liberarMemoria(Matriz,n);
    liberarMemoria(MatrizFiltrada,n_nueva);

    return 0;
}
