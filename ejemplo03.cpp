#include<iostream>
using namespace std;

void imprimir(int* arr, int n);
void duplicarArreglo(int *arr, int n);
void invertir(int *arr, int n);

int main(){
    int arr[5] = {1,2,3,4,5};
    int *p = arr;

    imprimir(arr,5);
    duplicarArreglo(arr,5);
    imprimir(arr, 5);
    invertir(arr,5);
    imprimir(arr,5);

    return 0;
}


void duplicarArreglo(int *arr, int n){

    for(int i=0; i<5; i++){
        *(arr+i) = *(arr+i)*2;
    }
}


void invertir(int *arr, int n){
    int* inicio = arr;
    int *fin = arr + n - 1;
    while (inicio < fin){
        swap(*inicio, *fin);
        inicio++;
        fin--;
    }
}


void imprimir(int* arr, int n){

    for(int i=0; i<n; i++){
        cout<<*(arr + i)<<" ";
    }
    cout<<endl;
}