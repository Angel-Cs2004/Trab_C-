// 15. En una playa de estacionamiento cobran S/. 2.00 por hora o fracción los días Lunes, Martes y
// Miércoles, S/. 2.50 los días Jueves y Viernes, S/. 3.00 los días Sábado y Domingo. Se
// considera fracción de hora cuando haya pasado de 5 minutos. Diseñe un programa que
// determine cuánto debe pagar un cliente por su estacionamiento en un solo día de la semana. Si
// el tiempo ingresado es incorrecto imprima un mensaje de error.
#include<iostream>
using namespace std;
int main (){
    string dias[7]= {"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"};
    string dia;
    int hora,min,extra,total;
    float c_u;
    cout<<"En que dia se encuentra: ";cin>>dia;
    if(dias[0]==dia || dias[1]==dia){
        c_u=2;
        cout<<"Cuanta horas  con  minutos estuvo: ";cin>>hora>>min;
        extra =(min>5)?c_u*1:c_u*0 ;
        total=hora*c_u+extra;
        cout<<"Total a pagar es: "<<total;
    }
    else if (dias[6]==dia || dias[5]==dia){
        c_u=3;
        cout<<"Cuantas horas con minutos estuvo:  ";cin>>hora>>min;
        extra =(min>5)?c_u*1:c_u*0 ;
        total=hora*c_u+extra;
        cout<<"Total a pagar es: "<<total;
    }
    else{
        c_u=2.5;
        cout<<"Cuantas horas con min estuvo: ";cin>>hora>>min;
        extra =(min>5)?c_u*1:c_u*0 ;
        total=hora*c_u+extra;
        cout<<"Total a pagar es: "<<total;
    }
}
