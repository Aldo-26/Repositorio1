#include<iostream>
#include<cstring>

using namespace std; 

int separar_palabras(char* texto, char* palabras[]){

    int i = 0;
    char* p = texto;

    while(*texto != '\0'){
        if((p == texto && *p != ' ') || (*(p-1) == ' ' && *p != ' ')){
            *(palabras + i) = p;
            i++;
        }
        p++;
    }

    return i;
}

void imprimir(char *palabra, int n){
    
    for(int i=0; i<n; i++){
        cout<<*(palabra + i);

        while(*palabra != '0'){
            palabra++;
        }
    }
}

int contar(char* palabra[], int n){

    int cont = 0;
    char **p = palabra;

    for(int i=0; i<n; i++){

        if(**p== 'A' || **p == 'a' || **p == 'E' || **p == 'e' || **p == 'I' || **p == 'i' || **p == 'O' || **p == 'o' || **p == 'U' || **p == 'u'){
            cont++;
        }
        p++;
    }
    return cont;
}

int main(){

    char texto[] = "Este es un  ejemplo en c++   END";
    char* palabras[10];

    int n = separar_palabras(texto, palabras); 
    
    imprimir(texto,n);

    cout<<contar(palabras, n);

}
