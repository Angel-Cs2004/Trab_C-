/*2. Mostrar los impares entre 1 y 100.*/
#include<iostream>
int main(int argc, char* argv[]){
    for(int i=1;i<100;i++){
        if(i%2!=0){
            std::cout<<i<<" ";
        }
    }
}