// 10. El usuario introduce tres números enteros y el programa se encargará de decir cuál de los tres
// es el central o el de en medio.
#include<iostream>
using namespace std;
int main (){
    int *vector = new int[3];
    int a,b,c;
    for(int i=0;i<3;i++){
        int valor;
        cout<<"Ingrese el termino "<<i+1<<" :";cin>>valor;
        *(vector + i) = valor;
    }
    for(int i=0;i<3;i++){
        cout<<*(vector+i)<<" ";
    }
    a=*(vector);
    b=*(vector+1);
    c=*(vector+2);
    int medio = ((a<b && a>c)||(a>b && a<c))?a:
                ((b<a && b>c)||(b>a && b<c))?b:c;
                
    cout<<"\nEl numero del medio es: "<<medio;
    return 0;
}