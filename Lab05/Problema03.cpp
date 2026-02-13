#include<iostream>
#include<cmath>
using namespace std;

struct Polinomio{
    int coef;
    int exp;
};

void llenarDatos(Polinomio *pol, int n){

    for(int i=0; i<=n; i++){
        cout<<"Ingrese el coeficiente de x^"<< n-i <<": ";
        cin>>pol[n-i].coef;

        pol[i].exp = i;
    }
}

Polinomio* sumaPolinomio(Polinomio *pol1, Polinomio *pol2, int n1, int n2, int &gradmax){
    
    if(n1 <= n2){
        gradmax = n2;
    }else{
        gradmax = n1;
    }

    Polinomio *SumPol = new Polinomio[gradmax + 1];

    for(int i=0; i<=gradmax; i++){
        int c1, c2;

        if(i <= n1){
            c1 = pol1[i].coef;
        }else{
            c1 = 0;
        }

        if(i <= n2){
            c2 = pol2[i].coef;
        }else{
            c2 = 0;
        }

        SumPol[i].coef = c1 + c2;
        SumPol[i].exp = i;
    }

    return SumPol;

}

Polinomio* multiplicarPolinomio(Polinomio *pol1, Polinomio *pol2, int n1, int n2, int &gradprod){
    gradprod = n1 + n2;

    Polinomio *Prodpol = new Polinomio[gradprod + 1];
    
    for(int i=0; i<= gradprod; i++){
        Prodpol[i].coef = 0;
        Prodpol[i].exp = i;
    }

    for(int i=0; i<=n1; i++){
        for(int j=0; j<=n2; j++){
            Prodpol[i + j].coef += pol1[i].coef*pol2[j].coef;
        }
    }
    return Prodpol;
}

void mostrarPolinomio(Polinomio *pol, int n){
    for(int i=n; i>=0; i--){
        cout<<pol[i].coef<<"x^"<<pol[i].exp;
        if(i>0){
            cout<<" + ";
        }
    }
    cout<<endl;
}

int evaluarPolinomio(Polinomio *pol, int n, int k){
    int sum = 0;

    for(int i=0; i<=n; i++){
        sum += (pol[i].coef*pow(k,pol[i].exp)); 
    }

    return sum;
}

int main(){

    int n1;
    cout<<"Ingrese el grado del primer polinomio: ";
    cin>>n1;

    Polinomio *pol1 = new Polinomio[n1];
    llenarDatos(pol1, n1);

    int n2;
    cout<<"Ingrese el grado del segundo polinomio: ";
    cin>>n2;

    Polinomio *pol2 = new Polinomio[n2];
    llenarDatos(pol2, n2);

    int gradmax;
    Polinomio *Suma = sumaPolinomio(pol1,pol2,n1,n2,gradmax);

    int gradprod;
    Polinomio *Producto = multiplicarPolinomio(pol1, pol2, n1, n2, gradprod);

    cout<<"Primer polinomio: ";
    mostrarPolinomio(pol1,n1);

    cout<<"Segundo Polinomio: ";
    mostrarPolinomio(pol2,n2);

    cout<<"La suma de los polinomios es: ";
    mostrarPolinomio(Suma,gradmax);

    cout<<"El producto de los polinomios es: ";
    mostrarPolinomio(Producto,gradprod);

    int k;
    cout<<"\nIngrese el valor de x para evaluar el primer polinomio: ";
    cin>>k;

    int sum = evaluarPolinomio(pol1,n1,k);
    cout<<"El primer polinomio evaludado en x = "<<k<<" es: "<<sum<<endl;

    delete[] pol1;
    delete[] pol2;
    delete[] Suma;
    delete[] Producto;

    return 0;
}
