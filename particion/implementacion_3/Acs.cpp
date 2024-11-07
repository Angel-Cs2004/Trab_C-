#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <bitset>
#include <cstdlib>     // para rand() y srand()
#include <ctime>       // para time()

using namespace std;

// Constante para establecer el tamaño del bloque
const size_t size_block = 64; // Cada bloque será de 8x8, lo que equivale a 64 bytes

// Función para particionar un archivo en bloques
const int blockSize = 8;

// Función para procesar y almacenar los bloques de la imagen
vector<vector<string>> procesamiento_Bloques(const cv::Mat& img, int blockSize) {
    vector<vector<string>> blocks;

    for (int i = 0; i < img.rows; i += blockSize) {
        for (int j = 0; j < img.cols; j += blockSize) {
            vector<string> block;

            for (int y = i; y < (i + blockSize); y++) {
                for (int g = j; g < (j + blockSize); g++) {
                    uint8_t pixelValue = img.at<uint8_t>(y, g);
                    block.push_back(bitset<8>(pixelValue).to_string());  // Convertir el valor del píxel a binario
                }
            }
            blocks.push_back(block);  // Agregar el bloque a la lista de bloques
        }
    }

    return blocks;
}

// Definición de las reglas de encriptación
void iden_reglas_compuestas(string& cadena, string accion, int indice) {
    map<char, map<string, char>> reglas;

    // Definición de las reglas
    reglas['a'] = {
        {"111", '0'}, {"110", '0'}, {"101", '0'}, {"100", '0'},
        {"011", '1'}, {"010", '1'}, {"001", '1'}, {"000", '1'}
    };
    reglas['c'] = {
        {"111", '0'}, {"110", '1'}, {"101", '0'}, {"100", '1'},
        {"011", '0'}, {"010", '1'}, {"001", '0'}, {"000", '1'}
    };
    reglas['C'] = {
        {"111", '1'}, {"110", '0'}, {"101", '1'}, {"100", '0'},
        {"011", '1'}, {"010", '0'}, {"001", '1'}, {"000", '0'}
    };
    reglas['A'] = {
        {"111", '1'}, {"110", '1'}, {"101", '1'}, {"100", '1'},
        {"011", '0'}, {"010", '0'}, {"001", '0'}, {"000", '0'}
    };
    reglas['B'] = {
        {"111", '1'}, {"110", '1'}, {"101", '0'}, {"100", '0'},
        {"011", '1'}, {"010", '1'}, {"001", '0'}, {"000", '0'}
    };
    reglas['b'] = {
        {"111", '0'}, {"110", '0'}, {"101", '1'}, {"100", '1'},
        {"011", '0'}, {"010", '0'}, {"001", '1'}, {"000", '1'}
    };

    // Definición de reglas compuestas
    map<int, map<string, string>> reglas_comp;
    reglas_comp[0] = { {"E", "AAAaaAaa"}, {"D", "CCccCccC"} };
    reglas_comp[1] = { {"E", "AaaAaaAA"}, {"D", "ccCccCCC"} };
    reglas_comp[2] = { {"E", "aAaaAAAa"}, {"D", "CccCCCcc"} };
    reglas_comp[3] = { {"E", "aaAAAaaA"}, {"D", "cCCCccCc"} };
    reglas_comp[4] = { {"E", "CCcCCccc"}, {"D", "aAAaAAaa"} };
    reglas_comp[5] = { {"E", "ccCCcCCc"}, {"D", "aaaAAaAA"} };
    reglas_comp[6] = { {"E", "CcccCCcC"}, {"D", "AAaaaAAa"} };
    reglas_comp[7] = { {"E", "cCCcccCC"}, {"D", "AaAAaaaA"} };
    reglas_comp[8] = { {"E", "BBbBCaca"}, {"D", "BBbBcAca"} };
    reglas_comp[9] = { {"E", "bcABcABb"}, {"D", "bCaBCaBb"} };
    reglas_comp[10] = { {"E", "CabbBCaB"}, {"D", "cAbbBcAB"} };
    reglas_comp[11] = { {"E", "BbcabbCA"}, {"D", "bBcAbbCA"} };
    reglas_comp[12] = { {"E", "bcACAbbB"}, {"D", "bCaCAbbB"} };
    reglas_comp[13] = { {"E", "bBbcACAb"}, {"D", "bBbCaCAb"} };
    reglas_comp[14] = { {"E", "CABcaBbb"}, {"D", "CABcaBbb"} };
    reglas_comp[15] = { {"E", "BbcAbcAB"}, {"D", "BbCabCaB"} };
    // Puedes agregar más reglas si es necesario...

    // Selección de la cadena de reglas según índice y acción
    string cadena_rule = reglas_comp[indice][accion];

    // Proceso de evolución de la cadena
    vector<char> cadena_actual(cadena.begin(), cadena.end());
    vector<char> nueva_cadena;
    for (int i = 0; i < cadena_actual.size(); i++) {
        char izquierda = (i > 0) ? cadena_actual[i - 1] : cadena_actual.back();
        char centro = cadena_actual[i];
        char derecha = (i < cadena_actual.size() - 1) ? cadena_actual[i + 1] : cadena_actual[0];

        string vecindad;
        vecindad += izquierda;
        vecindad += centro;
        vecindad += derecha;
        nueva_cadena.push_back(reglas[cadena_rule[i]][vecindad]);
    }

    cadena_actual = nueva_cadena;

    // Convertir el resultado en un string final
    cadena = string(cadena_actual.begin(), cadena_actual.end());
}

