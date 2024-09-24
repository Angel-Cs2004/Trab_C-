/*3. Escribe la siguiente expresion como expresion en c++*/
#include<iostream>
using namespace std;
int main(){
	float a,b,c,d,e,f, rpta = 0;
	cout<<"EL valor de a: "; cin>>a;
	cout<<"EL valor de b: "; cin>>b;
	cout<<"EL valor de c: "; cin>>c;
	cout<<"EL valor de d: "; cin>>d;
	cout<<"EL valor de e: "; cin>>e;
	cout<<"EL valor de f: "; cin>>f;
	
	rpta=(a+(b/c))/(d+(e/f));
	cout.precision(2);
	cout<<"F(x): "<<rpta;
	return 0;
}
