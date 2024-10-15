/*7. El programa irá preguntando por la cantidad de billetes y monedas de cada valor que tiene el
usuario y luego determinará la suma de dinero que hay en monedas y luego la suma de dinero
que hay en billetes. Luego el programa dirá la suma total de dinero que hay. Finalmente, el
programa dará al usuario la posibilidad de transformar la cantidad en soles a la cantidad
equivalente en dólares o euros, según lo decida el usuario.*/
#include <iostream>
#include <string>
using namespace std;
int main() {
    float billetes,monedas;
    float total_b,total_m,v_billetes,v_monedas;
    string rpta,bol;
    cout<<"Ingrese la cantidad de billetes: "<<endl;cin>>billetes;
    cout<<"Ingrese la cantidad de monedas: "<<endl;cin>>monedas;
    cout<<"Ingrese el valor de los billetes: "<<endl;cin>>v_billetes;
    cout<<"Ingrese el valor de las monedas: "<<endl;cin>>v_monedas;
    total_b=billetes*v_billetes;
    total_m=monedas*v_monedas;
    cout<<"Su total en billetes: "<<total_b<<endl;
    cout<<"Su total en monedas: "<<total_m<<endl;
    cout<<"El total en billetes y monedas: "<<total_b+total_m<<endl;
    cout<<"Desea transformarlo (y/n): ";cin>>rpta;
    if( rpta=="y"){
        cout<<"A que desea tranformarlo euros(e) o dolares(d): ";cin>>bol;
        if(bol=="e"){
            cout<<"Su valor en euros es: "<<(total_b+total_m)*0.24<<endl;
        }
        else if (bol=="d"){
            cout<<"Su valor en dolares es: "<<(total_b+total_m)*0.27<<endl;
        }
        else{
            cout<<"Pon bien oe!!!! chivolo pavo "<<endl;
        }
    }
    else if(rpta=="n"){
        cout<<"Proceso terminado.";
    }
    
    
    return 0;
}
