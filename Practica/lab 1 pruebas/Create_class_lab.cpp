/*Primero que ideas tendriamos :
    - p name floder 
    - p name c/u file 
    - p name ext */
#include<iostream>
#include<fstream>
#include<filesystem>
#include<string>
using namespace std;
namespace fs = std::filesystem;

void create_carp(fs::path folder,fs::path fil,fs::path ext, int num ){
    
    fs::path direccion =fs:: current_path(); 
    fs::path ruta = direccion/folder;
    fs::create_directory(ruta);
    fs::path ruta_file = ruta/fil;
    for(int i =0;i<num;i++){
        string file_create = ruta_file.string() + to_string(i+1)+"."+ext.string();
        ofstream file_abs(file_create);
    }
    cout<<"\nLos files fueron creados";
}
int main (){
    fs::path name_folder;
    fs::path name_file;
    fs::path name_ext;
    int numero;
    cout<<"Ingresa el nombre de la carpeta: ";cin>>name_folder;
    cout<<"\nIngresa el nombre de cada file: ";cin>>name_file;
    cout<<"\nCuantos files desea: ";cin>>numero;
    cout<<"\nCual sera la extencion en la que desea tenerlo: ";cin>>name_ext;
    create_carp(name_folder,name_file,name_ext,numero);
    return 0;
 }
//La quiero mucho xodo