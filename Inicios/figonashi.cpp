#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> numeros;
	vector<int> m3;
	int n,a=-1,b=1,c;
	cout<<"Ingrese la cantidad de terminos que desea ver: ";cin>>n;
	for(int i=0; i<n;i++){
		c=a+b;
		numeros.push_back(c); //parametro.append(i)
		a=b;
		b=c;
	}
	for(int i=0; i< numeros.size();i++){
		cout<<numeros[i]<<" "; //se busca imprimir por indice 
	}
	cout<<"\nVector con lso multiplos de 3: "<<endl;
	for(int i=0; i<numeros.size();i++){
		if(numeros[i]%3==0){
			m3.push_back(numeros[i]);
			cout<<numeros[i]<<" ";
		}
	}
	cout<<"\nInvertido: "<<endl;
	for(int i=m3.size()-1; i>=0;i-- ){
		cout<<m3[i]<<" ";
	}  
	return 0;
}
