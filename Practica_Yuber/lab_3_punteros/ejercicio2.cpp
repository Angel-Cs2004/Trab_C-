#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int leer(string& file,char rpta ){
    fstream archivo;
    string linea;
    cout<<"\nDesea leerlo?[y/n]: ";cin>>rpta;
    if(rpta=='y'){
        int col;
        archivo.open(file,ios::in);
        while(getline(archivo,linea)){
            for(int i=0;i<linea.size();i++){
                cout<<linea[i]<<" ";
            }
            cout<<endl;
        }
        col=linea.size();
        cout<<"Las dimenciones de la matriz: "<<col<<"x"<<col<<endl;
        archivo.close();
        cout<<"\nSe termino de leer.";
        return col;
    }else{
        cout<<"\nProceso terminado...";
        return 0;
    }
}

void create_carpeta(char**matriz,int col){
    ofstream carpeta("new_matriz.txt");
    for(int i=0;i<col;i++){
        for(int j=0;j<col;j++){
            carpeta<<matriz[i][j]<<" ";
        }
        carpeta<<endl;    
    }
    carpeta.close();    
}

char** create_matriz(int columnas,string& file,char rpta){
    cout<<"\nDesea crear una matriz con los datos obtenidos?[y/n]: ";cin>>rpta;
    if(rpta=='y'){
        
        char **matriz= new char*[columnas];
        for(int i=0;i<columnas;i++){
            matriz[i] = new char[columnas];    
        }
        fstream archivo;
        string linea;
        archivo.open(file,ios::in);
        for(int i=0;i<columnas;i++){
            getline(archivo,linea);
            for(int j=0;j<columnas;j++){
                matriz[i][j]=linea[j];
                cout<<matriz[i][j]<<" ";
            }
            cout<<endl;    
        }
        archivo.close();
        cout<<"\nSe termino de crear la matriz.";
        return matriz;
    }else{
        cout<<"\nProceso terminado...";
        return 0;
    }
}

void **modif_matriz(char **matriz,char rpta,int columnas){

    cout<<"Desea modificar algun valor de la matriz[y/n] ";cin>>rpta;
    if(rpta=='y'){
        int fil,col;
        char valor;
        cout<<"\nIngrese la fila y columna respectivamente: ";cin>>fil>>col;
        cout<<"\nPor que valor desea cambiar el valor de la matriz"<<"["<<fil<<"]"<<"["<<col<<"]: ";cin>>valor;
        matriz[fil][col]=valor;    
        cout<<"\nSe ha modificado valor..";
        create_carpeta(matriz,columnas);  
        cout<<"\nProceso terminado....";  
        return 0;
    }else{
        cout<<"Proceso terminado";
        return 0;
    }
}



int main (int argc,char*argv[]){
    string file;
    int col;
    char **matriz,rpta;

    cout<<"Ingresa el file: ";cin>>file;
    col=leer(file,rpta);
    matriz=create_matriz(col,file,rpta);
    cout<<"\nQuiere terminar el proceso[y/n]: ";cin>>rpta;
    if(rpta=='y'){
        create_carpeta(matriz,col);
    }
    modif_matriz(matriz,rpta,col);
    return 0;
}