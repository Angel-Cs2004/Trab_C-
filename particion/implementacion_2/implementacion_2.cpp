#include<iostream>
#include<string>
#include<fstream> 
#include<filesystem>
#include<cmath>
#include <bitset>
#include <cstring>
#include<tuple>

using namespace std;
namespace fs = std::filesystem;

const size_t size_block = 1024;  // Tamaño del bloque en bytes

// Función para calcular el número de bloques
int dimenciones_array(string& nom_archiv) {
    char es_M[size_block];
    int contador = 0;

    ifstream archiv(nom_archiv, ios::binary);
    while (archiv.read(es_M, size_block)) {
        contador++;
    }
    if (archiv.gcount() > 0) {
        contador++;
    }
    return contador;
}

string **particion(string& nom_archiv) {
    char es_M[size_block];
    int contador = sqrt(dimenciones_array(nom_archiv)) + 1;
    string string_key="";
    ifstream archiv(nom_archiv, ios::binary);

    // Inicializar la matriz de cadenas de tamaño contador x contador
    string** array = new string*[contador];
    for (int i = 0; i < contador; i++) {
        array[i] = new string[contador];
    }


    // Recorremos la matriz con dos bucles for
    for (int i = 0; i < contador && archiv; i++) {
        for (int j = 0; j < contador && archiv; j++) {
            // Leer el bloque de datos
            archiv.read(es_M, size_block);
            if (archiv.gcount() == 0) break;  // Si ya no hay más datos, salir del bucle

            // Crear el string_block a partir del bloque leído en binario
            string string_block;
            
            // Convertir cada byte a binario y agregarlo a string_block
            for (int k = 0; k < archiv.gcount(); ++k) {
                string_block += bitset<8>(static_cast<unsigned char>(es_M[k])).to_string();
            }

            // Concatenar la dirección de memoria del array del string_block
            uintptr_t direccion_array_pos = reinterpret_cast<uintptr_t>(&array[i][j]);
            string_key+=to_string(direccion_array_pos)+",";
            string_block += "__"+to_string(direccion_array_pos);

            // Almacenar el bloque en la matriz
            array[i][j] = string_block;

            // Imprimir el bloque y su dirección de memoria en la matriz
            cout << "Bloque [" << i << "][" << j << "]: " << array[i][j] 
                 << " | Dirección en matriz: " << reinterpret_cast<uintptr_t>(&array[i][j]) << endl;

        }
    }
    for (int i = 0; i < contador; ++i) {
        delete[] array[i];
    }
    // delete[] array;

    cout<<string_key;
    return array;
    
}

int main() {
    string name_file;
    string **array_valores;
    

    cout << "Ingrese el nombre del archivo: ";
    cin >> name_file;
    array_valores=particion(name_file);
    return 0;
}