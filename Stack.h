#include <iostream>
#include <string>
#include "node.h"
using namespace std;

template <class T>
class Stack{
	private:
		node<T> *top;
	public:
		Stack();
		~Stack();
		void push(T d);
		T pop();
		T peek();
		bool isEmpty();
};

template <typename T>
Stack<T>::Stack(){
	top = NULL;
}
template <typename T>
void Stack<T>::push(T d){
	node<T> *aux = new node<T>(d, top);
	top = aux;
}
template <typename T>
T Stack<T>::pop(){
	if (top == NULL) {
		return NULL;
	}
	T dataAux = top ->getData();
	node<T> *aux = top;
	top = top -> getNext();
	delete aux;
	return dataAux;
}
template <typename T>
T Stack<T>::peek(){
	if (top == NULL)
		return NULL;
	return top->getData();
}
template <typename T>
bool Stack<T>::isEmpty(){
	return (top == NULL);
}
template <typename T>
Stack<T>::~Stack(){
	node<T> *aux = top;
	while (aux != NULL) {
		top = top->getNext();
		delete aux;
		aux = top;
	}
}
