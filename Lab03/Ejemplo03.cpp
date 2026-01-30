#include<iostream>
#include<cstring>
using namespace std;

void CadenaMasLarga(const char**nombres, int n){

    int tam = 0;
    int tamMax = 0;
    const char* palabra = nullptr;
    for(const char** i = nombres; i < nombres + n; ++i){
        tam = strlen(*i);
        if(tam > tamMax){
            tamMax = tam;
            palabra = *i;
        }
    }

    cout<<"La palabra mas larga es: "<< palabra << endl;
    cout<<"Su longitud es: "<< tamMax << endl;
}

int main(){

    const char* nombres[] = {
    "Lesly",
    "Americo",
    "Xingbeck",
    "William",
    "Julio",
    "Darwin",
    "Kevin"
    };

    CadenaMasLarga(nombres,7);

    return 0;
}
