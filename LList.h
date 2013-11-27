#include "node.h"

template <class T>
class LList{
	private:
		node<T> *head;
		void change2(node<T> *aux1, node<T> *aux2);
	public:
		int count;
		LList();
		LList(LList<T> const &other);
		~LList();
		void addFirst(T d);
		void addLast(T d);
		bool add(T d, int pos);
		T deleteFirst();
		T deleteLast();
		T deletePos(int pos);
		void deleteAll();
		bool isEmpty();
		bool find(T d);
		T get(int pos);
		T set(T d, int pos);
		bool change(int pos1, int pos2);
		void sort(bool type);
		void invert();
		void print();
		void divide(LList &par, LList &impar);
};

template <typename T>
void LList<T>::divide(LList &par, LList &impar){
	bool even = true;
	node<T> *aux = head;
	node<T> *auxp = NULL;
	node<T> *auxi = NULL;
	if (head != NULL){
		par->head = new node<T>(head->getData());
		auxp = par->head;
		if (head->getNext() != NULL){
			impar->head = new node<T>(head->getnext()->getData);
			auxi = impar->head;
			aux = aux->getNext();
		}
		while (aux != NULL) {
			if (even) {
				auxp->setNext(new node<T>(aux->getData()));
				auxp = auxp.getNext();
			}else {
				auxi->setNext(new node<T>(aux->getData()));
				auxi = auxi.getNext();
			}
			aux = aux->getNext();
			even = !even;
		}		
	}

	
}

template <typename T>
LList<T>::LList(){
	head = NULL;
	count = 0;
}

template <typename T>
LList<T>::LList(LList<T> const &other){
	if (other->count == 0)
		head = NULL;
	else{
		node<T> *aux = other->head;
		addFirst(aux->getData());
		node<T> *aux1 = head;
		for (int i=1; i<other->count; i++){
			aux1->setNext(new node<T>(aux->getNext()->getData()))w;
			aux = aux->getNext();
			aux1 = aux1->getNext();
		}
		count = other->count;
	}
		
}

template <typename T>
LList<T>::~LList(){
	node<T> *aux = head;
	while (aux != aux->getPrev()){
		head = head->getNext();
		delete aux;
		aux = head;
	}
}

template <typename T>
void LList<T>::addFirst(T d){
	node<T> *aux = new node<T>(d,head);
	head = aux;
	count++;
}

template <typename T>
void LList<T>::addLast(T d){
	if (head == NULL)
		addFirst(d);
	else{
		node<T> *aux = head;
		while (aux->getNext() != NULL){
			aux = aux->getNext();
		}
		aux->setNext(new node<T>(d));
	}
	count++;
}

template <typename T>
bool LList<T>::add(T d, int pos){
	if (pos > count)
		return false;
	if (pos == 0)
		addFirst(d);
	else if (pos == count)
		addLast(d);
	else{
		node<T> *aux = head;
		for(int i=1; i<pos; i++)
			aux = aux->getNext();
		node<T> *nuevo = new node<T>(d,aux->getNext());
		aux->setNext(nuevo);
		count++;
	}
	return true;
}

template <typename T>
void LList<T>::print(){
	node<T> *aux = head;
	while (aux != NULL){
		cout << " " << aux->getData();
		aux = aux->getNext();
	}
	cout << endl;
}

template <typename T>
bool LList<T>::isEmpty(){
	return head==NULL;
}


template <typename T>
bool LList<T>::find(T d){
	node<T> *aux = head;
	while (aux != NULL){
		if (aux->getData() == d){
			return true;
		}
		aux = aux->getNext();
	}
	return false;
}

template <typename T>
T LList<T>::deleteFirst(){
	if (head == NULL)
		return NULL;
	T dataAux = head->getData();
	node<T> *aux = head;
	head = head->getNext();
	delete aux;
	count--;
	return dataAux;
}

template <typename T>
T LList<T>::deleteLast(){
	if (count <= 1)
		return deleteFirst();
	node<T> *aux = head;
	while(aux->getNext()->getNext()!=NULL){
		aux = aux->getNext();
	}
	T dataAux = aux->getNext()->getData();
	delete aux->getNext();
	aux->setNext(NULL);
	count--;
	return dataAux;
}

template <typename T>
T LList<T>::deletePos(int pos){
	if (pos==0)
		return deleteFirst();
	if (pos == count-1)
		return deleteLast();
	if (pos >= count)
		return NULL;
	node<T> *aux = head;
	for (int i=1; i<pos; i++)
		aux = aux->getNext();
	T dataAux = aux->getNext()->getData();
	node<T> *aux2 = aux->getNext();
	aux->setNext(aux->getNext()->getNext());
	delete aux2;
	count--;
	return dataAux;
}

template <typename T>
void LList<T>::deleteAll(){
	node<T> *aux = head;
	while (aux != NULL){
		head = head->getNext();
		delete aux;
		aux = head;
	}
	count = 0;
}

template <typename T>
T LList<T>::get(int pos){
	if (pos >= count)
		return NULL;
	node<T> *aux = head;
	for (int i=1; i<=pos; i++)
		aux = aux->getNext();
	return aux->getData();
}

template <typename T>
T LList<T>::set(T d, int pos){
	if (pos >= count)
		return NULL;
	node<T> *aux = head;
	for (int i=1; i<=pos; i++)
		aux = aux->getNext();
	T dataAux = aux->getData();
	aux->setData(d);
	return dataAux;	
}

template <typename T>
bool LList<T>::change(int pos1, int pos2){
	if (pos1>=count || pos2>=count)
		return false;
	if (pos1==pos2)
		return true;
	int posmen = (pos1<pos2)? pos1 : pos2;
	int posmay = (pos1>pos2)? pos1 : pos2;
	node<T> *aux1 = head;
	for (int i=1; i<=posmen; i++)
		aux1 = aux1->getNext();
	node<T> *aux2 = aux1;
	for (int i=posmen+1; i<=posmay; i++)
		aux2 = aux2->getNext();
	T dataAux = aux1->getData();
	aux1->setData(aux2->getData());
	aux2->setData(dataAux);
	return true;
}

template <typename T>
void LList<T> change2(node<T> *aux1, node<T> *aux2){
	T dataAux = aux1->getData();
	aux1->setData(aux2->getData());
	aux2->setData(dataAux);
}

template <typename T>
void LList<T>::sort(bool type){
	if (count <= 1)
		return;
	node<T> *auxi = head;
	node<T> *auxj;
	for (int i=0; i<count-1; i++){
		auxj = auxi->getNext();
		for (int j=i+1; j<count; j++){
			if (type){
				if (auxi->getData() > auxj->getData())
					change2(auxi, auxj);
			}
			else{
				if (auxi->getData() < auxj->getData())
					change2(auxi, auxj);
			}
					
		}
	}
}

template <typename T>
void LList::invert(){
	if (count <= 1)
		return;
		
	node<T> *before = NULL;
	node<T> *next = head->getNext();
	while (next != NULL){
		head->setNext(before);
		before = head;
		head = next;
		next = next->getNext();
	}
	head->setNext(before);
	delete next;
	delete before;
}
	
