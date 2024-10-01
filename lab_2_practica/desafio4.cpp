// 4. Se introducen 5 números por teclado, y se desea calcular cuántos son mayores que 0,
// cuantos son menores a 0 y cuantos son iguales a 0.
#include<iostream>
#include<vector>

int main(int argc,char* argv[]){
    int mayor=0,menor=0,igual=0;
    std::vector<int>lista(5);
    for(int i=0;i<5;i++){
        std::cout<<"Ingrese el termino "<<i+1<<" : ";std::cin>>lista[i];
    }
    for(int i=0; i<5;i++){
        if(lista[i]==0){
            igual+=1;
        }
        else if(lista[i]>0){
            mayor+=1;
        }
        else{
            menor+=1;
        }
    }
    std::cout<<"Los iguales a 0 : "<<igual<<std::endl;
    std::cout<<"Los mayores a 0: "<<mayor<<std::endl;
    std::cout<<"Los menores a 0: "<<menor<<std::endl;
}