/*3. Realice un progrma que lea de la entrada enstandar los siguientes datos de una persona: 
     Edad: dato de tipo entero.
     Sexo: dato de tipo caracter.
     Altura en metros: datos de tiempo real.
  Tras Leer los datos, el progrma debe mostrarlos e la salida esntandr. 
*/

#include<iostream>
using namespace std;
int main(){
	int edad;
	float altura;
	char sexo[10];
	cout<<"Introduce tu edad: "; cin>>edad;
	cout<<"Introduce tu altura: "; cin>>altura;
	cout<<"Cual es tu sexo: "; cin>>sexo;
	cout<<"Edad: "<<edad;
	cout<<"\nALtura: "<<altura<<"m";
	cout<<"\nSexo: "<<sexo<<endl;
	return 0;
}

