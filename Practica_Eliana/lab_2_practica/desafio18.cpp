// 18. En un supermercado un ama de casa pone en su carrito los artículos que va tomando de los estantes.
//  La señora quiere asegurarse de que el cajero le cobre bien lo que ella ha comprado, por lo que cada 
//  vez que toma un articulo anota su precio junto con la cantidad de artículos iguales que ha tomado y
//   determina cuanto dinero gastará en ese articulo; a esto le suma lo que ira gastando en los demás 
//   artículos, hasta que decide que ya tomo todo lo que necesitaba. Ayúdale a esta señora a no pasarse
//   de su presupuesto
#include<iostream>
bool verificador(float total_acum,float pres){
    if(total_acum<=pres){
        return true;
    }else{
        return false;
    }
}
int main (){
    int type;
    float presupuesto,precio,total_acum=0;
    std::cout<<"Cual es su presupesto? "<<std::endl;
    std::cin>>presupuesto;
    std::cout<<"Cuantos tipos articulos ha comprado: ";std::cin>>type;
    for(int i=0;i<type;i++){
        int cant,precio; 
        bool exd;
        std::cout<<"Cantidad de articulos del tipo "<<i+1<<" : "<<std::endl;std::cin>>cant; 
        std::cout<<"Precio de los articulos del tipo "<<i+1<<" : "<<std::endl;std::cin>>precio; 
        for(int i=0;i<cant;i++){
            total_acum+=precio;
            exd=verificador(total_acum,presupuesto);
            if(exd){
                continue;
            }else{
                std::cout<<"Se ha exedido del presupuesto "<<std::endl;
                std::cout<<"El total maximo a pagar es de: "<<total_acum-precio;
                return 0;
            }
        }        
    }
    std::cout<<"El total a pagar es: "<<total_acum;
    return 0;
}