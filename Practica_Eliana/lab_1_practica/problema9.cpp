#include <iostream>
#include <cstdlib>  // Para rand()
#include <ctime>    // Para time()

using namespace std;
int main() {
    srand(time(0));
    cout<<"El comaprador no aplica a la promocion"<<endl;
    const int valor_prom = 100;
    int cant,precio;
    int radom= rand() % 5 + 1;
    float desc;
    cout<<"Ingresar la cantidad de cosas que compro: "<<endl;cin>>cant;
    cout<<"Ingresar el precio de tales productos: "<<endl;cin>>precio;
    int total = cant*precio;
    if(total<100){
        cout<<"Por la cantidad no aplica al descuento "<<endl;
    }
    else{
        switch(radom){
            case 1:
                cout<<"No tiene descuento, su bola es BLANCA."<<endl;
                break;
            case 2:
                cout<<"Tiene descuento, su bola es ROJO."<<endl;
                desc=0.10;
                break;
            case 3:
                cout<<"Tiene descuento, su bola es AZUL."<<endl;
                desc=0.20;
                break;
            case 4:
                cout<<"Tiene descuento, su bola es VERDE."<<endl;
                desc=0.25;
                break;
            case 5:
                cout<<"Tiene descuento, su bola es AMARILLA."<<endl;
                desc=0.50;
                break;
           
            default:
                cout<<"No tiene descuento, su bola distinta a las permitidas"<<endl;
                break;
        }
        if(!(radom!=0 && radom!=1 && radom>5)){
            cout<<"felicidades, ha obtenido un descuento del "<<desc*100<<"%"<<endl;
            cout<<"Su nuevo total a pagar es: "<<(1-desc)*total<<endl;
        }
    }
    return 0;
} 