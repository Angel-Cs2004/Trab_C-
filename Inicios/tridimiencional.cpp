#include<iostream>
#include<cmath>
using namespace std;

void leer(int **Ma, int fi,int co){ 
    cout<<"Ingrese "<<fi*co<<" valores: "<<endl;
    for(int i=0; i<fi;i++){
    	 for(int j=0; j<co; j++){
         cin >>Ma[i][j];
     }
	}
}

void mostrar(int **Ma, int fi,int co){ 
        for(int i=0; i<fi;i++){ 
          for(int j=0; j<co;j++)
           cout<<Ma[i][j]<<" ";
            cout<<endl;
    }
}
 //promedio, mayor, suma;
void principal(int **matriz, int fi, int col ){
	int main;
	for (int i =0; i<fi;i++){
		main+=matriz[i][i];
	}
	cout<<main<<endl;
}
void sum_fil_pos_impar(int **matriz, int fi, int col){
	
	for(int i=0; i<fi;i++){ 
	      int suma=0;
          for(int j=0; j<col;j+=2){
          	suma+=matriz[i][j];
		  }
		  cout<<"La suma de fila "<<i+1<<" es: "<<suma<<endl;
       }
}
void sum_de_columnas(int **matriz, int fi, int col){
	for(int j=0; j<col;j++){
		int suma=0;
		for(int i = 0; i<fi;i++){
			suma+=matriz[i][j];
		}
		cout<<"La suma de la columna "<<j+1<<" es: "<<suma<<endl;
	}
}
void suma_primos_matriz(int **matriz, int fi, int col){
	int suma=0;
	for(int i = 0; i<fi; i++){
		for(int j =0;j<col;j++){
			for(int div=2;div<matriz[i][j];div++){
				if(matriz[i][j]%div==0){
					break;
				}
			if(div==matriz[i][j]-1){
				suma+=matriz[i][j];
			}
			}
		}
		
	}
	cout<<suma;
}



int main (int argc , char*argv[] ){
	int col, fi;
	cout<<"Ingresar el numero de filas: ";cin>>fi;
	cout<<"\nIngresar el numero de columnas: ";cin>>col;
	int **array = new int*[fi];
	for (int i=0;i<fi;i++){
		array[i]= new int[col];
	}
	leer(array,fi,col);
	mostrar(array,fi,col);
	cout<<"Diagonal principal: ";
	cout<<endl;
	principal(array,fi,col);
	cout<<"Suma de las filas de posicion impar: "<<endl;
	sum_fil_pos_impar(array, fi, col);
	cout<<endl<<"El valor de las suma de cada columna: "<<endl;
	sum_de_columnas(array,fi,col);
	cout<<endl<<"Suma de todos los primos de la matriz: "<<endl;
	suma_primos_matriz(array,fi,col);
	return 0;
}
