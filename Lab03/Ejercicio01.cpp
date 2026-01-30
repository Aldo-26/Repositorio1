#include<iostream>
using namespace std;

int separar_palabras(char* texto, char* palabras[]);
int longitud_palabra(const char* p);
void clasificar(char* palabras[], int n, char* cortas[], int& nc, char* largas[], int& nl);
int comparar_palabras(const char* a, const char* b);
void ordenar(char* v[], int n);
void imprimir_grupo(const char* titulo, char* v[], int n);

int main(){

    char texto[300] = "Programar en C++ requiere logica C++ exige disciplina";
    char* palabras[60];
    char* cortas[60];
    char* largas[60];

    return 0;
}

int separar_palabras(char* texto, char* palabras[]){

    int i=0;
    char* p = texto;

    while(*p != '\0'){
        if((p == texto && *p != ' ') ||(*(p-1) == ' ' && *p != ' ')){
            *(palabras + i) = p;
            i++;
        }
        p++;
    } 
    return i;
}

int longitud_palabra(const char* p){

    int tam=0;
    while(*p != '\0' && *p != ' '){
        tam++;
        p++;
    }

    return tam;
}

void clasificar(char* palabras[], int n, char* cortas[], int& nc, char* largas[], int& nl){

    int ic = 0;
    int il = 0;
    
    for(int i=0; i<n; i++){
        int longitud = longitud_palabra(*(palabras + i));
        if(longitud <=3){
            *(cortas + ic) = *(palabras + i);
            ic++;
            nc++;
        }else{
            *(largas + il) = *(palabras + i);
            il++;
            nl++;
        }
    }
}

int comparar_palabras(const char* a, const char* b){

    int i=0;

    while(*(a+i) != ' ' && *(a+i) != '\0' && *(b+i) != ' ' && *(b+i) != '\0'){
        if(*(a+i) != *(b+i)){
            return *a - *b;
        }
    }

    if((*(a+i) == ' ' || *(a+i) == '\0') && (*(b+i) == ' ' || *(b+i) == '\0')){
        return 0;
    }

    if(*(b+i) == ' ' || *(b+i) == '\0'){
        return -1;
    }
}

void ordenar(char* v[], int n){

    for(char **i = v; i < v + n; i++){
        for(char **j = i + 1; j < v + n; j++){
            if(comparar_palabras(*i, *j)){
                swap(*i,*j);
            }
        }
    }
}

void imprimir_grupo(const char* titulo, char* v[], int n){

    for(int i=0; i<n; i++){
        char *p = *(v+i);

        while(*p != ' ' && *p != '\0'){
            cout << *p;
            p++;
        }
        cout<<endl;
    }
}
