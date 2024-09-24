/*La sentencia if 
  
  if(condicion){
       instrucciones 1;
    }
   else{
      instrucciones2;
    }
*/
#include <iostream>
using namespace std;
int main(){
	int numero, dato= 5;
	
	cout<<"Digite un numero: ";
	cin>>numero;
	
	if(numero==dato){
		cout<<"El numero es 5";
	}
	else{
		cout<<"LE numero no es 5";
	}
	return 0;
	
}
