#include <iostream>

using namespace std;

void descendente(int *V,string *N, int t){
	for (int i = 0; i < 3 - 1; i++) {
		for (int j = 0; j < 3 - i - 1; j++) {
			if (V[j] < V[j + 1]) {
				swap(V[j], V[j + 1]);
				swap(N[j], N[j + 1]);
			}
		}
	}
}
	
int main() {
    int equipoA,equipoB,equipoC;
    cout << "Introduzca los puntos de cada equipo de futbol" <<'\n';
    cout << "El equipo A tuvo: "; cin >> equipoA;
    cout << "El equipo B tuvo: "; cin >> equipoB;
    cout << "El equipo C tuvo: "; cin >> equipoC;
    int vector[3]{equipoA, equipoB, equipoC};
    string nombres[3] = {"Equipo A", "Equipo B", "Equipo C"};
    descendente(vector, nombres, 3);
    if (equipoA==equipoB && equipoB==equipoC){
        cout << "Los tres equipos empatan";
    }
    else{
        if (vector[0]==vector[1]){
            vector[2] >vector[0]? cout << "El primer lugar es: "<< nombres[2]<<'\n'<< "El segundo lugar lo ocupa los equipos "<< nombres[0] <<" "<< nombres[1] <<'\n' << "Al segundo lugar le faltaron "<<vector[2]-vector[0]<<" puntos"
            : cout << "El primer lugar lo ocupan los equipos "<< nombres[0] <<" "<< nombres[1] <<'\n' << "El segundo lugar es el "<< nombres[2] <<'\n' << "Al segundo lugar le faltaron "<<vector[0]-vector[2]<<" puntos";
        }
        else if (vector[1]==vector[2]){
            vector[0] >vector[1]? cout << "El primer lugar es: "<< nombres[0]<<'\n'<< "El segundo lugar lo ocupa los equipos "<< nombres[1] <<" "<< nombres[2] <<'\n' << "Al segundo lugar le faltaron "<<vector[0]-vector[1]<<" puntos"
            : cout << "El primer lugar lo ocupan los equipos "<< nombres[1] <<" "<< nombres[2] <<'\n' << "El segundo lugar es el "<< nombres[0] <<'\n' << "Al segundo lugar le faltaron "<<vector[1]-vector[0]<<" puntos";
        }
        else{
            cout << "El primer lugar es " << nombres[0] << ", el segundo lugar es " << nombres[1] << " y el tercer lugar es " << nombres[2]<<'\n';
            cout <<"Al segundo lugar le faltaron para alcanzar al primer lugar "<< vector[0]-vector[1] << '\n';
            cout <<"Al tercer lugar le faltaron para alcanzar al segundo lugar "<< vector[1]-vector[2];
        }
    }
    return 0;
}