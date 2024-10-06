
#include<iostream>

#include<string>
#include<fstream>
using namespace std;

void leer(string& file,int& col, int& fil){
    string linea;
    fstream archivo;
    archivo.open(file,ios::in);
    while(getline(archivo,linea)){
        fil++;
        cout<<linea<<endl;
    }
    col=linea.size();
    archivo.close();
}

char** create_matriz(int col, int fil) {
    // Reserva de memoria
    char** matriz = new char*[fil];
    for (int i = 0; i < fil; i++) {
        matriz[i] = new char[col];//[0,........n(col)] indice == n-1
    }
    // Asignamos los valores para los punteros
    for (int a = 0; a < fil; a++) { //comienza con 0-->1,2,3,4,5 
        for (int b = 0; b < col; b++) {//comienza desde el 0-->11
            matriz[a][b] = '0';
        }    
    }
    for (int i = 0; i < fil; i++) { //comienza con 0-->1,2,3,4,5 
        for (int j = 0; j < col; j++) {//comienza desde el 0-->1,2,3,4,5,6
            cout<<matriz[i][j]<<" ";
        } 
        cout<<endl;
    }
    
    cout << "\nSe terminó el proceso de creación";
    return matriz;
}


void save(string& file,char **matriz,int fil,int col){
    fstream archivo;
    string linea;
    int contador=0;
    archivo.open(file,ios::in);
    while(getline(archivo,linea)){
        for (size_t j = 0; j < linea.size(); j++){
            matriz[contador][j]=linea[j];
        }
        contador++;
    }
    archivo.close();
    ofstream carpeta("new_matriz.txt");
    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            carpeta<<matriz[i][j]<<" ";
        }
        carpeta<<endl;    
    }
    carpeta.close();
}

void Agregar(int col,int fil,string& file){
    char adicion,rpta;
    char **matriz_add;
    cout<<"\nQue desea agregar?[A(arista)|V(vertice)]: ";cin>>adicion;
    if(adicion=='A' || adicion=='a'){
        char valor;
        int indice;
        col++;
        matriz_add=create_matriz(col,fil);
        // que con quien es incidente la siguiente matriz ingrese(max 2)
        for (size_t i = 0; i < 2; i++){
            cout<<"\nCon que vertice incide la nueva arista: ";cin>>indice; //mod ind
            matriz_add[indice][col-1]='1';
            cout<<endl;
            // la matriz modificada(check) sobrescri
        }
        // hacer una funcion que sobrescriab la nueva matriz con lo nuevo
    }else if(adicion=='V' || adicion=='v'){
        //con que aristas es incidente
        fil++; 
        char indice,valor;
        matriz_add= create_matriz(col,fil);
        // que con quien es incidente la siguiente matriz ingrese(max 2)
        cout<<"\nSe creo el nuevo vertice con exito.";
        for (size_t j = 0; j < col; j++){
                cout<<"\nIncide con la arista "<<j+1<<"?, marque con [1-0]: ";cin>>valor;
                matriz_add[fil-1][j]=valor;
            
        }
    }
    else{
        cout<<"\nNo se puede ralizar la operacion, caracter invalido.";
    }
    cout<<"\nDesea guardar la nueva matriz?:[y/n]: ";cin>>rpta;
    if(rpta=='y' || rpta=='Y'){
        save(file,matriz_add,fil,col);
        cout<<"\nProceso terminado";
    }else if(rpta=='n'|| rpta=='N'){
        cout<<"\nProceso terminado";
    }
}

char** copy_and_create_matriz_file(string& file,int col,int fil){
    fstream archivo;
    string linea;
    char rpta;
    //reserva de memoria
    char **matriz=new char*[fil];
    for(int i=0;i<fil;i++){
        matriz[i] = new char[col];
    }
    //Asignamos los valores para los punteros
    archivo.open(file,ios::in);
    cout<<endl;
    for(int i=0;i<fil;i++){
        getline(archivo,linea);
        for(int j=0;j<col;j++){
            matriz[i][j]=linea[j];
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;    
    }
    archivo.close();

    cout<<"\nDesea guardar la nueva matriz?:[y/n]: ";cin>>rpta;
    if(rpta=='y' || rpta=='Y'){
        save(file,matriz,fil,col);
        cout<<"\nProceso terminado";
    }else if(rpta=='n'|| rpta=='N'){
        cout<<"\nProceso terminado";
    }
    cout<<"\nSe termino el proceso de creacion";
    return matriz;

}

int main(int argc,char *argv[]){
    char rpta;
    int  valor,col=0,fil=0;
    string file;
    cout<<"Deseas procesar algun archivo?[y/n]: ";cin>>rpta;
    if(rpta=='y'||rpta=='Y'){
        cout<<"\nNombre del archivo: ";cin>>file;
        leer(file,col,fil); //me devuelve los valores de la columnas y filas
        do{
            cout<<"\nINGRESE EL PROCESO QUE DESEA REALIZAR:\n \n1)Agregar\n2)Crear_Matriz\n\nValor elegido: ";cin>>valor;
            switch (valor){
                case 1:/*Opcion de agregar*/
                    Agregar(col,fil,file);
                    break;  
                case 2:
                    copy_and_create_matriz_file(file,col,fil);
                    break;
                    
            }
        } while (valor!=0);
            
    }else{
        cout<<"\nProceso terminado";
        return 0;
    }
    cout<<"\nDecidio terminar con todos los procesos";
    return 0;
}