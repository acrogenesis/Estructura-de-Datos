#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int main() {
	int n, r, c; //numero de casos, filas, columnas
	char campo[20][20]; //arreglo para * y .
	int campo2[20][20]; //arreglo para numero de bombas
	int temp = 0; //temp para numero de bombas
	int temp2 = 0; //temp para asignar r y c cuando vienen sin espacio (35 a r=3 y c=5) 
	cin >> n;
	//vaciar los arreglos
	for (int o = 0; o < 20; o++) {
		for (int p = 0; p < 20; p++) {
			campo2[o][p]=0;
			campo[o][p]=' ';
		}
	}	
	for (int i = 0; i < n; i++) {
		cin >> r;
		cin >> c;
		//llena el arreglo campo con * y .
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				cin >> campo[j][k];
			}
		}
		//imprimir caso i+1 (1,2,3..)
		cout << "Caso " << i+1 << ":" << endl;
		// si la casilla es un '.' verifica todas las de alrededor y haz un temp con la cantidad
		// despues asigna el temp al campo2 en la misma ubicacion que esta el '.' en el campo.
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				if(campo[j][k] == '.'){
					if(campo[j-1][k] == '*'){
						temp += 1;
					}
					if(campo[j+1][k] == '*'){
						temp += 1;
					}
					if(campo[j][k+1] == '*'){
						temp += 1;
					}
					if(campo[j][k-1] == '*'){
						temp += 1;
					}	
					if(campo[j+1][k+1] == '*'){
						temp += 1;
					}	
					if(campo[j+1][k-1] == '*'){
						temp += 1;
					}							
					if(campo[j-1][k+1] == '*'){
						temp += 1;
					}	
					if(campo[j-1][k-1] == '*'){
						temp += 1;
					}												if(temp != 0){
						campo2[j][k] = temp;
					}
				}
				temp = 0;
			}
		}
		//imprimir los resultados de los casos
		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				if(campo[j][k] == '.'){
					cout << campo2[j][k];
				}else cout << campo[j][k];
			}
			cout << endl;
		}	
		//vaciar los arreglos
		for (int o = 0; o < 20; o++) {
			for (int p = 0; p < 20; p++) {
				campo2[o][p]=0;
				campo[o][p]=' ';
			}
		}	
		//solo dar salto de linea entre casos no al final
		if (i != n-1 ){
			cout << endl;
		}
	}
}