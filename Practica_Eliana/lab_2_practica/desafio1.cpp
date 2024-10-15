// 1. Mostrar los N primeros múltiplos de 3.
#include<iostream>
// using namespace std;
int main(int argc, char* argv[]){
    int num;
    std::cout<<"Ingrese cuantos valores ingresara: ";std::cin>>num;
    for(int i= 0;i<num;i++){
        std::cout<<i*3<<" ";
    }
}