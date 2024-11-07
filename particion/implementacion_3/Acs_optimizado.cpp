#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

const size_t size_block = 64;
const int blockSize = 8;

vector<vector<string>> procesamiento_Bloques(const cv::Mat& img, int blockSize) {
    vector<vector<string>> blocks;
    blocks.reserve((img.rows / blockSize) * (img.cols / blockSize));
    vector<string> block;
    block.reserve(size_block);

    for (int i = 0; i < img.rows; i += blockSize) {
        for (int j = 0; j < img.cols; j += blockSize) {
            block.clear();
            for (int y = i; y < (i + blockSize); y++) {
                for (int g = j; g < (j + blockSize); g++) {
                    block.push_back(bitset<8>(img.at<uint8_t>(y, g)).to_string());
                }
            }
            blocks.push_back(block);
        }
    }
    return blocks;
}

void iden_reglas_compuestas(string& cadena, const string& accion, int indice) {
    static const unordered_map<char, unordered_map<string, char>> reglas = {
        {'a', {{"111", '0'}, {"110", '0'}, {"101", '0'}, {"100", '0'},
               {"011", '1'}, {"010", '1'}, {"001", '1'}, {"000", '1'}}},
        {'c', {{"111", '0'}, {"110", '1'}, {"101", '0'}, {"100", '1'},
               {"011", '0'}, {"010", '1'}, {"001", '0'}, {"000", '1'}}},
        {'C', {{"111", '1'}, {"110", '0'}, {"101", '1'}, {"100", '0'},
               {"011", '1'}, {"010", '0'}, {"001", '1'}, {"000", '0'}}},
        {'A', {{"111", '1'}, {"110", '1'}, {"101", '1'}, {"100", '1'},
               {"011", '0'}, {"010", '0'}, {"001", '0'}, {"000", '0'}}},
        {'B', {{"111", '1'}, {"110", '1'}, {"101", '0'}, {"100", '0'},
               {"011", '1'}, {"010", '1'}, {"001", '0'}, {"000", '0'}}},
        {'b', {{"111", '0'}, {"110", '0'}, {"101", '1'}, {"100", '1'},
               {"011", '0'}, {"010", '0'}, {"001", '1'}, {"000", '1'}}}
    };

    static const vector<pair<string, string>> reglas_comp[] = {
        {{"E", "AAAaaAaa"}, {"D", "CCccCccC"}},
        {{"E", "AaaAaaAA"}, {"D", "ccCccCCC"}},
        {{"E", "aAaaAAAa"}, {"D", "CccCCCcc"}},
        {{"E", "aaAAAaaA"}, {"D", "cCCCccCc"}},
        {{"E", "CCcCCccc"}, {"D", "aAAaAAaa"}},
        {{"E", "ccCCcCCc"}, {"D", "aaaAAaAA"}},
        {{"E", "CcccCCcC"}, {"D", "AAaaaAAa"}},
        {{"E", "cCCcccCC"}, {"D", "AaAAaaaA"}},
        {{"E", "BBbBCaca"}, {"D", "BBbBcAca"}},
        {{"E", "bcABcABb"}, {"D", "bCaBCaBb"}},
        {{"E", "CabbBCaB"}, {"D", "cAbbBcAB"}},
        {{"E", "BbcabbCA"}, {"D", "bBcAbbCA"}},
        {{"E", "bcACAbbB"}, {"D", "bCaCAbbB"}},
        {{"E", "bBbcACAb"}, {"D", "bBbCaCAb"}},
        {{"E", "CABcaBbb"}, {"D", "CABcaBbb"}},
        {{"E", "BbcAbcAB"}, {"D", "BbCabCaB"}}
    };

    const string& cadena_rule = reglas_comp[indice % 16][accion == "E" ? 0 : 1].second;
    vector<char> nueva_cadena(cadena.size());

#pragma omp parallel for
    for (int i = 0; i < cadena.size(); i++) {
        string vecindad;
        vecindad.reserve(3);
        vecindad += (i > 0) ? cadena[i - 1] : cadena.back();
        vecindad += cadena[i];
        vecindad += (i < cadena.size() - 1) ? cadena[i + 1] : cadena[0];
        nueva_cadena[i] = reglas.at(cadena_rule[i]).at(vecindad);
    }

    cadena.assign(nueva_cadena.begin(), nueva_cadena.end());
}

