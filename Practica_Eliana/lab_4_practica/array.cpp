#include<iostream>
#include<string>
#include<vector>

int ingresar(int A[]){
    int size;
    std::cout<<"Ingrese el valor que desea: "; 
    std::cin>>size;
    for (size_t i = 0; i < size; i++)
    {
        std::cout<<"Ingrese un valor para "<<"["<<i<<"]: "; 
        std::cin>>A[i];
        std::cout<<std::endl;
    } 
    return size;     
}

void mostrar(int A[],int size){
    for (size_t i = 0; i <size ;i++)
    {
        std::cout<<A[i]<<" ";
    }
    std::cout<<std::endl;
    
}

int mayor(int A[],int size){
    int mayor=A[0];
    for (size_t i = 0; i < size; i++)
    {
        if(A[i]>mayor){
            mayor=A[i];
        }
    }
    return mayor;
}

void repetidas(int A[],int size){
    for (size_t i = 0; i < size; i++)
    {
        int contador=0;
        bool repetido=false;
        for (size_t j = 0; j < size; j++)
        {
            if(i>j && A[i]==A[j]){
                repetido=true;
                break;
            }
        }
        if(repetido){
            continue;
        } else {
            for (size_t k = 0; k < size; k++){
                if(A[i]==A[k]){
                    contador++;
                }
            }
            std::cout<<"El numero de veces repetido del elemento "<<"["<<A[i]<<"] es: "<<contador<<std::endl;
        }
    }
}

void sec_array(int A[],int size){
    std::vector<int> B;
    for (size_t i = 0; i < size; i++)
    {
        bool repetido=false;
        for (size_t j = 0; j < size; j++)
        {
            if(i>j && A[i]==A[j]){
                repetido=true;
                break;
            }
        }
        if(repetido){
            continue;
        } else {
            B.push_back(A[i]);
        }
    }
    std::cout<<"El array sin repetir es: ";
    for(int val : B){
        std::cout << val << " ";
    }
    std::cout << std::endl;  // Asegúrate de tener un salto de línea después de mostrar el array
}

int main(){
    int size,size_i;
    std::cout<<"Ingrese el tamano del array: "; 
    std::cin>>size;
    int A[size];
    size_i=ingresar(A);
    mostrar(A,size_i);
    std::cout<<"El mayor de toda la lista es: "<<mayor(A,size_i)<<std::endl;
    repetidas(A,size_i);
    sec_array(A,size_i);
}