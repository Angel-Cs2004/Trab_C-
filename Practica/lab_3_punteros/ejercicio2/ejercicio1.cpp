/*Hacer un programa para calcular el numero de aristas que tiene un 
grafo completo, dado como entrada el numero de vertices de un grafo*/
#include<iostream>
using namespace std;
int main(int argc, char*argv[]){
    int numero_vertices;
    cout<<"Ingrese el numero de vertices del grafo completo: ";cin>>numero_vertices;
    cout<<"Su numero de arista del grafo completo es: "<<numero_vertices*(numero_vertices-1)/2;
    return 0;
}
