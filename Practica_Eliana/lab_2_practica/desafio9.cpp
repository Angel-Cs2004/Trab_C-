// 9. Pedir sucesivamente por teclado un número hasta que el número sea un valor comprendido
// entre 1 y 5.
#include<iostream>
int main(int argc, char*argv[]){
    int valor,contador=1;
    do{
        std::cout<<"Ingrese un valor "<<contador<<" : ";std::cin>>valor;
        contador+=1;
    }while(!(valor>=1 && valor<=5) );
    std::cout<<"Se introdujo un valor en el rango de 1 a 5 ";
    std::cout<<"\nProceso terminado";
}