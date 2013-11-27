#include "node.h"

template <class T>
class Queue{
	private:
		node<T> *end;
	public:
		Queue();
		~Queue();
		void push(T d);
		T pop();
		T peek();
		bool isEmpty();
};

template <typename T>
Queue<T>::Queue(){
	end = NULL;
}

template <typename T>
Queue<T>::~Queue(){
	if (end != NULL){
		node<T> *aux1 = end->getNext();
		node<T> *aux2 = aux1->getNext();
		while (aux1 != end)
		{
			delete aux1;
			aux1 = aux2;
			aux2 = aux2->getNext();
		}
		delete end;
		end = NULL;
	}
}	
template <typename T>
bool Queue<T>::isEmpty(){
	return end == NULL;
}

template <typename T>
void Queue<T>::push(T d){
	node<T> *aux = new node<T>(d);
	if (end == NULL){
		aux->setNext(aux);
		end = aux;
	}
	else{
		aux->setNext(end->getNext());
		end->setNext(aux);
		end = aux;
	}
}
template <typename T>
T Queue<T>::pop(){
	if (end == NULL)
		return NULL;
	T dataAux = end->getNext()->getData();
	node <T> *aux = end->getNext();
	if (end -> getNext()==end){
		end = NULL;
	}
	else
	{
		end->setNext(end->getNext()->getNext());
	}
	delete aux;
	return dataAux;
}
template <typename T>
T Queue<T>::peek(){
	if (isEmpty())
		return NULL;
	return end->getNext()->getData();
}