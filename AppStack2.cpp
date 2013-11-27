#include <iostream>
#include <string>
using namespace std;
#include "Stack.h"

int polaco(string s){
	Stack<int> *pila = new Stack<int>();
	int a, b, c;
	for (int i=0; i<s.length(); i++){
		if (s[i]>='0' && s[i]<='9')
			pila->push(s[i]-'0');
		else{
			b = pila->pop();
			a = pila->pop();
			switch(s[i]){
				case '+' : c = a+b; break;
				case '-' : c = a-b; break;
				case '*' : c = a*b; break;
				case '/' : c = a/b; break;
			}
			pila->push(c);
		}
	}
	return pila->pop();
}
int main(){
	string operacion;
	cin >> operacion;
	cout << "el resultado es " << polaco(operacion) << endl;
}