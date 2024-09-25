// 16. Diseñe un programa que ingrese un número entero positivo que no tenga más de 4 cifras y lo
// imprima completando con ceros por la izquierda de tal manera que siempre se ve con 4 cifras.
// Por ejemplo, si l número ingresado fuera 18, el resultado deberá ser 0018. Si el número
// ingresado no fuera correcto debe imprimir un mensaje de error.
/*Ingresar un natural , cifras<=4*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string cadena;
    int num;
    cout<<"Ingrese el numero: ";cin>>num;
    if(9999>=num && num>=1000){
        cout<<"Sun numero es el mismo: "<<num;
    }
    else{
        string num_st = to_string(num);   //utilizamos de la libreria standar de c++ : to_string para trnasformar int a string
        int len = num_st.size();
        for(int i=0;i<4-len;i++){
            num_st = "0"+num_st;
        }
        cout<<num_st;
    }
    return 0;
}
