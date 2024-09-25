/*// 12. El programa determina el precio de un boleto de ida y vuelta en ferrocarril,
 conociendo la distancia a recorrer y sabiendo que si el número de días de estancia 
 es mayor o igual a 7 y la distancia mayor o igual a 100 kilómetros, el boleto tiene 
 una reducción del 50%. El precio por kilómetro es de 1 dólar.*/


 /*DISTANCIA, NRO DIAS>=7 And DISTANCIA>=100KM == 50% DESCUENTO
 1KM ==  1 dolar */
 #include<iostream>
 using namespace std;
 int main (){
    int dis,dias;
    float desc;
    cout<<"Ingresa la distancia que vas a recorrer: ";cin>>dis;
    cout<<"Cuantos dias estancia tomara: ";cin>>dias;
    if(dias>=7 && dis>=100){
        cout<<"El total a pagar es: "<<"$"<<dis*0.5<<".00";
    }
    else{
        cout<<"El total a pagar es: "<<"$"<<dis<<".00";
    }

 }