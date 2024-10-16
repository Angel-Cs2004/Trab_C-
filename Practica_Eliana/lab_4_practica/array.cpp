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

void inversa(int A[], int size) {
    if (size == 1) { // Cambié el caso base a size == 1
        std::cout << A[0];
    } else {
        std::cout << A[size - 1] << " ";
        inversa(A, size - 1); // La llamada recursiva debe estar sola
    }
}
void inversa_i(int A[],int size){
    std::cout<<std::endl;
    for (int i = size-1; i >=0; i--)
    {
        std::cout<<A[i]<<" ";
    }
    std::cout<<std::endl;
}
int sumatoria(int A[], int size) {
    if(size==0 ||size==-1){
        return 0;
    }
    if(size%2==0){
            return A[size-2] + sumatoria(A,size-2);
    }else{
            return A[size-1] + sumatoria(A,size-2);
    }
}
int sumatoria_i(int A[],int size){
    std::cout<<std::endl;
    int sumatoria=0;
    for (int i = 0; i<size; i+=2)
    {
        sumatoria+=A[i];
    }
    return sumatoria;
}

void eliminar(int A[],int size,int posicion){
  
    for(int k=posicion;k<size-1;k++){
        A[k]=A[k+1];
    }
    A[size - 1]=0;
    mostrar(A,size);
}

void agregar(int A[],int size,int posicion,int valor){
    std::cout<<std::endl;
    int C[size+1];
    for(int i=0;i<size+1;i++){
        if(i!=posicion && i<posicion){
            C[i]=A[i];
        }else if(i!=posicion && i>posicion){
            C[i]=A[i-1];
        }else{
            C[i]=valor;
        }
    }
    mostrar(C,size+1);
}
//La otra opcion de IA
// void agregar(int A[],int size,int posicion,int valor){
//     std::cout<<std::endl;
//     for(int i=size;i>=posicion;i--){
//         A[i]=A[i-1];
//     }
//     A[posicion]=valor;
//     mostrar(A,size+1);
// }

int main(){
    int size,size_i;
    std::cout<<"Ingrese el tamano del array: "; 
    std::cin>>size;
    int A[size]={0};
    mostrar(A,size);
    size_i=ingresar(A);
    mostrar(A,size_i);
    std::cout<<"El mayor de toda la lista es: "<<mayor(A,size_i)<<std::endl;
    repetidas(A,size_i);
    sec_array(A,size_i);
    inversa(A,size_i);
    inversa_i(A,size_i);
    std::cout<<"La sumatoria del array A[]: "<<sumatoria_i(A,size_i);
    std::cout<<std::endl;
    std::cout<<sumatoria(A,size_i);
    int posicion=2;
    int valor=69;
    std::cout<<"\nLa agregacion: ";
    agregar(A,size_i,posicion,valor);
    std::cout<<"\nEl valor del array es: ";
    eliminar(A,size_i,posicion);
    
    
}
