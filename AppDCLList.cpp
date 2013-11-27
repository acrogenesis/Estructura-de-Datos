#include <iostream>
using namespace std;

#include "DCLList.h"

int main(){
	DCLList<int> *lista1;
	DCLList<string> *lista2;
	lista1 = new DCLList<int>();
	lista2 = new DCLList<int>(lista1);
	lista1->addFirst(10);
	//cout << "pass" <<endl;
	lista1->print();
	lista1->addLast(20);
	//cout << "pass" <<endl;
	lista1->print();
	lista1->addFirst(30);
	//cout << "pass" <<endl;
	lista1->print();
	lista1->addLast(40);
	//cout << "pass" <<endl;
	lista1->print();
	if (lista1->add(1,0))
		cout << "SI SE PUDO el 1 en la pos 0" << endl;
	else
		cout << "NO SE PUDO el 1 en la pos 0" << endl;
	if (lista1->add(100,80))
		cout << "SI SE PUDO el 100 en la pos 80" << endl;
	else
		cout << "NO SE PUDO el 100 en la pos 80" << endl;
	if (lista1->add(400,3))
		cout << "SI SE PUDO el 400 en la pos 3" << endl;
	else
		cout << "NO SE PUDO el 400 en la pos 3" << endl;
	lista1->print();
	cout << "La lista 1 tiene " << lista1->count <<" datos"<<endl;
	
	DCLList<string> *lista2;
	lista2 = new DCLList<string>();
	lista2->addFirst("HOLA");
	lista2->print();
	lista2->addFirst("CRAYOLA");
	lista2->print();
	lista2->addFirst("BEAGLE");
	lista2->print();
}