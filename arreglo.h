#include <iostream>
#include <string>
using namespace std;

class Arreglo{
	private:
		int tam;
		int *datos;
	public:
		Arreglo(int t);
		Arreglo(const Arreglo &otro);
		~Arreglo();
		Arreglo operrator+(int num);
		Arreglo operator=(const Arreglo &otro);
		friend istream& operator >>(istream &ent, Arreglo &otro);
		friend ostream& operator <<(ostream &sal, Arreglo &otro);
		void muestra();
};

Arreglo::Arreglo(int t){
	tam = t;
	datos = new int[tam];
	for (int i = 0; i < tam; i++) {
		*(datos+i) = 0;
	}
}
Arreglo& Arreglo::operator+(int num){
	Arreglo AUX(this->tam);
	for (int i = 0; i < i<this->tam; i++) {
		*(AUX.datos+i) = *(datos+i)+num;
	}
	return AUX;
}
Arreglo& Arreglo::operator=(const Arreglo &otro){
	tam = otro.tam;	
	datos = new int[tam];
	for (int i = 0; i < tam; i++) {
		*(datos+i) = *(otro.datos+i);
	}
}
Arreglo::Arreglo(const Arreglo &otro){
	tam = otro.tam;
	datos = new int[tam];
	for (int i = 0; i < tam; i++) {
		*(datos+i) = *(otro.datos+i);
	}
}
Arreglo::~Arreglo(){
	delete datos;
}
istream & operator>>(istream&ent, Arreglo &otro){
	for (int i = 0; i < otro.tam; i++) {
		ent >> *(otro.datos +i);
	}	
	ent.ignore();
}
ostream& operator<<(ostream &sal, Arreglo &otro){
	for (int i = 0; i < otro.tam; i++) {
		sal << *(otro.datos+i) << " ";
	}
	sal << endl;
}
void Arreglo::muestra(){
	for (int i = 0; i < tam; i++) {
		cout << *(datos+i) << " ";
	}
	cout << endl;
}