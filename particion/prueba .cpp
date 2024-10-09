#include<iostream>
#include<string>
#include<fstream> 
#include<vector>
#include<filesystem>

using namespace std;
namespace fs = std::filesystem;

//constante establecerla
const size_t size_block = 1024;

// Función para particionar un archivo en bloques
vector<vector<char>> particion(const string& nom_archv ){  
    // Abrir archivo en modo binario
    ifstream archv(nom_archv,ios::binary);   
    if (!archv){
        cout<<"No se logro particionar "<<nom_archv;
        return {};
    }
    char espacio_en_memoria[size_block]; 
    vector<vector<char>> blocks;

    while(archv.read(espacio_en_memoria,size_block)){
        // Mostrar el bloque que se está leyendo
        cout << "Bloque leído: " << string(espacio_en_memoria, size_block) << endl;

        blocks.emplace_back(espacio_en_memoria, espacio_en_memoria + size_block);
    }

    // Procesar el último bloque si tiene un tamaño menor que size_block
    if(archv.gcount() > 0){
        cout << "Último bloque leído (incompleto): " << string(espacio_en_memoria, archv.gcount()) << endl;
        blocks.emplace_back(espacio_en_memoria, espacio_en_memoria + archv.gcount());
    }

    archv.close();
    return blocks;
}

// Función para guardar los bloques en archivos separados
void save_document(vector<vector<char>>& block, const string& base){
    // Crear carpeta
    fs::path base_path = fs::path(base);
    fs::path path = base_path.stem(); //perro.txt => perro
    fs::path path_abs = fs::current_path()/path; // ruta/perro
    fs::create_directory(path_abs);

    // Almacenar los bloques en archivos separados
    for(int i=0; i<block.size(); i++){ //base.bin
        string extencion = "block " + to_string(i+1) + ".bin";
        fs::path path_deposito = path_abs/extencion;
        ofstream part_block(path_deposito,ios::binary);
        if (part_block){
            part_block.write(block[i].data(),block[i].size());
            cout<<"Guardado el "<<extencion<<endl;
        }
        else{
            cout<<"Error proceso sin iniciar"<<endl;
        }
    }
}

int main (){
   string name_file;
   vector<vector<char>> bloques;
   cout<<"Ingrese el nombre del archivo: ";
   cin>>name_file;
   bloques = particion(name_file);
   save_document(bloques,name_file);
   cout<<"\nEl archivo "<<name_file<<" se ha particionado en "<<bloques.size()<<" bloques."<<endl;
   return 0;
}
