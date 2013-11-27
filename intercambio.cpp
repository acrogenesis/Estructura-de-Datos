#include <iostream>
#include <string>

using namespace std;

void ordIntercambio (int a[], int n)
{ 	int i, j, aux;  /* se realizan n-1 pasadas,	a[o] ... a[n-2]	*/
	bool check = true;
	while (check) {
		for (i = 0; i < n; i++){ /* coloca mínimo de a[i+1]...a[n-1] en a[i] */
			for (j = 0; j < i; j++){
				if (a[i] < a[j]){
					aux = a[i];
					a[i] = a[j];
					a[j]= aux;
				}
			}
		}		
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int main() {
	int arr[5];
	arr[0]=8;
	arr[1]=9;
	arr[2]=6;
	arr[3]=1;
	arr[4]=5;
	
	ordIntercambio(arr,5);
}