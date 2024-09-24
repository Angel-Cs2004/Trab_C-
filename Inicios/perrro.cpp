#include <iostream>
#include <cmath>  
using namespace std;

int main(int argc, char *argv[])
{
    int v[] = {600, 470, 170, 430, 300}; 
    int sum = 0;
    float media, varianza, desv;
    int count = 0; 

    // Calcular la media
    for (int i = 0; i < 5; i++) {
        sum += v[i];
    }
    media = sum / 5.0;
    cout << "Media: " << media << endl;

    // Calcular la varianza
    sum = 0; 
    for (int i = 0; i < 5; i++) {
        sum += (v[i] - media) * (v[i] - media);
    }
    varianza = sum / 5.0;
    cout << "Varianza: " << varianza << endl;

    // Calcular la desviación estándar
    desv = sqrt(varianza);
    cout << "Desviación estándar: " << desv << endl;

    // Contar los elementos que están dentro de una desviación estándar de la media
    for (int i = 0; i < 5; i++) {
        if ((media - desv) <= v[i] && v[i] <= (media + desv)) {
            count++;
        }
    }

    cout << "Cantidad de valores dentro de una desviación estándar: " << count << endl;

    return 0;
}
