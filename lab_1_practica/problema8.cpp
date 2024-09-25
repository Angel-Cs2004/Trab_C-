#include<iostream>
#include <string>
using namespace std;
int main(){
    int sueldo = 12,total,total_e, horas,h1,h2,h3;
    cout<<"Que horas trabajo entre 8:00 am-4:00 pm: ";cin>>horas;
    cout<<endl<<"Que horas trabajo entre 4:00 pm-8:00 pm: ";cin>>h1;
    cout<<endl<<"Que horas trabajo entre 8:00 pm-12:00 am: ";cin>>h2;
    cout<<endl<<"Que horas trabajo entre 12:00 am-8:00 am: ";cin>>h3;
    total = horas*sueldo;
    total_e= h1*(sueldo*1.25)+h2*(sueldo*1.5)+h3*sueldo*2;
    cout<<"El total por todas las horas: "<<"s/."<<total+total_e<<".00";
    cout<<"\nTotal por horas de oficina: "<<"s/."<<horas*sueldo<<".00";
    cout<<"\nTotal por horas extra: "<<"s/."<<total_e<<".00";
    if (total<total_e){
        cout<<"\nSe gano mas por horas extra";
        
    }
    else{
        cout<<"\nSe gano mas por horas de oficina";
    }
    return 0;
}
