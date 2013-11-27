#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

int verFondo(Stack<int> *pila){
	Stack<int> *pila2 = new Stack<int>();
	int temp;
	while (!pila->isEmpty()) {
		pila2->push(pila->pop());
	}
	temp = pila2->peek();
	while(!pila2->isEmpty()){
		pila->push(pila2->pop());
	}
	return (temp);
	delete pila2;
}

int main(int argc, char *argv[]) {
	Stack<int> *pila = new Stack<int>();
	pila->push(10);
	pila->push(8);
	pila->push(11);
	pila->push(333);
	pila->push(222);
	cout<< verFondo(pila) <<endl;
	cout << pila->peek() << endl;
}