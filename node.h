#include <iostream>
#include <string>
using namespace std;

template <class T>
class node{
	private:
		T data;
		node<T> *next;
	public:
		node (T d);
		node(T d, node<T> *n);
		T getData();
		void setData(T d);
		node<T>* getNext();
		void setNext(node<T> *n);
		
};

template <typename T>
node<T>::node(T d){
	data = d;
	next = NULL;	
}
template <typename T>
node<T>::node(T d, node<T> *n){
	data = d;
	next = n;	
}
template <typename T>
T node<T>::getData(){
	return data;
}
template <typename T>
void node<T>::setData(T d){
	data = d;
}
template <typename T>
node<T>* node<T>::getNext(){
	return next;
}
template <typename T>
void node<T>::setNext(node<T> *n){
	next = n;
}


