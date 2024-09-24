#include<iostream>
using namespace std;
int main(){
	int a;
	cout<<"Ingrese el valor: ";cin>>a;
//	if( a%2==0){
//		cout<<"El numero es par";
//	}
//	else{
//		cout<<"El numero es impar";
//	}
//	
	if( a==0){
		cout<<"El numero es 0";
	}
	else if(a%2==0){
		cout<<"El numero es par";
	}
	else{
		cout<<"El numero es impar";
	}
	return 0;
}
