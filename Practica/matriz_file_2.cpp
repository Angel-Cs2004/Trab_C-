#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

vector<vector<char>>matriz_create(int filas,int columnas){
    return vector<vector<char>>(filas,vector<char>(columnas,0));
}


int main(){
    string valor,linea;
    int col=0,fil=0,contador=0;
    cout<<"Ingrese el nombre del archivo: ";cin>>valor;
    cout<<endl;
    ifstream archivo(valor);
    
    while (getline(archivo,linea)){ //obtenemos las dimensiones
        fil+=1;                 // filas = x
        col=linea.size();       // columnas = y
    }

    vector<vector<char>>matriz=matriz_create(fil,col);// creacion de la matriz
    
    //volver al inicio
    archivo.clear();
    archivo.seekg(0);

    //asignacion de valores en la matriz creada gatito
    while (getline(archivo,linea)){
            for(int i=0;i<linea.size();i++){
                matriz[contador][i]=linea[i];
                cout<<matriz[contador][i]<<" ";
            }
            contador+=1;
            cout<<endl;
        }

    cout<<"Fila: "<<fil<<"    Columna: "<<col;
}