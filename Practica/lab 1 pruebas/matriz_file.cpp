#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
int main(){
    string valor,linea;
    int col=0,fil=0,contador=0;
    cout<<"Ingrese el nombre del archivo: ";cin>>valor;
    cout<<endl;
    ifstream archivo(valor);

    while (getline(archivo,linea)){ //obtenemos las dimensiones
        fil+=1;
        col=linea.size();
    }


    string array[fil][col];


    //volver al inicio
    archivo.clear();
    archivo.seekg(0);


    while (getline(archivo,linea)){
            for(int i=0;i<linea.size();i++){
                array[contador][i]=linea[i];
            }
            contador+=1;
        }
    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Fila: "<<fil<<"    Columna: "<<col;
}
