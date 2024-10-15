// 10. Mostrar un listado con los valores de 1, 2, ....., 1000 fotocopias, junto con su costo
// respectivo, si el precio unitario de la fotocopia es leído por la computadora.
#include<iostream>
#include<cstdlib>
#include<ctime>
int main(int argc,char*argv[]){
    srand(time(0));
    int valor = rand()%1000 +1;
    int precio;
    std::cout<<"La cantidad de fotocopias es: "<<valor;
    std::cout<<"\nIntroduzca el precio de las copias por unidad: ";std::cin>>precio;
    std::cout<<"\nEl total es de: s/."<<valor*precio<<".00";

}