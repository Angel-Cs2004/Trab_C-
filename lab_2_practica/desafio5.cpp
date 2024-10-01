// 5. Ingresar valores por teclado hasta que se ingrese un cero.
#include<iostream>
int main(int argc,char* argv[]){
    int valor;
    do{
        std::cout<<"Ingrese un valor: ";std::cin>>valor;
    }while(valor!=0);
    std::cout<<"El proceso ha terminado.";
    return 0;
}