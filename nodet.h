#include <iostream>
class nodet{
	private:
		int data;
		nodet *left;
		nodet *right;
	public:
		nodet(int d);
		nodet(int d, nodet *l, nodet *r);
		int getData();
		void setData(int d);
		nodet* getLeft();
		void setLeft(nodet *l);
		nodet* getRight();
		void setRight(nodet *r);
};


nodet::nodet(int d){
	data = d;
	left = NULL;
	right = NULL;
}

nodet::nodet(int d, nodet *l, nodet *r){
	data = d;
	left = l;
	right = r;
}

int nodet::getData(){
	return data;
}

void nodet::setData(int d){
	data = d;
}

nodet* nodet::getLeft(){
	return left;
}

void nodet::setLeft(nodet *l){
	left = l;
}

nodet* nodet::getRight(){
	return right;
}

void nodet::setRight(nodet *r){
	right = r;
}