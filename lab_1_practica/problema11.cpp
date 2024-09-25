// 11. El usuario introduce tres números enteros y el programa los ordenará en orden
// ascendente y a continuación en orden descendente, mostrando en la primer columna 
//los números de menor a mayor y en la siguiente columna a continuación los números
 //de mayor a menor.
 /* 3 4 5
 3 5
 4 4
 5 3   hacerlo por un fort con vectores o punteros*/
 #include <iostream>
using namespace std;


int main() {
    int num;
    cout<<"Ingrese la cantidad de numeros que desea organizar: ";cin>>num;
    int list[num];
    for(int i=0;i<num;i++){
        int valor;
        cout<<"Ingresa el valor "<<i+1<<" : ";cin>>valor;
        list[i]=valor;
    }
    for(int i=0;i<num-1;i++){
        for(int j=0;j<num-i-1;j++){
            if(list[j]>list[j+1]){
                int moment = list[j];
                list[j]=list[j+1];
                list[j+1]=moment;
            }
        }
    }
    for (int i=0;i<num;i++){
        cout<<list[i]<<"     ";
        cout<<list[num-i-1]<<endl;
    }
    return 0;
}
