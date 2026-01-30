#include<iostream>
#include<cstring>
using namespace std;

void Ordenamiento(const char** nombres, int n){

    for(const char** i = nombres; i<nombres + n; ++i){
        for(const char** j = i + 1; j < nombres + n; ++j){
            if(strcmp(*i, *j) > 0){
                const char* temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}

void imprimir(const char** nombres, int n){
    
    for(const char** i = nombres; i<nombres + n; ++i){
        cout<< *i <<endl;
    }
}

int main(){

    int n=7;
    const char* nombres[] = {
    "Lesly",
    "Americo",
    "Xingbeck",
    "William",
    "Julio",
    "Darwin",
    "Kevin"
    };

    imprimir(nombres, n);

    cout<<"Arreglo ordenado: "<<endl;
    Ordenamiento(nombres,n);
    imprimir(nombres,n);

    return 0;
}
