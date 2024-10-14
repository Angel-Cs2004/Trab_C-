#include <iostream>
#include <fstream> //entrada y salida de datos, 
#include <vector>

using namespace std;  // Evita la necesidad de usar "std::" antes de cout, cerr, etc.

//constante establecerla 
const size_t BLOCK_SIZE = 1024;  // Tamaño del bloque en bytes

// Función para particionar un archivo en bloques
vector<vector<char>> partitionFile(const string& nombre_archiv) // es una constante string con reserva file 
{
    // Abrir archivo en modo binario
    ifstream archv_bin(nombre_archiv, ios::binary);  
    
    //verificar si el archivo se particiono 
    if (!archv_bin)
     {
        cout << "No se pudo abrir el archivo." << endl;
        return {};
    }
    
    //crear un vector blocks
    vector<vector<char>> blocks;  // Almacenará los bloques
    char space_memory[BLOCK_SIZE];  // Buffer(espacio en memoria) para cada bloque == "_,_,_,...."

    //particionar por cada 1024 bytes
    while (archv_bin.read(space_memory, BLOCK_SIZE)) { // Intenta leer bufer_ssize bits y alamacenarlos en el space
        blocks.emplace_back(space_memory, space_memory + BLOCK_SIZE);  // Agregar bloque completo
    }

    // Procesar el último bloque si tiene un tamaño menor que BLOCK_SIZE
    if (archv_bin.gcount() > 0) {
        blocks.emplace_back(space_memory, space_memory + archv_bin.gcount());
    }

    //Returnar el vector de vectores  y cerrar el archiv bin 
    archv_bin.close();  // Cerrar archivo
    return blocks;
}

int main() {
    string filename = "archivo_de_entrada.bin";
    vector<vector<char>> bloques = partitionFile(filename);

    cout << "Archivo particionado en " << bloques.size() << " bloques." << endl;

    // Aquí podrías continuar con la implementación de hashing en otra fase
    return 0;
}

                             // establece un vector de v
// void saveBlocksToFiles(const vector<vector<char>>& blocks, const string& baseFilename) {
//     for (size_t i = 0; i < blocks.size(); ++i) {
//         string partFilename = baseFilename + "_part" + to_string(i) + ".bin";  // Crear nombre del archivo de cada bloque
//         ofstream partFile(partFilename, ios::binary);  // Abrir un archivo para cada bloque
//         if (partFile) {
//             partFile.write(blocks[i].data(), blocks[i].size());  // Escribir el bloque en el archivo
//             cout << "Guardado: " << partFilename << endl;
//         } else {
//             cerr << "No se pudo crear el archivo: " << partFilename << endl;
//         }
//     }
// }

// int main() {
//     string filename = "archivo.txt";
//     vector<vector<char>> blocks = partitionFile(filename);  // Particionar el archivo
//     saveBlocksToFiles(blocks, "archivo");  // Guardar las partes en archivos separados
//     return 0;