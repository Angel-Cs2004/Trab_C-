#include<iostream>
#include<string>
#include<fstream> 
#include<vector>
#include<filesystem>
using namespace std;
namespace fs = std::filesystem;
int main(){
    fs::path ruta_actual = fs::current_path()/"perro";
    cout<<ruta_actual;
    fs::create_directory(ruta_actual);
    cout<<"\nterminado "<<fs:: current_path();
    return 0;
}