vector<int> rule30(const vector<vector<string>>& blocks) {
    string lista_base;
    lista_base.reserve(256);

    static const unordered_map<string, char> regla30 = {
        {"111", '0'}, {"110", '0'}, {"101", '0'}, {"100", '0'},
        {"011", '1'}, {"010", '1'}, {"001", '1'}, {"000", '1'}
    };

    for (int i = 0; i < 32; i++) {
        srand(time(0));
        int valor = rand() % 24 + 2;
        lista_base += blocks[valor][i];
    }

    bitset<4> num_iteraciones(blocks[0][8].substr(0, 4));
    unsigned long base_10_iteraciones = num_iteraciones.to_ullong();

    vector<char> cadena_actual(lista_base.begin(), lista_base.end());
    vector<char> nueva_cadena(cadena_actual.size());

    for (int iteracion = 0; iteracion < base_10_iteraciones; iteracion++) {
#pragma omp parallel for
        for (int i = 0; i < cadena_actual.size(); i++) {
            string vecindad;
            vecindad.reserve(3);
            vecindad += (i > 0) ? cadena_actual[i - 1] : cadena_actual.back();
            vecindad += cadena_actual[i];
            vecindad += (i < cadena_actual.size() - 1) ? cadena_actual[i + 1] : cadena_actual[0];
            nueva_cadena[i] = regla30.at(vecindad);
        }
        cadena_actual = nueva_cadena;
    }

    vector<int> valores_encriptacion;
    valores_encriptacion.reserve(cadena_actual.size() / 4);

    for (int i = 0; i < cadena_actual.size(); i += 4) {
        string cadena_indice(cadena_actual.begin() + i, cadena_actual.begin() + i + 4);
        valores_encriptacion.push_back(bitset<4>(cadena_indice).to_ulong());
    }

    return valores_encriptacion;
}

void encriptacion(vector<vector<string>>& blocks, const string& accion, const vector<int>& key) {
#pragma omp parallel for collapse(2)
    for (int t = 0; t < 11; t++) {
        for (int i = 0; i < blocks.size(); i++) {
            for (int pixel = 0; pixel < size_block; pixel++) {
                string num_pixel = blocks[i][pixel];
                iden_reglas_compuestas(num_pixel, accion, key[pixel]);
                blocks[i][pixel] = num_pixel;
            }
        }
    }
}

void encriptacion_img(const vector<vector<string>>& blocks, const string& output_file) {
    cv::Mat image(256, 256, CV_8UC1);

#pragma omp parallel for collapse(2)
    for (int i = 0; i < image.rows; i += blockSize) {
        for (int j = 0; j < image.cols; j += blockSize) {
            int block_idx = (i / blockSize) * (image.cols / blockSize) + (j / blockSize);
            for (int y = 0; y < blockSize; y++) {
                for (int g = 0; g < blockSize; g++) {
                    image.at<uint8_t>(i + y, j + g) =
                        static_cast<uint8_t>(bitset<8>(blocks[block_idx][y * blockSize + g]).to_ulong());
                }
            }
        }
    }

    cv::imwrite(output_file, image);
    cout << "La img ha sido encriptada\n";
}

int main() {
    string name_file, accion;
    cout << "Ingrese el nombre del archivo: ";
    cin >> name_file;
    cout << "Que desea hacer con el archivo E(Encriptar) o D(Decifrar): ";
    cin >> accion;

    cv::Mat img = cv::imread(name_file, cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        cerr << "Error: no se pudo cargar la imagen.\n";
        return -1;
    }

    vector<vector<string>> bloques = procesamiento_Bloques(img, 8);

    if (accion == "E") {
        vector<int> key = rule30(bloques);
        encriptacion(bloques, accion, key);
        cout << "Su llave de encriptacion es: [ ";
        for (int k : key) cout << k << " ";
        cout << "]\n";
        encriptacion_img(bloques, "D:/img_decifradas/negra_10.jpg");
    }
    else if (accion == "D") {
        vector<int> key;
        cout << "Ingrese la llave de desencriptación (64 números): ";
        for (int i = 0; i < 64; i++) {
            int k;
            cin >> k;
            key.push_back(k);
        }
        encriptacion(bloques, accion, key);
        encriptacion_img(bloques, "imagen_decifrada.png");
    }
    else {
        cout << "Acción no válida.\n";
    }

    return 0;
}