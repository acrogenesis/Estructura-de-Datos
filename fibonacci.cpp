#include <iostream>
#include <string>

using namespace std;
int fiboR(int n){
	if(n<=2)
		return 1;
	return fiboR(n-1)+fiboR(n-2);
}
int fiboI(int n){
	int a =1, b=1,resul=1;
	for (int i = 3; i <=n; i++) {
		resul = a+b;
		a=b;
		b=resul;
	}
	return resul;
}
int main(int argc, char *argv[]) {
	cout << fiboI(45) << endl;
	cout << fiboR(45);
}