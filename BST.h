#include "nodet.h"
#include <queue>
#include <stack>
using namespace std;
class BST{
	private:
		nodet *root;
		void preorden(nodet *r);
		void inorden(nodet *r);
		void postorden(nodet *r);
		void dHojas(nodet *r);
		void destroy(nodet *r);
		int howmany(nodet *r);
		int pred(nodet *r);
		int succ(nodet *r);
		int height2(nodet *r);
		void primos(nodet *r);
	public:
		BST();
		~BST();
		void npn();
		void anchura();
		bool search(int d);
		bool insert(int d);
		void print(int i);
		void primos(int d);
		void ancestros(int d);
		bool deleteData(int d);
		int height();
};
BST::BST(){
	root = NULL;
}
bool BST::search(int d){
	nodet *aux = root;
	while (aux != NULL){
		if (aux->getData() == d)
			return true;
		else
			aux = (aux->getData()>d)? aux->getLeft() : aux->getRight();
	}
	return false;
}
bool BST::insert(int d){
	if (root == NULL){
		root = new nodet(d);
		return true;
	}
	nodet *father = NULL;
	nodet *aux = root;
	while (aux != NULL){
		if (aux->getData() == d)
			return false;
		father = aux;
		aux = (aux->getData()>d)? aux->getLeft() : aux->getRight();
	}
	if (father->getData() > d)
		father->setLeft(new nodet(d));
	else
		father->setRight(new nodet(d));
	return true;
}
void BST::preorden(nodet *r){
	if (r != NULL){
		cout << r->getData() << " ";
		preorden(r->getLeft());
		preorden(r->getRight());
	}
}
void BST::primos(nodet *r){
	if (r != NULL){
		if( r->getData()%2 != 0)
			cout << r->getData() << " ";
		primos(r->getLeft());
		primos(r->getRight());
	}
}

void BST::inorden(nodet *r){
	if (r != NULL){
		inorden(r->getLeft());
		cout << r->getData() << " ";		
		inorden(r->getRight());
	}
}

void BST::postorden(nodet *r){
	if (r != NULL){
		postorden(r->getLeft());
		postorden(r->getRight());
		cout << r->getData() << " ";		
	}
}
void BST::npn(){
	queue<nodet> f;
	f.push(*root);
	while (!f.empty()) {
		cout << f.front().getData() << " ";
		if (f.front().getLeft() != NULL)
			f.push(*(f.front().getLeft()));
		if (f.front().getRight() != NULL)
			f.push(*(f.front().getRight()));
		f.pop();
	}
}
void BST::dHojas(nodet *r){
	if (r != NULL){
		if( r->getLeft() == NULL && r->getRight() == NULL)
			cout << r->getData() << " ";
		dHojas(r->getLeft());
		dHojas(r->getRight());
	}
}
void BST::ancestros(int d){
	stack<int> p;
	nodet *aux = root;
	if(aux->getData() == d){
		cout << aux->getData();
	}else{
		p.push(aux->getData());
		while(!p.empty()) {
			aux = (aux->getData()>d)? aux->getLeft() : aux->getRight();
			p.push(aux->getData());
			if(aux->getData() == d){
				p.pop();
				while(!p.empty()){
					cout << p.top() << " ";
					p.pop();
				}
			}
		}
	}
}
void BST::anchura(){
	queue<nodet> f;
	f.push(*root);
	int count = 1;
	int count2 = count;
	while (!f.empty()) {
		if(count2 < count)
			count2 = count;
		count = 1;
		if (f.front().getLeft() != NULL){
			f.push(*(f.front().getLeft()));
			count++;
		}
		if (f.front().getRight() != NULL){
			f.push(*(f.front().getRight()));
			count++;
		}
		f.pop();
	}
	cout << count2;
}
void BST::primos(int d){
	stack<nodet> p;
	nodet *aux = root;
	nodet *abuelo = aux;
	p.push(*aux);
	while(aux!=NULL) {
		aux = (aux->getData()>d)? aux->getLeft() : aux->getRight();
		p.push(*aux);
		if(aux->getData() == d){
			p.pop();
			p.pop();
			*abuelo = p.top();
			if(abuelo->getData() > d){
				abuelo = abuelo->getRight();
				if(abuelo->getLeft() != NULL)
					cout << abuelo->getLeft()->getData() << " ";
				if(abuelo->getRight() != NULL)
					cout << abuelo->getRight()->getData() << " ";
				aux = NULL;
			}else {
				abuelo = abuelo->getLeft();
				if(abuelo->getLeft() != NULL)
					cout << abuelo->getLeft()->getData() << " ";
				if(abuelo->getRight() != NULL)
					cout << abuelo->getRight()->getData() << " ";
				aux = NULL;				
			}
		}
	}
}
void BST::print(int i){
	switch(i){
		case 1: preorden(root); break;
		case 2: inorden(root); break;
		case 3: postorden(root); break;
		case 4: dHojas(root); break;
	}
	//cout << endl;
}
int BST::howmany(nodet *r){
	int cont = 0;
	if (r->getLeft() != NULL)
		cont++;
	if (r->getRight() != NULL)
		cont++;
	return cont;
}

int BST::pred(nodet *r){
	nodet *aux = r->getLeft();
	while (aux->getRight() != NULL)
		aux = aux->getRight();
	return aux->getData();
}
int BST::height2(nodet *r){
	if (r == NULL)
		return 0;
	else{
		int le = height2(r->getLeft());
		int ri = height2(r->getRight());
		return (1+ ((le>ri)?le:ri));
	}
}
int BST::height(){
	return height2(root);
}

int BST::succ(nodet *r){
	nodet *aux = r->getRight();
	while (aux->getLeft() != NULL)
		aux = aux->getLeft();
	return aux->getData();
}
bool BST::deleteData(int d){
	if (root == NULL)
		return false;
	nodet *father = NULL;
	nodet *aux = root;
	while (aux->getData() != d){
		father = aux;
		aux = (aux->getData() > d)? aux->getLeft() : aux->getRight();
		if (aux == NULL)
			return false;
	}
	int cuantos = howmany(aux);
	switch (cuantos){
		case 0: if (father == NULL){
					root = NULL;
				}
				else{
					if (father->getData() > d)
						father->setLeft(NULL);
					else
						father->setRight(NULL);
				}
				delete aux;
				break;
		case 1: if (father == NULL){
					root = (aux->getLeft() != NULL)? aux->getLeft() : aux->getRight();
				}
				else{
					if (father->getData() > d){
						if (aux->getLeft() != NULL)
							father->setLeft(aux->getLeft());
						else
							father->setLeft(aux->getRight());
					}
					else{
						if (aux->getLeft() != NULL)
							father->setRight(aux->getLeft());
						else
							father->setRight(aux->getRight());
					}
				}
				delete aux;
				break;
	}
	return true;
}
void BST::destroy(nodet *r){
	if (r != NULL) {
		destroy(r->getLeft());
		destroy(r->getRight());
		delete r;
	}
}
BST::~BST(){
	destroy(root);
}