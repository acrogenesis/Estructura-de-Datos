#include <iostream>
#include <string>
#include "BST.h"

using namespace std;
int main(int argc, char *argv[]) {
	BST *arbol = new BST();
	arbol->insert(24);
	arbol->insert(12);
	arbol->insert(30);
	arbol->insert(60);
	arbol->insert(14);
	arbol->insert(10);
	arbol->insert(70);
	arbol->insert(55);
	arbol->insert(44);
	arbol->insert(48);
	arbol->insert(5);
	arbol->insert(2);
	arbol->insert(3);
	cout << "arbol: ";
	arbol->print(1);
	cout << endl << "anchura: ";
	arbol->anchura();
	cout << endl << "nivelxnivel: ";
	arbol->npn();
	cout << endl << "hojas: ";
	arbol->print(4);
	cout << endl << "ancestros del 48: ";
	arbol->ancestros(48);
	cout << endl << "primos de 60: ";
	arbol->primos(60);
	
}