// Función para obtener las claves de encriptación
vector<int> rule30(vector<vector<string>> blocks) {
    string lista_base = "";
    map<string, char> regla30;
    regla30["111"] = '0';
    regla30["110"] = '0';
    regla30["101"] = '0';
    regla30["100"] = '0';
    regla30["011"] = '1';
    regla30["010"] = '1';
    regla30["001"] = '1';
    regla30["000"] = '1';
   
    // Generar la lista de 256 bits
    for (int i = 0; i < 32; i++) {
        srand(time(0));
        int valor = rand() % 24 + 2;
        lista_base += blocks[valor][i];
    }

    // Obtener el número de iteraciones de la regla 30
    string numero_iteraciones = blocks[0][8].substr(0, 4);  // Primeros 4 bits de la cadena
    bitset<4> num_iteraciones(numero_iteraciones);
    unsigned long base_10_iteraciones = num_iteraciones.to_ullong();

    // Recorrido del string generado
    vector<char> cadena_actual(lista_base.begin(), lista_base.end());
    vector<char> nueva_cadena;

    for (int iteracion = 0; iteracion < base_10_iteraciones; iteracion++) {
        for (int i = 0; i < cadena_actual.size(); i++) {
            char izquierda = (i > 0) ? cadena_actual[i - 1] : cadena_actual.back();
            char centro = cadena_actual[i];
            char derecha = (i < cadena_actual.size() - 1) ? cadena_actual[i + 1] : cadena_actual[0];
            string vecindad;
            vecindad += izquierda;
            vecindad += centro;
            vecindad += derecha;
            nueva_cadena.push_back(regla30[vecindad]);
        }
        cadena_actual = nueva_cadena;
        nueva_cadena.resize(0);
    }

    // Convertir a lista de índices
    vector<int> valores_encriptacion;
    string cadena_indice = "";
    for (int i = 0; i < cadena_actual.size(); i++) {
        cadena_indice += cadena_actual[i];
        if (cadena_indice.size() == 4) {
            bitset<4> num_cad_indice(cadena_indice);
            valores_encriptacion.push_back(num_cad_indice.to_ullong());
            cadena_indice = "";
        }
    }
    return valores_encriptacion;
}

// Encriptación utilizando las reglas definidas
void encriptacion(vector<vector<string>>& blocks, string accion, vector<int> key) {
    int cant_blocks = blocks.size();
    for (int t = 0; t < 5; t++) {
        for (int i = 0; i < cant_blocks; i++) {
            for (int pixel = 0; pixel < size_block; pixel++) {
                string num_pixel = blocks[i][pixel];
                // Aplicar reglas de encriptación
                iden_reglas_compuestas(num_pixel, accion, key[pixel]);
                blocks[i][pixel] = num_pixel;  // Actualizar el bloque con el pixel encriptado
            }
        }
    }
}

// Función para reconstruir la imagen a partir de los bloques encriptados
void encriptacion_img(const vector<vector<string>>& blocks, const string& output_file) {
    cv::Mat image = cv::Mat::zeros(256, 256, CV_8UC1);
    int block_idx = 0;
    for (int i = 0; i < image.rows; i += blockSize) {
        for (int j = 0; j < image.cols; j += blockSize) {
            for (int y = 0; y < blockSize; y++) {
                for (int g = 0; g < blockSize; g++) {
                    uint8_t pixel_value = static_cast<uint8_t>(bitset<8>(blocks[block_idx][y * blockSize + g]).to_ulong());
                    image.at<uint8_t>(i + y, j + g) = pixel_value;
                }
            }
            block_idx++;
        }
    }
    cv::imwrite(output_file, image);
    cout << "La img ha sido encriptada";
}

// Imprimir lista
void print(const vector<int>& lista) {
    cout << "[ ";
    for (int i = 0; i < lista.size(); i++) {
        cout << lista[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    string name_file, accion;
    cout << "Ingrese el nombre del archivo: ";
    cin >> name_file;
    cout << "Que desea hacer con el archivo E(Encriptar) o D(Decifrar): ";
    cin >> accion;

    cv::Mat img = cv::imread(name_file, cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        cerr << "Error: no se pudo cargar la imagen." << endl;
        return -1;
    }

    vector<vector<string>> bloques = procesamiento_Bloques(img, 8);
    if (accion == "E") {
        vector<int> key = rule30(bloques);
        encriptacion(bloques, accion, key);
        cout << "Su llave de encriptacion es: ";
        print(key);
        encriptacion_img(bloques, "D:/img_decifradas/negra_0.jpg");
    }
    else if (accion == "D") {
        // Aquí debes proporcionar una clave válida de descifrado para 'key'.
        vector<int> key; // Asumimos que el usuario proporciona la clave.
        encriptacion(bloques, accion, key);
        encriptacion_img(bloques, "imagen_decifrada.png");
    }
    else {
        cout << "Acción no válida." << endl;
    }

    return 0;
}
