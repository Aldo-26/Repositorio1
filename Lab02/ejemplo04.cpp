#include <iostream>
using namespace std;

void imprimir(const int* inicio, const int* fin);
int* buscarPrimerNegativo(int* inicio, int* fin);
int* subarregloMaximoInicio(int* inicio, int* fin);
void invertir(int* inicio, int* fin);

int main(){

    int datos[] = {3, -2, 5, 7, -4, 10, -6, 1};
    int n = sizeof(datos)/sizeof(datos[0]);
    
    int *inicio = datos;
    int *fin = datos + n;

    imprimir(inicio, fin);
    cout<< *buscarPrimerNegativo(inicio, fin)<<endl;

    int* f1=subarregloMaximoInicio(inicio,fin);
    imprimir(inicio, f1);

    invertir(inicio, fin);    
    imprimir(inicio, fin);


    return 0;
}

void imprimir(const int* inicio, const int* fin){

    for(const int*p = inicio; p < fin; p++){
        cout<< *p << " ";
    }
    cout<<endl;
}

int* buscarPrimerNegativo(int* inicio, int* fin){
    
    for(int *p = inicio; p < fin; ++p){
        if(*p < 0){
            return p;
        }
    }
    return fin;
}

int* subarregloMaximoInicio(int* inicio, int* fin){

    int ultimasuma = 0;
    int  maxsuma = *inicio;
    int *finMax = inicio + 1;

    for(int*p = inicio; p<fin; ++p){
        ultimasuma += *p;
        if(ultimasuma > maxsuma){
            maxsuma =  ultimasuma;
            finMax = p + 1;
        }
    }
    return finMax;

}

void invertir(int* inicio, int* fin){
    int* pi = inicio;
    int* pf = fin - 1;
    while(pi < pf){
        int temp = *pi;
        *pi = *pf; 
        *pf = temp; 

        pi++;
        pf--;
    }
}
