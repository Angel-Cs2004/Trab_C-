#include<iostream>
#include<string>
using namespace std;
int main (){
	int monedas,billetes;
	int v_monedas,v_billetes;
	int t_m,t_b;
	string rpta,money;
	cout<<"\nIngrese la cantidad de biletes y su valor: ";cin>>billetes>>v_billetes;
	cout<<"\nIngrese la cantidad de monedas y su valor: ";cin>>monedas>>v_monedas;
	t_b=billetes*v_billetes;
	cout<<"\nEl valor total de billetes es: "<<t_b;
	t_m=monedas*v_monedas;
	cout<<"\nEl valor total de monedas es: "<<t_m;
	cout<<"\nEl total es: "<<t_b+t_m;
	cout<<"\nDesea comvertirlo";cin>>rpta;
	if(rpta=="Si"){
		cout<<"\nA dolares o euros (d/e)";cin>>money;
		if(money=="e"){
			cout<<"\nel valor de su moneda es: "<< (t_b+t_m)*4.18;
		}
		else if(money=="d"){
			cout<<"\nEl valor de su moneda es: "<<(t_b+t_m)*3.77;
		}
	}
	else if (rpta=="No"){
		cout<<"\nProceso finalizado";
	}#include<iostream>
#include<string>
using namespace std;
int main (){
	int monedas,billetes;
	int v_monedas,v_billetes;
	int t_m,t_b;
	string rpta,money;
	cout<<"Ingrese la cantidad de biletes y su valor: ";cin>>billetes;cout<<" y ";cin>>v_billetes;
	cout<<"\nIngrese la cantidad de monedas y su valor: ";cin>>monedas;cout<<" y ";cin>>v_monedas;
	t_b=billetes*v_billetes;
	cout<<"\nEl valor total de billetes es: "<<t_b;
	t_m=monedas*v_monedas;
	cout<<"\nEl valor total de monedas es: "<<t_m;
	cout<<"\nEl total es: "<<t_b+t_m;
	cout<<"\nDesea comvertirlo(si/no): ";cin>>rpta;
	if(rpta=="si"){
		cout<<"\nA dolares o euros (d/e): ";cin>>money;
		if(money=="e"){
			cout<<"\nel valor de su moneda es: "<< (t_b+t_m)*4.18;
		}
		else if(money=="d"){
			cout<<"\nEl valor de su moneda es: "<<(t_b+t_m)*3.77;
		}
	}
	else if (rpta=="No"){
		cout<<"\nProceso finalizado";
	}
}
