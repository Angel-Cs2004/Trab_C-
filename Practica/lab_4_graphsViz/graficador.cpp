#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
void leer(string& rpta,int& col, int& fil){
    string linea;
    fstream archivo;
    archivo.open(rpta,ios::in);
    cout<<"MATRIZ: "<<rpta<<endl;
    while(getline(archivo,linea)){
        fil++;
        for (size_t i = 0; i < linea.size(); i++){
            cout<<linea[i]<<" ";
        }
        cout<<endl;
    }
    col=linea.size();
    archivo.close();
    cout<<"El numero de columnas es: "<<col<<"                   El numero de nodos es: "<<fil<<endl;
}

char** create_matriz(string& file,int col, int fil) {
    // Reserva de memoria
    fstream archivo;
    string linea;
    archivo.open(file,ios::in);
    char** matriz = new char*[fil];
    for (int i = 0; i < fil; i++) {
        matriz[i] = new char[col];//[0,........n(col)] indice == n-1
    }
    // Asignamos los valores para los punteros
    for (int a = 0; a < fil; a++) { //comienza con 0-->1,2,3,4,5 
        getline(archivo,linea);
        for (int b = 0; b < col; b++) {//comienza desde el 0-->11
            matriz[a][b] = linea[b];
        }    
    }
    for (int i = 0; i < fil; i++) { //comienza con 0-->1,2,3,4,5 
        for (int j = 0; j < col; j++) {//comienza desde el 0-->1,2,3,4,5,6
            cout<<matriz[i][j]<<" ";
        } 
        cout<<endl;
    }
    
    cout << "\nSe terminó el proceso de creación\n";
    return matriz;
}

void print_ref(char **matriz,int col,int fil){
    for (size_t i = 0; i < col+1; i++){
        if(i==0){
            cout<<"  ";
        }
        else{
            cout<<i<<" ";
        }
    }
    cout<<endl;
    // se crea la referencia vertical-marcos
    for (size_t i = 0; i < col+1; i++){
            cout<<"--";//marcos horizontales
    }
    cout<<endl;

    for (size_t i = 0; i < fil; i++){
        // getline(archivo,linea);
        for (size_t j = 0; j < col+1; j++){
            if(j==0){
                cout<<i+1<<"|";//marcos verticales
                continue;
            }else{

                cout<<matriz[i][j-1]<<" ";
            }
        }
        cout<<endl;  
    }
    cout<<endl;
    
}
    
string dot_format(char **matriz,int col,int fil){
    ofstream archivo("Grafo.dot");
    archivo<<"graph G{"<<endl;
    for (int i = 0; i <fil; i++){
        for(int j= 0;j<col; j++){
            if(matriz[i][j]=='1'){
                archivo<<"    "<<i+1<<"--"<<j+1<<";"<<endl;
            }
        }
        
    }
    archivo<<"}"; 
    archivo.close(); 
    return "Grafo.dot";
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

void modificar(string file,char **matriz,int col,int fil){
    //mostrar los valores
    print_ref(matriz,col,fil);
    char rpta;
    int fila,columna;
    cout<<"\nDesea modificar la adyacencia de algun vertice?:[y/n]";cin>>rpta;
    if(rpta=='y'||rpta=='Y'){
        cout<<"\nIndicque la posicion de matriz[i][j]";
        cout<<"\nValor [i]: ";cin>>fila;
        cout<<"\nValor [j]: ";cin>>columna;
        cout<<"Por que valor lo cambiara: [0-1]: ";cin>>rpta;
        matriz[fila-1][columna-1]=rpta;
        print_ref(matriz,col,fil);
        cout<<"\nResultado final de la matriz modificada.";
        cout<<"Gustaria guardar la matriz en un formato dot[D] o txt[T]: ";cin>>rpta;
        if(rpta=='D'||rpta=='d'){
            dot_format(matriz,col,fil);
        }else if(rpta=='T'||rpta=='t'){
            create_carpeta(matriz,col);
        }
    }

}

void view(char **matriz,int col,int fil){
  string nom_archv_dot,comando,deseo;
  char rpta;
  nom_archv_dot=dot_format(matriz,col,fil);
  //dot ejemplo2.dot -o grafo2.png -Tpng
  cout<<"A que desea exportar PDF[p] o PNG[i]: ";cin>>rpta;
  if(rpta=='i' || rpta=='I'){
    comando="dot "+nom_archv_dot+" -o grafo.png -Tpng";
    system(comando.c_str());   
  }else if(rpta=='p'||rpta=='P'){
    comando="dot "+nom_archv_dot+" -o grafo.pdf -Tpdf";
    system(comando.c_str());
  }
  cout<<"\nEl grafo fue exportado a formato.  ";

}

void busqueda(){
    string rpta,extencion=".txt";
    int fil=0,col=0;
    cout<<"Introduzca que el nombre de la matriz: ";cin>>rpta;
    extencion=rpta+extencion;
    leer(extencion,col, fil);
}
int main(int argc,char *argv[]){
    string file;
    int rpta;
    int fil=0,col=0;
    char **matriz,rpta0;
    cout<<"Que desea hacer: "<<endl;
    cout<<"\na. Leer\nb. Salirse \nSu respuesta es?: ";cin>>rpta0;
    if(rpta0=='a'){

        cout<<"Introduzca el nombre del rpta: ";cin>>file;
        leer(file,col,fil);
        do{
            cout<<"\nQue desea hacer con la matriz?: \n1. Crear la matriz de adyacencia\n2. Modificar el grafo (Vértices, enlaces)\n3. Grabar la matriz en un archivo\n4. Leer la matriz de un archivo\n5. Visualizar el grafo (graphviz)";
            cout<<"\nQue opcion escogera?: ";
            cin>>rpta;
            switch (rpta){
                case 1:
                    create_matriz(file,col,fil);
                    break;
                case 2:
                    matriz=create_matriz(file,col,fil);
                    modificar(file,matriz,col,fil);
                    break;
                case 3:
                    matriz=create_matriz(file,col,fil);
                    create_carpeta(matriz,col);
                    break;
                case 4:
                    busqueda();
                    break;
                case 5:
                    matriz=create_matriz(file,col,fil);
                    view(matriz,col,fil);
                    break;
            }
        } while (rpta<=5 && rpta>0);
        

    }else if(rpta=='b'){

    }
    return 0;
}