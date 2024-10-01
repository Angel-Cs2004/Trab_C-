// 6. Hallar la suma de todos los números ingresados por el usuario. El programa ya no pedirá más
// números cuando el usuario ingrese 0.
#include<iostream>
int main(int argc,char* argv[]){
    int valor,suma;
    do{
        std::cout<<"Ingrese un valor: ";std::cin>>valor;
        suma+=valor;
    }while(valor!=0);
    std::cout<<"El proceso ha terminado.";
    std::cout<<"\nLa suma de los valores dados es: "<<suma;

    return 0;
}