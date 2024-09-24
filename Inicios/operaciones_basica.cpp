/*Escriba un programa que lea de la entrad estandar dos numeros y 
muestre en salida estandar su suma, resta, multiplicacion y division.*/

#include<iostream>
using namespace std;
int main(){
	float num1, num2, division=0;
	cout<<"Ingrese el primer numero:\n";
	cin>>num1;
	cout<<"Ingrese el segundo numero:\n";
	cin>>num2;
	division = num1/num2;
	cout<<endl;
	cout<<"La suma es: "<<num1+num2<<endl;
	cout<<"La resta es: "<<num1-num2<<endl;
	cout<<"La division es: "<<division<<endl;
	cout<<"La multiplicacion: "<<num1*num2<<endl;
	return 0;
}
