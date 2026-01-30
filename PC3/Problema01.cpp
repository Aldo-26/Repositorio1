#include<iostream>
using namespace std;

void suma(char* p, int k){

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){

            if((*(p+i) + *(p+j)) == '15'){

            }
        }
    }
}


int main(){

    char texto[] = "1,2,4,7,11";
    char*p = texto;

    cout<<*p + *(p+4);

    int k = 15; 

    return 0;
}
