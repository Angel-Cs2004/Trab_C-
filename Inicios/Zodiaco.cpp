/*6. Este programa muestra el signo zodiacal de una persona. Para ello el usuario debe introducir
únicamente el día y el mes de nacimiento y el programa determinará inmediatamente el signo
zodiacal de la persona. ""++++++_}{}":>///
*/
#include <iostream>;
#include <string>
using namespace std;
int main (){
	int mes,dia;
	string signo;
	cout<<"Ingresa  el dia: ";cin>>dia;
	cout<<"Ingresa el mes: ";cin>>mes;
	signo =(mes==1 && dia<=19)|| (mes==12 && dia>=22)?"capricornio":
           (mes==2 && dia<=18)|| (mes==1 && dia>=20)?"acuario":
 	       (mes==3 && dia<=20)|| (mes==2 && dia>=19)?"picis":
	       (mes==4 && dia<=19)|| (mes==3 && dia>=21)?"aries":
	       (mes==5 && dia<=20)|| (mes==4 && dia>=20)?"tauro":
	       (mes==6 && dia<=20)|| (mes==5 && dia>=21)?"geminis":
  	       (mes==7 && dia<=22)|| (mes==6 && dia>=21)?"cancer":
	       (mes==8 && dia<=22)|| (mes==7 && dia>=23)?"leo":
	       (mes==9 && dia<=22)|| (mes==8 && dia>=23)?"virgo":
	       (mes==10 && dia<=22)|| (mes==9 && dia>=23)?"libra":
	       (mes==11 && dia<=21)|| (mes==10 && dia>=23)?"escorpio":
	       (mes==12 && dia<=21)|| (mes==11 && dia>=22)?"sagitario":"Fecha invalida";
	cout<<"usted es "<<signo;
	return 0;
}
