/*7. La calificacion final de un  erstudiante es  edia ponderada de tres notas:
 La nota de practicas cuenta con un 30% del total, la nota teorica que ucenta 
 un 60% y la nota de participacion qe cuenta conel 10% restante.Escriba un programa
 que lea de la entrada estandar las tre notas de un alumno y escriba en la salida 
 estandar su nota final*/
 
 #include<iostream>
 using namespace std;
 int main(){
 	float np, nt, pr,prom;
 	cout<<"Nota practica: ";cin>>np;
  	cout<<"Nota teorica: ";cin>>nt;
 	cout<<"Nota participacion: ";cin>>pr;
 	
 	prom= (np*0.3+nt*0.6+pr*0.1);
 	cout<<"Tu promedio es: "<<prom;
	return 0;
 }
