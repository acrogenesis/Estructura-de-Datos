#include <iostream>
#include <string>
#include "LList.h"
using namespace std;
int main(int argc, char *argv[]) {
	LList<int> *lista1;
	lista1 = new LList<int>;
	lista1->addFirst(1);
	lista1->addFirst(3);
	lista1->addFirst(2);
	lista1->addLast(4);
	lista1->addLast(47);
	lista1->addLast(45);
	lista1->print();
	/*
	LList<string> *lista2;
	lista2 = new LList<string>();
	lista2->addFirst("HOlA");
	lista2->print();
	lista2->addFirst("CRAYOLA");
	lista2->print();	
	lista2->addFirst("BEAGLE");
	lista2->print();		
	*/
}