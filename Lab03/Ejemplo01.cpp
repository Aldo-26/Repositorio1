#include<iostream>
#include<cstring>
using namespace std;

void Ordenamiento(char (*nombres)[20], int n){
    
    char temp[30];
    for(char (*i)[20] = nombres; i<nombres + n - 1; ++i){
        for(char (*j)[20] = i + 1; j<nombres + n; ++j){
            if(strcmp(*i,*j) > 0){
                strcpy(temp,*i);
                strcpy(*i,*j);
                strcpy(*j,temp);
            }
        }
    }
}

void imprimir(char(*nombres)[20], int n){
    for(char (*i)[20] = nombres; i<nombres + n - 1; ++i){
        cout<< *i <<endl;
    }
}

int main(){

    char nombres[][20] = {
    "Lesly",
    "Americo",
    "Xingbeck",
    "William",
    "Julio",
    "Darwin",
    "Kevin"
    };

    int n = sizeof(nombres)/sizeof(nombres[0]);

    imprimir(nombres,n);

    cout<<"Arreglo ordenado : "<<endl;
    Ordenamiento(nombres,n);
    imprimir(nombres,n);

    return 0;
}
