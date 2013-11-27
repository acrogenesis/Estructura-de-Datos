#include <iostream>
#include <string>
#include "dNode.h"
using namespace std;

template <class T>
class DCLList{
	private:
		dNode<T> *head;
	public:
		DCLList();
		~DCLList();
		void addFirst(T d);
		void addLast(T d);
		bool add(T d, int pos);
		T deleteFirst();
		T deleteLast();
		T deletePos(int pos);
		bool isEmpty();
		void print();
		T setAt(T d, int pos);
		T getAt(int pos);
		bool change(int pos1, int pos2);
		int count;
};
template <typename T>
DCLList<T>::DCLList(){
	head = NULL;
}
template <typename T>
void DCLList<T>::addFirst(T d){
	if (head == NULL){
		dNode<T> *aux = new dNode<T>(d, aux, aux);
		head = aux;
		count++;
	}else {
		dNode<T> *aux = new dNode<T>(d, aux->getPrev(), head);
		head = aux;
		count++;
	}
}
template <typename T>
void DCLList<T>::addLast(T d){
	if(head == NULL)
		addFirst(d);
	else{
		dNode<T> *aux = head;
		aux->setPrev(new dNode<T>(d));
	}
	count++;
}
template <typename T>
bool DCLList<T>::add(T d, int pos){
	if(pos > count)
		return false;
	if(pos == 0)
		addFirst(d);
	else if(pos == count)
		addLast(d);
	else {
		if (pos < count/2){
			dNode<T> *aux = head;
			for (int i = 1; i < pos; i++) {
				aux = aux->getNext();
			}
			dNode<T> *nuevo = new dNode<T>(d,aux->getPrev(),aux->getNext());
			aux->setNext(nuevo);
			count++;
		}
	}
	return true;
}
template <typename T>
T DCLList<T>::deleteFirst(){
	if (head == NULL) {
		return NULL;
	}
	T dataAux = head ->getData();
	dNode<T> *aux = head;
	head = head -> getNext();
	delete aux;
	count--;
	return dataAux;
}
template <typename T>
T DCLList<T>::deleteLast(){
	if (count <=1)
		return deleteFirst();
	dNode<T> *aux = head;
	aux = aux->getPrev()->getPrev();
	//1 2 3 4 5
	T dataAux = aux->getNext()->getData();
	delete aux->getNext();
	aux->setNext(head);
	count--;
	return dataAux;
}
template <typename T>
T DCLList<T>::deletePos(int pos){
	if (pos == 0)
		return deleteFirst();
	if (pos == count-1)
		return deleteLast();
	if (pos >= count)
		return NULL;
	dNode<T> *aux = head;
	for (int i = 1; i < pos; i++) {
		aux = aux->getNext();
	}
	T dataAux = aux->getNext()->getData();
	dNode<T> *aux2 = aux->getNext();
	aux.setNext(aux->getNext()->getNext());
	delete aux2;
	count--;
	return dataAux;
}
template <typename T>
bool DCLList<T>::isEmpty(){
	return head == NULL;
}
template <typename T>
void DCLList<T>::print(){
	dNode<T> *aux = head;
	while (aux != aux->getPrev()) {
		cout << " " << aux->getData();
		aux = aux->getNext();
	}
	cout<<endl;
}
template <typename T>
T DCLList<T>::setAt(T d, int pos){
	if(pos >= count)
		return NULL;
	dNode<T> *aux = head;
	for(int i=1; i<= pos; i++)
		aux=aux->getNext();
	T dataAux = aux->getData();
	aux->setData(d);
	return dataAux;
}
template <typename T>
T DCLList<T>::getAt(int pos){
	if(pos >= count){
		return NULL;
	}
	dNode<T> *aux = head;
	for(int i=1; i<= pos; i++)
		aux=aux->getNext();
	return aux->getData();
}
template <typename T>
bool DCLList<T>::change(int pos1, int pos2){
	if(head == NULL){
		return false;
	}else if (pos1>=count or pos2>=count){
			return false;
	}else {
		dNode<T> *aux = head;
		T dataAux;
		for (int i = 1; i <= pos1; i++){
			aux=aux->getNext();
		}
		addLast(aux->getData());
		dNode<T> *aux2 = head;
		for (int i = 1; i <= pos2; i++) {
			aux2=aux2->getNext();
		}
		setAt(aux2->getData(), pos1);
		while (aux->getNext() != NULL) {
			aux=aux->getNext();
		}
		setAt(aux->getData(),pos2);
		deleteLast();
		return true;
	}
}