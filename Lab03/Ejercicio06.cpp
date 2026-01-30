#include<iostream>
#include<cstring>

using namespace std;

void Minuscula(char* p, int n);
void Ordenar(char* p, int n);
void intercambio(char* p1, char *p2);
bool anagrama(char* p1, char* p2, int n1, int n2);

int main(){

    char p1[] = "Amor"; 
    char p2[] = "Ramo";

    int n1 = strlen(p1);
    int n2 = strlen(p2);

    if(anagrama(p1, p2 ,n1 ,n2)){
        cout<< "Es anagrama ";
    }else{
        cout<<"No es anagrama";
    }

    return 0;
}

bool anagrama(char* p1, char* p2, int n1, int n2){

    if(n1 != n2){
        return false;
    }

    Minuscula(p1,n1);
    Minuscula(p2,n2);

    Ordenar(p1,n1);
    Ordenar(p2,n2);

    for(int i=0; i<n1; i++){
        if(*(p1 + i) != *(p2 + i)){
            return false;
        }
    }
        return true;
}

void Minuscula(char*p, int n){

    for(int i=0; i<n; i++){
        if( *(p+i) <= 'Z' && *(p+i) >= 'A'){
            *(p+i) = *(p+i) + 32;
        }
    }

}

void Ordenar(char* p, int n){
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(*(p + j) > *(p + j + 1)){
                intercambio((p + j),(p + j + 1));
            }
        }
    }

}

void intercambio(char* p1, char *p2){
    
    char temp = *p1;
    *p1 = *p2;
    *p2 = temp;

}
