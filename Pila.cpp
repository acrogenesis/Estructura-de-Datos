#include <iostream>
#include "Queue.h"
using namespace std;

int main(){
	Queue<int> *fila = new Queue<int>();
	fila->push(5);
	fila->push(10);
	fila->push(1);
	while (!fila->isEmpty())
		cout << " " << fila->pop();
	cout << endl;
	fila->push(100);
	fila->push(200);
	cout << "PEEK "<< fila->peek();
	while (!fila->isEmpty())
		cout << " " << fila->pop();
	cout << endl;
	
}