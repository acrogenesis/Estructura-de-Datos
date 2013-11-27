#include <iostream>

using namespace std;
int arr[100][100];
int tam;

void lee(){
	//leer los datos
	cin >> tam;
	for (int i=0; i<tam; i++){
		for (int j=0; j<=i; j++){
			arr[i][j] = 0;
		}
	}
	for (int i=0; i<tam; i++){
		for (int j=0; j<=i; j++){
			cin >> arr[i][j];
		}
	}
}
void suma(){
	int resul;
	//suma todo el lado izquierdo
	for (int i = 1; i < tam; i++) {
		arr[i][0] += arr[i-1][0];
	}
	//suma todo el lado derecho
	for (int i = 1; i < tam; i++) {
		int h = i;
		arr[i][h] += arr[i-1][h-1];	
	}
	//suma lo restante
	for (int i = 2; i < tam; i++) {
		for (int j = 1; j < i; j++) {
			if(arr[i-1][j-1] >= arr[i-1][j]){
				arr[i][j] += arr[i-1][j-1];
			}else {
				arr[i][j] += arr[i-1][j];
			}
		}
	}
	//resul es el mas grande
	resul = arr[tam-1][0];
	//queda en el ultimo rengolon los mas grandes de cada posible camino comparalos
	for (int i = 0; i < tam; i++) {
		if (resul < arr[tam-1][i])
			resul = arr[tam-1][i];
	}
	cout << resul << endl;
}
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		lee();
		suma();
	}
}