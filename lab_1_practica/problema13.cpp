// 13. El usuario introduce el total de puntos de 3 equipos de futbol. El programa determinara qué
// equipo va en primero, segundo y tercer lugar o si hay empate en puntos entre algunos equipos,
// dirá quiénes van empatados y en qué lugar están empatados. Luego el programa dirá cuántos
// puntos le faltan al segundo lugar para alcanzar al primer lugar y cuántos puntos le faltan al
// tercer lugar para alcanzar al segundo lugar, y en caso de haber empates en puntos, el programa
// hará saber quiénes están empatados en puntos, en qué lugar de la tabla de posiciones empatan
// y cuántos puntos les falta a ambos para alcanzar a otro equipo o para que los alcancen a ellos.
// Si los tres equipos empatan en puntos, el programa dirá que los tres empatan.
/*dame los puntos del equipo 1: 
ordenamiento burbuja== geraquia o empate
van empartados en x posicion
a 2do lugar le falta y puntos para el primero 
a 3ro lugar le falta y puntos para el 2do ==> si hay empate 
si el 2do y 3ro empates, indicar y decir cuanto le falta para el primer
caso en qeu los tres sena empates*/
#include<iostream>
#include<string>
using namespace std;
int main (){
    int puntaje[3];// pensado para tener los mismos indices
    string equipos[3] = {"Naira","Tamara","Daniela"}; //pensado para tener los mismos indices
    string puestos[3] = {"tercer","segundo","primero"}; //ya esta ordenado
    for(int i=0;i<3;i++){
        int puntos;
        cout<<"Ingresa los puntos de el equipo "<<equipos[i]<<": ";cin>>puntos;
        puntaje[i]=puntos;
    }
    for(int i=0;i<3-1;i++){
        for(int j=0;j<3-i-1;j++){
            if(puntaje[j]>puntaje[j+1]){
                int temp=puntaje[j];
                string temp_equipos=equipos[j];
                puntaje[j]=puntaje[j+1];puntaje[j+1]=temp;
                equipos[j]=equipos[j+1];equipos[j+1]=temp_equipos;
            }
        }
    }
    if(puntaje[0]==puntaje[1] && puntaje[1]==puntaje[2] && puntaje[0]==puntaje[2]){
        cout<<"Hay empate absoluto"<<endl;
        
    }
    else if(puntaje[0]==puntaje[1] || puntaje[1]==puntaje[2] || puntaje[0]==puntaje[2]) {
        for(int i=0;i<3-1;i++){
            if (puntaje[i]==puntaje[i+1]){
                if(i==1){
                    cout<<"Hay empate entre "<<equipos[i]<<" y "<<equipos[i+1]<<endl;
                    cout<<"Empatados en el "<<puestos[i+1]<<" puesto"<<endl;
                    cout<<"Al segundo equipo le falta "<<(puntaje[2]-puntaje[0])<<" puntos para alcanzarlos"<<endl;
                }
                else{
                    cout<<"Hay empate entre "<<equipos[i]<<" y "<<equipos[i+1]<<endl;
                    cout<<"Empatados en el "<<puestos[i+1]<<" puesto"<<endl;
                    cout<<"Les falta "<<puntaje[2]-puntaje[0]<<" puntos para alcanzar al primero"<<endl;
                }
            }
        }
        if(puntaje[0]==puntaje[2]){
            cout<<"Hay empate entre "<<equipos[0]<<" y "<<equipos[2]<<endl;
            cout<<"Empatados en el "<<puestos[2]<<" puesto"<<endl;
        }      
    }
    else{
        cout<<"Al "<<puestos[1]<<" le falta "<<puntaje[2]-puntaje[1]<<" puntos para alcanzar al "<<puestos[2]<<endl;
        cout<<"Al "<<puestos[0]<<" le falta "<<puntaje[1]-puntaje[0]<<" puntos para alcanzar al "<<puestos[1]<<endl;
    }
    return 0;
}
    // if(puntaje[0]==puntaje[1] || puntaje[1]==puntaje[2] || puntaje[0]==puntaje[2]){
    //     for(int i=0;i<3-1;i++){
    //         if (puntaje[i]==puntaje[i+1]){
    //             if(i==1){
    //                 cout<<"Hay empate entre "<<equipos[i]<<" y "<<equipos[i+1]<<endl;
    //                 cout<<"Empatados en el "<<puestos[i+1]<<" puesto"<<endl;
    //                 cout<<"Al segundo equipo le falta "<<(puntaje[2]-puntaje[0])<<" puntos para alcanzarlos"<<endl;
    //             }
    //             else{
    //                 cout<<"Hay empate entre "<<equipos[i]<<" y "<<equipos[i+1]<<endl;
    //                 cout<<"Empatados en el "<<puestos[i+1]<<" puesto"<<endl;
    //                 cout<<"Les falta "<<puntaje[2]-puntaje[0]<<" puntos para alcanzar al primero"<<endl;
    //             }
    //         }
    //     }
    //     if(puntaje[0]==puntaje[2]){
    //         cout<<"Hay empate entre "<<equipos[0]<<" y "<<equipos[2]<<endl;
    //         cout<<"Empatados en el "<<puestos[2]<<" puesto"<<endl;
    //     }
    // }
    // else if(puntaje[0]==puntaje[1] && puntaje[1]==puntaje[2] && puntaje[0]==puntaje[2]) {
    //     cout<<"Al "<<puestos[1]<<" le falta "<<puntaje[2]-puntaje[1]<<" puntos para alcanzar al "<<puestos[2]<<endl;
    //     cout<<"Al "<<puestos[0]<<" le falta "<<puntaje[1]-puntaje[0]<<" puntos para alcanzar al "<<puestos[1]<<endl;
    // }