#include <iostream>
#include <vector>

int main() {
    int n;
    int opcion;
    int fila;
    int columna;

    std::cout << "Introduce el tamaño de la matriz cuadrada (n x n): ";
    std::cin >> n;

    std::vector<std::vector<int>> matriz(n, std::vector<int>(n));

    std::cout << "Introduce los elementos de la matriz:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "Elemento [" << i << "][" << j << "]: ";
            std::cin >> matriz[i][j];
        }
    }

    std::cout << "Menú:\na) Leer datos\nb) Modificar datos\nc) Mostrar datos\nd) Mostrar suma de la diagonal principal\ne) Mostrar suma de la diagonal secundaria\nf) Salir\nIngrese su opción: ";
    std::cin >> opcion;
    if (opcion = 'a'); //a)	Leer Datos.
        std::cout << "Introduce los elementos de la matriz:" << std::endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << "Elemento [" << i << "][" << j << "]: ";
                std::cin >> matriz[i][j];
            }
        }
    else if (opcion = 'b');  //b)	Modificar Datos.
        cout << "Ingrese la fila y columna del elemento a modificar: ";
        cin >> fila >> columna;
        cout << "Ingrese el nuevo elemento: "; cin >> dato;
        m[fila - 1][columna] = dato;
        
    else if (opcion = 'c');  //c)	Mostrar Datos.

        std::cout << "La matriz es:" << std::endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
            std::cout << matriz[i][j] << " ";
            }
            std::cout << std::endl;
        }


    else if (opcion = 'd');  //d)	Mostrar la suma de la diagonal principal.
    int sumaDiagonalPrincipal(int matriz[][3], int tamano) {
        int suma = 0;
        for (int i = 0; i < tamano; i++) {
            suma += matriz[i][i];
        }
        return suma;
    }
    else if (opcion = 'e');  //e)	Mostrar la suma de la diagonal secundaria.
    int sumaDiagonalSecundaria(int matriz[][3], int tamano) {
        int suma = 0;
        for (int i = 0; i < tamano; i++) {
            suma += matriz[i][tamano - i - 1];
        }
        return suma;
}

    else if (opcion = "f");  //f)	Salir

    return 0;
}
