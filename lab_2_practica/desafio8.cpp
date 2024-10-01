//  Programa en el que el ordenador lanza 50 veces un dado y cuenta cuantas veces sale el nº
// 1
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(int argc,char*argv[]){
    srand(time(0));
    int suma_1=0;
    for(int i=0;i<50;i++){
        int valor = rand()% 6+1;
        cout<<valor<<" ";
        if(valor==1){
            suma_1+=1;
        }
    }
    cout<<endl;
    cout<<"La cantidad de unos es : "<<suma_1;
    return 0;
}
