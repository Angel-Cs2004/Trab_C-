#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void leer(int *v, int numero){
	for(int i=0;i<numero;i++){
		cout<<"El valor para el termino "<<i+1<<": ";cin>>*(v+i);
	    cout<<endl;
	}
}
void mostrar(int *v, int numero){
	for(int i=0;i<numero;i++){
		cout<<*(v+i)<<" ";
	}
	cout<<endl;
}


void raiz(int *v, int t){
	for (int i=0; i<t;i++){
		cout<<pow(*(v+i),2)<<" ";
		
	}
	cout<< endl;
}
void factorial(int *v, int t){
	
	for (int i=0; i<t;i++){
		int cte = 1;
		for (int j =0; j<*(v+i);j++){
			cte*=(j+1);
		}
		cout<<"el factorial del elemento en posicion "<<i+1<<"("<<*(v+i)<<")"<<": "<<cte<<endl;
	}
	cout<< endl;

}
void divisores(int *v, int t){
		for (int i=0; i<t;i++){
		    int cte = 1;
		    cout<<"los divisores del termino "<<i+1<<"("<<*(v+i)<<")"<<": ";
		    for (int j =1; j<*(v+i)+1;j++){
			    if (*(v+i)%j==0){
				   cout<<j<<" - ";
		       	}
	    	}
	    	cout<<endl;
    	}
}
void primos(int *v, int t){
	for (int i =0;i<t;i++){
		for( int j=2;j<*(v+i);j++){
			if (*(v+i)%j==0){
				break;				
			}
		if(*(v+i)-1==j){
			cout<<*(v+i)<<" ";
		}			
		}
	}
}

int main (int argc, char *argv[]){
	int num;
	int *vector= new int[num] ;
	cout<<"Ingrese el valor que desea que sea la matriz: ";cin>>num;
	leer(vector,num);
	mostrar(vector,num);
	cout<<"La raiz es: "<<endl;
	raiz(vector,num);
	cout<<endl;
	cout<<"El factorial de los terminos : "<<endl;
	factorial(vector,num);
	cout<<endl;
	cout<<"Los devisores de los terminos : "<<endl;
	divisores(vector,num);
	cout<<"Soy primos : "<<endl;
	primos(vector,num);

	delete []vector;
	return 0;
}

