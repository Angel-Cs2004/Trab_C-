# include<iostream>
#include<cmath>
using namespace std;
int main(){
	float x,y,rpta;
	cout<<"Ingrese x: "; cin>>x;
	cout<<"Ingrese y: "; cin>>y;
	rpta=(sqrt(x))/(pow(y,2)-1);
	cout<<"F(x)= "<<rpta;
	return 0;
}
