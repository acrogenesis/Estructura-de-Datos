// Copyright © Adrián Rangel
#include <iostream>
#include "dNode.h"

using namespace std;

template <class T>
class DCLList{
	private:
		dNode<T> *head;
		dNode<T> *tail;
	public:
		int count;
		DCLList();
		DCLList(DCLList<T> const &other);
		~DCLList();
		void addFirst(T d);
		void addLast(T d);
		bool add(T d, int pos);
		T deleteFirst();
		T deleteLast();
		T deletePos(int pos);
		bool isEmpty();
		T get(int pos);
		T set(T d, int pos);
		bool change(int pos1, int pos2);
		void print();
};
template <typename T>
DCLList<T>::DCLList(){
	head = NULL;
	tail = NULL;
	count = 0;
}

template <typename T>
DCLList<T>::DCLList(DCLList<T> const &other){
	if (other->count == 0){
		head = NULL;
		tail = NULL;
	}
	else{
		dNode<T> *aux = other->head;
		addFirst(aux->getData());
		dNode<T> *aux1 = head;
		for (int i=1; i<other->count; i++){
			aux1->setNext(new dNode<T>(aux->getNext()->getData()));
			aux = aux->getNext();
			aux1 = aux1->getNext();
		}
		tail = aux1;
		count = other->count;
	}
		
}

template <typename T>
DCLList<T>::~DCLList(){
	dNode<T> *aux = head;
	while (aux != aux->getPrev()){
		head = head->getNext();
		delete aux;
		aux = head;
	}
}

template <typename T>
void DCLList<T>::addFirst(T d){
	if (head == NULL){
		dNode<T> *aux = new dNode<T>(d, tail, head);
		head = aux;
		tail = aux;
		count++;
	}else {
		dNode<T> *aux2 = head;
		dNode<T> *aux = new dNode<T>(d, tail, head);
		aux2->setPrev(aux);
		//cout << "/"<< tail->getPrev()->getPrev()->getData() << "/";
		head = aux;
		count++;
	}
}

template <typename T>
void DCLList<T>::addLast(T d){
	if(head == NULL)
		addFirst(d);
	else{
		dNode<T> *aux = tail;
		dNode<T> *aux2 = head;
		aux->setNext(new dNode<T>(d,aux,aux2));
		tail = aux->getNext();
		aux2->setPrev(tail);
		aux2 = aux2->getPrev();
		aux2->setNext(head);
		//cout << "/"<< tail->getPrev()->getPrev()->getData() << "/";
	}
	count++;
}

template <typename T>
bool DCLList<T>::add(T d, int pos){
	if (pos > count)
		return false;
	if (pos == 0){
		addFirst(d);
	}else if (pos == count-1){
		addLast(d);
	}else {
		if (pos < count/2){
			dNode<T> *aux = head;
			for (int i = 1; i < pos; i++) {
				aux = aux->getNext();
			}
			dNode<T> *nuevo = new dNode<T>(d,aux->getPrev(),aux->getNext());
			aux->setNext(nuevo);
			dNode<T> *aux2 = nuevo;
			nuevo = nuevo->getPrev();
			aux2->setNext(nuevo);
			count++;
		}else {
			//1 30 10 20 40
			//1 30 10 400 20 40
			dNode<T> *aux = tail;
							//5			3
			for (int i = count; i > pos; i--) {
				aux = aux->getPrev();
				//cout << "/" << aux->getData()<<"/";
			}
			dNode<T> *nuevo = new dNode<T>(d,aux,aux->getNext());
			//cout << "/"<< nuevo->getNext()->getData() << "/";
			aux->setNext(nuevo);
			dNode<T> *aux2 = nuevo;
			aux2 = aux2->getNext();
			aux2->setPrev(nuevo);
			count++;
		}
	}
	return true;
}

template <typename T>
void DCLList<T>::print(){
	if (count == 1) {
		dNode<T> *aux = head;
		cout << " " << aux->getData() << endl;
	}else {
		dNode<T> *aux = head;
		while (aux != tail) {
			cout << " " << aux->getData();
			aux = aux->getNext();
		}
		cout << " " << aux->getData();
		cout<<endl;
	}
}

template <typename T>
bool DCLList<T>::isEmpty(){
	return head==NULL;
}


template <typename T>
T DCLList<T>::deleteFirst(){
	if (head == NULL)
		return NULL;
	T dataAux = head->getData();
	dNode<T> *aux = head;
	dNode<T> *aux2 = head->getPrev();
	head = head->getNext();
	aux2->setNext(head);
	head->setPrev(aux2);
	delete aux;
	count--;
	return dataAux;
}

template <typename T>
T DCLList<T>::deleteLast(){
	if (count <=1)
		return deleteFirst();
	dNode<T> *aux = tail;
	aux = aux->getPrev();
	//1 2 3 4 5
	T dataAux = aux->getNext()->getData();
	delete aux->getNext();
	aux->setNext(head);
	count--;
	return dataAux;
}

template <typename T>
T DCLList<T>::deletePos(int pos){
	if (pos==0)
		return deleteFirst();
	if (pos == count-1)
		return deleteLast();
	if (pos >= count)
		return NULL;
	dNode<T> *aux = head;
	for (int i=1; i<pos; i++)
		aux = aux->getNext();
	T dataAux = aux->getNext()->getData();
	dNode<T> *aux2 = aux->getNext();
	aux->setNext(aux->getNext()->getNext());
	delete aux2;
	count--;
	return dataAux;
}

template <typename T>
T DCLList<T>::get(int pos){
	if (pos >= count)
		return NULL;
	dNode<T> *aux = head;
	for (int i=1; i<=pos; i++)
		aux = aux->getNext();
	return aux->getData();
}

template <typename T>
T DCLList<T>::set(T d, int pos){
	if (pos >= count)
		return NULL;
	dNode<T> *aux = head;
	for (int i=1; i<=pos; i++)
		aux = aux->getNext();
	T dataAux = aux->getData();
	aux->setData(d);
	return dataAux;	
}

template <typename T>
bool DCLList<T>::change(int pos1, int pos2){
	if (pos1>=count || pos2>=count)
		return false;
	if (pos1==pos2)
		return true;
	int posmen = (pos1<pos2)? pos1 : pos2;
	int posmay = (pos1>pos2)? pos1 : pos2;
	dNode<T> *aux1 = head;
	for (int i=1; i<=posmen; i++)
		aux1 = aux1->getNext();
	dNode<T> *aux2 = aux1;
	for (int i=posmen+1; i<=posmay; i++)
		aux2 = aux2->getNext();
	T dataAux = aux1->getData();
	aux1->setData(aux2->getData());
	aux2->setData(dataAux);
	return true;
}