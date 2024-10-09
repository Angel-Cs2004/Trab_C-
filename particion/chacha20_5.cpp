#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <cstring>
#include <sodium.h>

using namespace std;
namespace fs = std::filesystem;

const size_t size_block = 1024;

char** particion(const string& nom_archv, int& num_bloques, const string& key_hex, const string& nonce_hex, string& direcciones_concatenadas) {
    ifstream archv(nom_archv, ios::binary);
    if (!archv) {
        cout << "No se logró particionar " << nom_archv << endl;
        return nullptr;
    }

    archv.seekg(0, ios::end);
    size_t tam_archv = archv.tellg();
    archv.seekg(0, ios::beg);
    num_bloques = (tam_archv + size_block - 1) / size_block;

    char** bloques = new char*[num_bloques];
    direcciones_concatenadas.clear();

    for (int i = 0; i < num_bloques; i++) {
        bloques[i] = new char[size_block + 4];
        if (archv.read(bloques[i], size_block)) {
            string direccion = to_string(reinterpret_cast<uintptr_t>(bloques[i]));
            direcciones_concatenadas += direccion + ",";
            strcat(bloques[i], direccion.c_str());
        } else if (archv.gcount() > 0) {
            memset(bloques[i] + archv.gcount(), 0, size_block - archv.gcount());
        }
    }

    archv.close();
    
    unsigned char key[crypto_secretbox_KEYBYTES];
    unsigned char nonce[crypto_secretbox_NONCEBYTES];
    for (size_t i = 0; i < crypto_secretbox_KEYBYTES; ++i) {
        sscanf(key_hex.substr(i * 2, 2).c_str(), "%2hhx", &key[i]);
    }
    for (size_t i = 0; i < crypto_secretbox_NONCEBYTES; ++i) {
        sscanf(nonce_hex.substr(i * 2, 2).c_str(), "%2hhx", &nonce[i]);
    }

    size_t ciphertext_len = direcciones_concatenadas.size() + crypto_secretbox_MACBYTES;
    unsigned char* ciphertext = new unsigned char[ciphertext_len];
    crypto_secretbox_easy(ciphertext, (const unsigned char*)direcciones_concatenadas.c_str(), direcciones_concatenadas.size(), nonce, key);
    
    delete[] ciphertext;

    return bloques;
}

void liberar_memoria(char** bloques, int num_bloques) {
    for (int i = 0; i < num_bloques; i++) {
        delete[] bloques[i];
    }
    delete[] bloques;
}

int main() {
    string name_file;
    char** bloques;
    int num_bloques = 0;
    string key_hex, nonce_hex, direcciones_concatenadas;

    cout << "Ingrese la clave (32 caracteres hexadecimales): ";
    cin >> key_hex;
    cout << "Ingrese el nonce (24 caracteres hexadecimales): ";
    cin >> nonce_hex;
    cout << "Ingrese el nombre del archivo: ";
    cin >> name_file;

    bloques = particion(name_file, num_bloques, key_hex, nonce_hex, direcciones_concatenadas);

    if (bloques != nullptr) {
        cout << "\nEl archivo " << name_file << " se ha particionado en " << num_bloques << " bloques." << endl;
        cout << "Direcciones concatenadas: " << direcciones_concatenadas << endl;
        liberar_memoria(bloques, num_bloques);
    }

    return 0;
}
