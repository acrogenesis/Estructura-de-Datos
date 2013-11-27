#include <iostream>
#include <string>

using namespace std;
int factR (int n){
	if (n==0)
		return 1;
	return n*factR(n-1);
}
int factI(int n){
	int acum = 1;
	for (int i = 2; i <= n; i++)
		acum = acum*i;
	return acum;
	
}
int main(int argc, char *argv[]) {
	int dato;
	cout << "Dar el dato: "<<endl;
	cin >> dato;
	cout << "iterativo: "<<factI(dato) << endl;
	cout << "recursivo: "<<factR(dato) << endl;
}