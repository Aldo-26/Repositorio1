#include<iostream>
using namespace std;

int main(){

    float y = 23.5;
    float* pf = &y;

    cout<<"EL valor de y es: "<<y<<endl;
    cout<<"La direccion de y es: "<<pf<<endl;
    cout<<"El puntero de pf apunta a: "<<*pf<<endl;

    char ch='A';
    char* pch = &ch;

    cout<<"El valor de ch es: "<<ch<<endl;
    cout<<"La direccion de ch es: "<<(void*)pch<<endl;  //void* se usa en caso de char, para que te muestre el puntero

    int arr[] = {1,2,3};
    cout<<arr<<endl;  //el nombre es un puntero 
    cout<<&arr[0]<<endl;

    return 0;
}