#include<iostream>
using namespace std;

int guardarDIrecciones(char* texto, char** indice){

    int i=0;
    char* p = texto;

    while(*p != '\0'){
        int j = 0;

        if((p == texto && *p != ' ') || (*(p-1) == ' ' && *p != ' ')){
            *(indice + i) = p;
            *(*(indice + i) + j) = j;
            j++;
            i++;
        }
        p++;
        j++;
    }
    return i;
}

int comparar(const char * a, const char * b){

    int i=0;
    while((*a != ' ') && (*a != '\0') && (*b != ' ') && (*b != '\0')){
        if(*(a+i) == *(b+i)){
            
        }
    }

}

void ordenarIndice(char ** indice, int n){

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(comparar() > 0){
                swap();
            }
        }
    }
}
void imprimir(char* texto, char** indice, int n);

int main(){

    char texto[] = "Los punteros no se copian se referencian y se ordenan";
    char** Indice;





}
