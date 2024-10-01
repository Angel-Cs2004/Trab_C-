// 14. Simular el comportamiento de un reloj digital, imprimiendo la hora, minutos y segundos de un día desde las 0:00:00 horas hasta las 23:59:59 horas
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

int main(int argc, char*argv[]){
    srand(time(0));
    std::string min_s,seg_s;
    int hora= rand()%24+1;
    int min= rand()%59+0;
    int seg= rand()%59+0;

    if(min<10){
        min_s="0"+std::to_string(min);
    }else{
        min_s=std::to_string(min);
    }
    if(seg<10){
        seg_s="0"+std::to_string(seg);    
    }else{
        seg_s=std::to_string(seg);
    }
    std::cout<<"Consultando la hora.... "<<std::endl<<hora<<":"+min_s+":"+seg_s;
    return 0;

}
int main(int argc, char*argv[]){
    srand(time(0));
    std::string min_s,seg_s;
    int hora= rand()%24+1;
    int min= rand()%59+0;
    int seg= rand()%59+0;

    std::string horas = (hora<10)?"0"+std::to_string(hora):std::to_string(hora);
    std::string mins = (min<10)?"0"+std::to_string(min):std::to_string(min);
    std::string segs = (seg<10)?"0"+std::to_string(seg):std::to_string(seg);
    std::cout<<"Consultando la hora.... "<<std::endl<<horas<<":"+mins+":"+segs;
    return 0;
}


int main(int argc, char*argv[]){
    int hora= rand()%24;
    int min= rand()%60;
    int seg= rand()%60;
    std::cout << "Consultando la hora.... "<<std::endl
              << std::setw(2) << std::setfill('0') << hora << ":"
              << std::setw(2) << std::setfill('0') << min << ":"
              << std::setw(2) << std::setfill('0') << seg << std::endl;
}
