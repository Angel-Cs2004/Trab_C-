// 3. Mostrar los pares entre a y b
#include<iostream>
int main(int argc, char* argv[]){
    int a,b;
    std::cout<<"Ingrese el minimo: ";std::cin>>a;
    std::cout<<"Ingrese el maximo: ";std::cin>>b;
    for(int i=a;i<b+1;i++){
        if(i%2==0){
            std::cout<<i<<" ";
        }
    }
}