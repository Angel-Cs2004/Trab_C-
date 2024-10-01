// 13. Suponga que se tiene un conjunto de calificaciones de un grupo de 10 alumnos. Realizar un algoritmo para calcular la calificación media y la calificación mas baja de todo el grupo.
#include<iostream>
int main(int argc,char*argv[]){
    int notas[10],min=0;
    float suma=0;
    for(int i=0;i<10;i++){
        std::cout<<"Ingrese la nota "<<i+1<<" : ";std::cin>>notas[i]; 
        suma+=notas[i];
    }
    std::cout<<"\nEl promedio de notas es: "<<suma/10;

    min=notas[0];
    for(int i=0;i<9;i++){
        if(notas[i]>notas[i+1]){
            min=notas[i+1];
        }
    }
    std::cout<<"\nLa calificacion mas baja es: "<<min;
    return 0;
}