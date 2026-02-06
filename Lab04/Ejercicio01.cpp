#include<iostream>
#include<cstring>
#include <cctype> // tolower()

using namespace std;

char* leerFrase(){
    char temp[1000];

    cout<<"Ingrese la frase: ";
    cin.getline(temp,1000);

    int len = strlen(temp);
    char *frase = new char[len + 1];

    strcpy(frase,temp);

    return frase;
}

char* normalizarFrase(char* frase){
    char temp[100];
    int i = 0;
    int j = 0;

    while(frase[i] != '\0'){

        if(!isspace(frase[i])){
            temp[j] = tolower(frase[i]);
            j++;
        }else{
            temp[j] = ' ';
            j++;
        }
        i++;
    }

    temp[j] = '\0';

    char *normalizado = new char[j + 1];
    strcpy(normalizado,temp);

    return normalizado;

}

int contarPalabras(char *frase){
    int cont = 0;
    bool estoyPalabra = false;
 
    for(int i = 0; frase[i] != '\0'; i++){

        if(!isspace(frase[i]) && !estoyPalabra){
            cont++;
            estoyPalabra = true;
        }
        if(isspace(frase[i])){
            estoyPalabra = false;
        }
    }
    return cont;
}

char ** separarPalabras(char* frase, int n){

    char ** palabras = new char*[n];

    int i = 0;
    int j = 0;

    while(frase[i] != '\0'){
        while(isspace(frase[i])){
            i++;
        }

        int inicio = i;
        int len = 0;

        while(frase[i] != '\0' && !isspace(frase[i])){
            i++;
            len++;
        }

        palabras[j] = new char[len + 1];

        for(int k = 0; k < len; k++){
            palabras[j][k] = frase[inicio + k];
        }
        palabras[j][len] = '\0';

        j++;
    }

    return palabras;
}

void mostrarPalabras(char** palabras, int n) {
    for (int i = 0; i < n; ++i) {
        cout << palabras[i] << "\t" << strlen(palabras[i]) <<endl;
    } 

}

void liberarMemoria(char** palabras, int n) {
    for (int i = 0; i < n; ++i){
        delete [] palabras[i];
    }
    delete [] palabras;
}


int main(){
    char *frase = leerFrase(); // debo liberar memoria

    char *normalizada = normalizarFrase(frase); // debo liberar memoria

    int numPal = contarPalabras(frase); 

    char** palabras = separarPalabras(normalizada,numPal); // debo liberar

    mostrarPalabras(palabras, numPal);

    delete [] frase;
    frase = nullptr;

    delete [] normalizada;
    normalizada = nullptr;

    liberarMemoria(palabras, numPal);
    palabras = nullptr;
    return 0;


}
