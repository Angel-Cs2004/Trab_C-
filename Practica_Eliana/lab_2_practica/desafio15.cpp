// 15. En un centro de verificación de automóviles se desea saber el promedio de puntos contaminantes de los
//  primeros 25 automóviles que lleguen. Asimismo, se desea saber los puntos contaminantes del carro que menos 
//  contaminó y del que más contaminó.
#include<iostream>
#include<cstdlib>
#include<ctime>
int main(int argc,char*argv[]){
    srand(time(0));
    int carros[25];
    int max=0,min=0;
    for(int i=0;i<25;i++){
        int puntos=rand()%21;
        carros[i]=puntos;
        std::cout<<"Carro "<<i+1<<" : "<<puntos<<" puntos"<<std::endl;
    }
    max=carros[0];
    min=carros[0];
    for(int i=0;i<25;i++){
        if(min>carros[i+1]){
            min=carros[i+1];
        }
        if(max<carros[i+1]){
            max=carros[i+1];
        }
    }
    std::cout<<"El maximo contaminante es: "<<max<<std::endl;
    std::cout<<"El minimo contaminante es: "<<min<<std::endl;
}
