// 11. Producir el mismo listado anterior si existe una promoción que consiste en un descuento del 10% para cantidades entre 100 y 200 unidades y del 15% para cantidades entre 201 y 500 unidades y del 20% para compras mayores
#include<iostream>
#include<cstdlib>
#include<ctime>
int main(int argc,char*argv[]){
    srand(time(0));
    int valor = rand()%1000 +1;
    int precio;
    std::cout<<"La cantidad de fotocopias es: "<<valor;
    std::cout<<"\nIntroduzca el precio de las copias por unidad: ";std::cin>>precio;
    float descuento =(valor>500)?(0.2):(valor<=500 && valor>200)?(0.15):(valor<=200 && valor>=100)?(0.10):(1) ;
    std::cout<<"\nEl total es de: s/."<<valor*precio*(1-descuento);

}