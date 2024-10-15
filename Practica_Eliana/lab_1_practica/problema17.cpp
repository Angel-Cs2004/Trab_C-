// 17. Determine el menor valor de 5 números, indicando además a qué orden pertenece. Considere
// que el menor valor puede repetirse. Por ejemplo: Si los números ingresados fueran: 14, 19, 14,
// 16, 15. Los resultados deben ser: El menor valor ingresado fue 14 y corresponden al primer
// número, tercer número.
#include<iostream>
#include<vector>
using namespace std;
void menor(int *vector,string puestos[5]){
    int menor;
    menor = vector[0];
    for(int i=0;i<5;i++){
        if(menor>vector[i]){
            menor=vector[i];
        }
    }
    cout<<"El termino menor es: "<<menor<<endl;
    for(int i=0;i<5;i++){
        if(menor==vector[i]){
            cout<<"Corresponde al "<<puestos[i]<<" numero"<<endl;
        }
    }
}
int main (){
    int *vector = new int[5];
    string puestos[5]={"primer","segundo","tercer","cuarto","quinto"};
    for(int i=0;i<5;i++){
        int valor;
        cout<<"Ingrese el termino "<<i+1<<" : ";cin>>valor;
        cout<<endl;
        *(vector+i)=valor;
    }
    menor(vector,puestos);
    delete[] vector;
    return 0;
}