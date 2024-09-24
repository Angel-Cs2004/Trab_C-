#include<iostream>
using namespace std;
int main(){
	int a,b,aux;
	cout<<"Ingrese el primer valor a: "; cin>>a;
	cout<<"Ingrese el segund valor b: "; cin>>b;
//	a,b=b,a;
    aux=a;a=b;b=aux; // tenemos que poner una tercera variable 
	cout<<"el valor de a ahora es: "<<a;
	cout<<"\nel valor de b ahora es:"<<b;
}
