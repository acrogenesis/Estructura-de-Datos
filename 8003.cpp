#include <iostream>
#include <string>

using namespace std;

int buscar(int N, int clave, int arr[1000]){
	int central, bajo, alto, valorCentral;
	bajo = 0;
	alto = N-1;
	while (bajo <= alto) {  
    	central = (bajo + alto)/2;
		valorCentral = arr[central];
		if (clave == valorCentral)  
			return 1;
		else if (clave < valorCentral) 
			alto = central -1; 
		else 
			bajo = central + 1; 
	}
	return 0;
}

int main() {
	int n,n2;
	cin >> n;
	int row, col;
	int numero;
	bool check = false;
	int matr[n+1][n];
	int temp[n];
	
	int cont = 0;
	int fila;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matr[i][j];
		}
	}
	matr[n+1][0] = 999999999;
	cin >> n2;
	int busco[n2];
	for (int i = 0; i < n2; i++) {
		cin >> busco[i];
	}
	
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < n; j++) {
		
			if (busco[i] >= matr[j][0] && busco[i] < matr[j+1][0]){
				cont = j;
				check = true;
			}
			if(j==(n-1) && check==false){
				cont = j;
			}
			//cout << busco[i] << ">=" << matr[j][0] << "-" << busco[i] << "<" << matr[j+1][0] << endl;
			//cout << cont << endl;
		}
		
		for (int j = 0; j < n; j++) {
			temp[j] = matr[cont][j];
		}
		
		numero = buscar(n,busco[i],temp);
		
		if (numero == 1){
			cout << "Caso " << i+1 <<": SI" <<endl;
		}
		if (numero == 0){
			cout << "Caso " << i+1 <<": NO" <<endl;
		}
		cont = 0;
		fila = 0;
		numero = 0;
		check = false;
	}
}