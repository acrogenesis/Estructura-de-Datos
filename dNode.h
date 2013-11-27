#include <iostream>
#include <string>
using namespace std;

template <class T>
class dNode{
	private:
		T data;
		dNode<T> *next;
		dNode<T> *prev;
	public:
		dNode (T d);
		dNode(T d, dNode<T> *p,dNode<T> *n);
		T getData();
		void setData(T d);
		
		dNode<T>* getNext();
		void setNext(dNode<T> *n);
		
		dNode<T>* getPrev();
		void setPrev(dNode<T> *p);
};

template <typename T>
dNode<T>::dNode(T d){
	data = d;
	next = NULL;
	prev = NULL;
}
template <typename T>
dNode<T>::dNode(T d,dNode<T> *p, dNode<T> *n){
	data = d;
	prev = p;
	next = n;	
}
template <typename T>
T dNode<T>::getData(){
	return data;
}
template <typename T>
void dNode<T>::setData(T d){
	data = d;
}
template <typename T>
dNode<T>* dNode<T>::getNext(){
	return next;
}
template <typename T>
void dNode<T>::setNext(dNode<T> *n){
	next = n;
}
template <typename T>
dNode<T>* dNode<T>::getPrev(){
	return prev;
}
template <typename T>
void dNode<T>::setPrev(dNode<T> *p){
	prev = p;
}