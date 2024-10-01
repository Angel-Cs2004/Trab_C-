// 12. Se desea resolver 3 operaciones básicas de enteros (+, - y *) sobrecargando lo menos posible el procesador del computador. Para ello, los expertos han dicho que la forma de hacer que el procesador trabaje lo menos posible es solamente haciendo sumas.
// Es por ello que desean que usted programe el siguiente diálogo para la calculadora básica:

// Ingrese el valor de a? 7
// Ingrese el valor de b? 3
// a y b los quiere...
// 1) sumar
// 2) restar
// 3) multiplicar
// Ingrese operación? 2
// ummm... la resta de 7 y 3 es 4

// Ingrese el valor de a? 1
// Ingrese el valor de b? 3
// a y b los quiere...
// 1) sumar
// 2) restar
// 3) multiplicar

// Ingrese operación? 5
// NO EXISTE OPERACION
// Ingrese el valor de a? _
// ...
// Realice este programa recordando que:
// a + b = a + b
// a - b = a + (-b)
// a x b = a + a + a + ... + a (b veces)
// Hint: Suponga que el ciclo de la calculadora es infinito.
#include<iostream>;
int main(int argc, char*argv[]){
    int a,b,opcion;
    int mult=0;
    std::cout<<"Ingrese el valor de a: ";std::cin>>a;
    std::cout<<"\nIngrese el valor de b: ";std::cin>>b;
    std::cout<<"\nELIJA LA OPERCION QUE DESEA REALIZAR: \n1)sumar\n2)restar\n3)multiplicar\n";
    std::cout<<"Ingrese operacion: ";
    std::cin>>opcion;
    switch (opcion)
    {
    case 1: 
        std::cout<<"La suma de "<<a<<" y "<<b<<" es "<<a+b;
        break;

    case 2:
        std::cout<<"La resta de "<<a<<" y "<<b<<" es "<<a+(-b);
        break;

    case 3:
        for(int i=0;i<b;i++){
            mult+=a;
        }
        std::cout<<"La multiplicacion de "<<a<<" y "<<b<<" es "<<mult;
        break;

    default:
        std::cout<<"NO EXISTE OPERACION ";
        break;
    }
    return 0;
}