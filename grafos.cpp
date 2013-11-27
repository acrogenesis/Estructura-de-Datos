#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;
int main(int argc, char *argv[]) {
	
	int cant;
	
	string line;
	ifstream myFile;
	//cout << "Nombre del archivo: " ;
	//cin >> file;
	myFile.open("datosgrafos.txt");
 	if (!myFile){
		cout << "Error opening file"  << endl;
		return -1;
	}
	myFile >> cant;
	int mat[cant][cant];
	int mat2[cant][cant];
	bool check[cant];
	for (int i = 0; i < cant; i++) {
		for (int j = 0; j < cant; j++) {
			myFile >> mat[i][j];
			mat2[i][j] = mat[i][j];
		}
		check[i] = false;
	}
	myFile.close();
	/*9
	0 1 0 1 0 0 1 0 0
	  0 1 0 0 0 1 0 0
	    0 0 0 0 0 1 1
	      0 1 0 1 0 0
	        0 1 1 0 0
	          0 0 1 1
	            0 0 0
	              0 1
	                0
	*/
	queue<int> fila;
	fila.push(1);
	int b=1;
	int temp2;
	//anchura 1 2 4 7 3 5 8 9 6
	while (!fila.empty()) {
		cout << fila.front() << " ";
		
		temp2=b;
		for (; b < cant; b++) {
			if ((mat[fila.front()-1][b] == 1)) {
				fila.push(b+1);
				for (int i = 0; i < cant; i++) {
					mat[i][b]=0;
				}
			}
		}
		fila.pop();
		b = temp2;
		//a++;
	}
	cout << endl;
	/*
	0 1 0 1 0 0 1 0 0
	1 0 1 0 0 0 1 0 0
	0 1 0 0 0 0 0 1 1
	1 0 0 0 1 0 1 0 0
	0 0 0 1 0 1 1 0 0
	0 0 0 0 1 0 0 1 1
	1 1 0 1 1 0 0 0 0
	0 0 1 0 0 1 0 0 1
	0 0 1 0 0 1 0 1 0
	*/
	
	//profundidad 1 2 3 8 6 5 4 7 9
	stack<int> pila;
	pila.push(1);
	check[0] = true;
	int temp=1;
	cout << pila.top() << " ";
	for(int r=0; r<cant-1;r++){
	//while (!pila.empty()) {
		for(int i=cant-1; i >=0; i--){
			if(!check[i] && mat2[i][temp-1]==1){
				pila.push(i+1);
			}
		}
		temp = pila.top();
		pila.pop();
		if(!check[temp-1])
			cout<<temp<<" ";
		else{
			cout<<pila.top()<<" ";
			pila.pop();
		}
		check[temp-1] = true;
	}
}