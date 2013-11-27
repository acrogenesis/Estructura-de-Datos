#include <iostream>
#include <string>
#include "Arreglo.h"
using namespace std;
int main(int argc, char *argv[]) {
	Arreglo A(10);
	cin >> A;
	cout << A;
	Arreglo B(A);
	cout << B;
	
}