#include<iostream>
using namespace std;

int separar_palabras(char* frase, char* palabras[]);
int comparar(const char* a, const char* b);
void ordenar(char* palabras[], int n);
void imprimir(char* palabras[], int n);

int main(){
    
    char frase[200] = "aprender punteros exige mucha logica y practica";      // arreglo base de caracteres
    char* palabras[50];  // arreglo de punteros a palabras
    
    int n = separar_palabras(frase, palabras);
    ordenar(palabras, n);
    imprimir(palabras, n);

    return 0;
}

int separar_palabras(char* frase, char* palabras[]){

    int i=0;
    char* f = frase;

    while(*f != '\0'){
        
        if((f == frase && *f != ' ') || (*(f-1) == ' ' && *f != ' ')){
            *(palabras+i) = f;
            i++;
        }
        f++;
    }
    return i;
}

int comparar(const char* a, const char* b){

    int i=0; 

    while(*(a+i) != '\0' && *(a+i) != ' ' && *(b+i) != '\0' && *(b+i) != ' '){
        if(*(a+i) != *(b+i)){
            return *(a+i) - *(b+i);
        }
        i++;
    }

    if((*(a+i) == ' ' || *(a+i) == '\0') && ((*(b+i) == ' ' || *(b+i) == '\0'))){
        return 0;
    }

    if (a[i] == ' ' || a[i] == '\0') {
        return 1;
    }

    if((*(b+i) == ' ' || *(b+i) == '\0')){
        return -1;
    }
    return 0;
}

void ordenar(char* palabras[], int n){

    for(char **i = palabras; i < palabras + n; i++){
        for(char **j = i + 1; j < palabras + n; j++){
            if(comparar(*i, *j) > 0){
                swap(*i, *j);
            }
        }
    }
}

void imprimir(char* palabras[], int n){

    for(int i=0; i<n; i++){
        char *p = *(palabras + i); 

        while(*p != ' ' && *p != '\0'){
            cout<< *p;
            p++;
        }
        cout<<endl;
    }
}

