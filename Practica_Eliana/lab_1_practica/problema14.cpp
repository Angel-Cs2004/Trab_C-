// 14. Dadas dos tanques llenos de agua cuyas capacidades están dadas en litros y en yardas cúbicas.
// De la cantidad total de agua: el 75% se dedica al consumo doméstico y el 25% se dedica al
// riego. Diseñe un programa que haga lo siguiente:
// Determine la cantidad total de agua expresada en metros cúbicos y en pies cúbicos.
// Determine las cantidades de agua dedicada al riego y al consumo doméstico expresada en
// metros cúbicos y en pies cúbicos. Considere los siguientes factores de conversión:
// 1 pie cúbico = 0.0283 metros cúbicos, 1 metro cúbico = 1000 litros, 1 yarda cúbica = 27 pies
// cúbicos.
#include<iostream>
using namespace std;
int main (){
    float c1,c2,total;
    //covercion de litras a m3 and pies
    const float yardas_mcub = 0.76,metros_yardas = 35;
    const float litros_c1=0.001,pies_c2=0.037;
    //coversion de pies cub a m3 and pies
    // const float litros_c2=pies_c2=;
    cout<<"Ingrese la capacidad del tanque 1 en litros: ";cin>>c1;
    cout<<"Ingrese la capacidad del tanque 2 en yadas cubicas: ";cin>>c2;
   //cant de total
    total = c1*litros_c1+ c2*yardas_mcub;
    cout<<"El total en metros cubicos es: "<<total<<endl;
    cout<<"El total en yardas cubicas es: "<<total*35<<endl;
   //c1==litros
    cout<<"Cantidad de agua reservada para riesgos  de tanque 1 es: "<<c1*litros_c1*0.25<<"m3  y "<< c1*litros_c1*metros_yardas*0.25<<"pies "<<endl;
    cout<<"Cantidad de agua reservada para uso domestico de tanque 1 es: "<<c1*litros_c1*0.75<<"m3 y "<< c1*litros_c1*metros_yardas*0.75<<"pies "<<endl;
   //c2=yardas
    cout<<"Cantidad de agua reservada para riesgos  de tanque 2 es: "<<c2*yardas_mcub*0.25<<"m3 y "<<c2*pies_c2*0.25<<"pies "<<endl;
    cout<<"Cantidad de agua reservada para uso domestico de tanque 2 es: "<<c2*yardas_mcub*0.75<<"m3 y "<<c2*pies_c2*.75<<"pies "<<endl;
}
