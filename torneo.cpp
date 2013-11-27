#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Equipos{
	private:
		int partidosGanados;
		int partidosPerdidos;
		int partidosEmpatados;
		int partidosJugados;
		int cantGoles;
		int puntos;
		int diferenciaGoles;
		int golesFavor;
		int golesContra;
		string equipo;
	public:
		int goles;
		Equipos();
		
		string getEquipo();
		int getPGanados();
		int getPEmpatados();
		int getPPerdidos();
		int getPuntos();
		int getPJugados();
		int getDGoles();
		int getGFavor();
		int getGContra();
		
		void setPJugados();
		void setPuntos();
		void setDGoles();
		void setEquipo(string nombre);
		void sumaPGanados();
		void sumaPPerdidos();
		void sumaPEmpatados();
		void sumaGFavor(int goles);
		void sumaGContra(int goles);
		void clear();
		
		Equipos operator=(Equipos e);
};
Equipos::Equipos(){
	equipo = "";
	cantGoles = 0;
	partidosGanados = 0;
	partidosPerdidos = 0;
	partidosEmpatados = 0;
	partidosJugados = 0;
	puntos = 0;
	diferenciaGoles = 0;
	golesFavor = 0;
	golesContra = 0;
}
string Equipos::getEquipo(){
	return equipo;
}
int Equipos::getPGanados(){
	return partidosGanados;
}
int Equipos::getPEmpatados(){
	return partidosEmpatados;
}
int Equipos::getPPerdidos(){
	return partidosPerdidos;
}
int Equipos::getPuntos(){
	return puntos;
}
int Equipos::getPJugados(){	
	return partidosJugados;
}
int Equipos::getGFavor(){
	return golesFavor;
}
int Equipos::getGContra(){
	return golesContra;
}
int Equipos::getDGoles(){
	return diferenciaGoles;
}
void Equipos::setPuntos(){
	puntos += partidosGanados * 3;
	puntos += partidosEmpatados * 1;
}
void Equipos::setPJugados(){
	partidosJugados += partidosGanados;
	partidosJugados += partidosEmpatados;
	partidosJugados += partidosPerdidos;
}
void Equipos::setDGoles(){
	diferenciaGoles = golesFavor - golesContra;
}
void Equipos::sumaGFavor(int goles){
	golesFavor += goles;
}
void Equipos::sumaGContra(int goles){
	golesContra += goles;
}
void Equipos::setEquipo(string nombre){
	equipo = nombre;
}
void Equipos::sumaPGanados(){
	partidosGanados += 1;
}
void Equipos::sumaPPerdidos(){
	partidosPerdidos += 1;
}
void Equipos::sumaPEmpatados(){
	partidosEmpatados += 1;
}
Equipos Equipos::operator=(Equipos e){
	partidosGanados = e.partidosGanados;
	partidosPerdidos = e.partidosPerdidos;
	partidosEmpatados = e.partidosEmpatados;
	partidosJugados = e.partidosJugados;
	cantGoles = e.cantGoles;
	puntos = e.puntos;
	diferenciaGoles = e.diferenciaGoles;
	golesFavor = e.golesFavor;
	golesContra = e.golesContra;
	equipo = e.equipo;
	return e;
}
void Equipos::clear(){
	equipo = "";
	cantGoles = 0;
	partidosGanados = 0;
	partidosPerdidos = 0;
	partidosEmpatados = 0;
	partidosJugados = 0;
	puntos = 0;
	diferenciaGoles = 0;
	golesFavor = 0;
	golesContra = 0;
}




//funciones
void ignore(){
	cin.ignore();
}
string primerEquipo(string partido){
	istringstream ss( partido );
	string lado;
	getline(ss, lado,'#');
	return lado;
}
int primerGol(string partido){
	int gol;
	istringstream ss( partido );
	string lado;
	getline(ss, lado,'@');
	lado.erase(lado.begin(),lado.end()-1);
	gol = lado[0] - 48;
	return gol;
}

string segundoEquipo(string partido){
	istringstream ss( partido );
	string lado;
	while(!ss.eof()){
		getline(ss, lado,'#');
	}
	return lado;
}
int segundoGol(string partido){
	int gol;
	istringstream ss( partido );
	string lado;
	while(!ss.eof()){
		getline(ss, lado,'@');
	}
	lado.erase(lado.begin()+1,lado.end());
	gol = lado[0] - 48;
	return gol;
}

//main

int main(int argc, char *argv[]) {
	string nombreTorneo;
	int cantTorneos, cantEquipos, cantJuegos;
	string temp;
	Equipos equipo[102];
	Equipos tempEquipo;
	
	bool interruptor = true;
	
	cin >> cantTorneos;
	ignore();
	for (int i = 0; i < cantTorneos; i++) {
		
		getline(cin,nombreTorneo);
		cin >> cantEquipos;
		ignore();
		for (int j = 0; j < cantEquipos; j++) {
			getline(cin,temp);
			equipo[j].setEquipo(temp);
			temp = "";
		}
		cin >>  cantJuegos;
		ignore();
		for (int j = 0; j < cantJuegos; j++) {
			getline(cin,temp);
			for (int k = 0; k < cantEquipos; k++) {
				//dar valores a primer equipo
				if(equipo[k].getEquipo() == primerEquipo(temp)){
					if(primerGol(temp) == segundoGol(temp)){
						equipo[k].sumaPEmpatados();
					}
					if (primerGol(temp) > segundoGol(temp)) {
						equipo[k].sumaPGanados();
					}
					if (primerGol(temp) < segundoGol(temp)) {
						equipo[k].sumaPPerdidos();
					}		
					equipo[k].sumaGFavor(primerGol(temp));
					equipo[k].sumaGContra(segundoGol(temp));		
				}else if(equipo[k].getEquipo() == segundoEquipo(temp)){
					if(primerGol(temp) == segundoGol(temp)){
						equipo[k].sumaPEmpatados();
					}
					if (primerGol(temp) < segundoGol(temp)) {
						equipo[k].sumaPGanados();
					}
					if (primerGol(temp) > segundoGol(temp)) {
						equipo[k].sumaPPerdidos();
					}
					equipo[k].sumaGFavor(segundoGol(temp));
					equipo[k].sumaGContra(primerGol(temp));
				}
			}			
			temp = "";
		}

		for (int j = 0; j < cantEquipos; j++) {
			equipo[j].setDGoles();
			equipo[j].setPJugados();
			equipo[j].setPuntos();
		}
		
		//Menos goles en contra.
		for(int pasada = 0; pasada < cantEquipos-1 && interruptor; pasada++){
			interruptor = false;
			for (int j=0; j<cantEquipos-1-pasada; j++) {
				if (equipo[j+1].getGContra() < equipo[j].getGContra()) {
					tempEquipo = equipo[j+1];
					equipo[j+1] = equipo[j];
					equipo[j] = tempEquipo;
					interruptor = true;
				}
			}
		}
		interruptor = true;
		
		//Mas goles a favor.
		for(int pasada = 0; pasada < cantEquipos-1 && interruptor; pasada++){
			interruptor = false;
			for (int j=0; j<cantEquipos-1-pasada; j++) {
				if (equipo[j+1].getGFavor() > equipo[j].getGFavor()) {
					tempEquipo = equipo[j];
					equipo[j] = equipo[j+1];
					equipo[j+1] = tempEquipo;
					interruptor = true;
				}
			}
		}
		interruptor = true;
		
		//Mejor diferencia de goles (goles a favor – goles en contra).
		
		for(int pasada = 0; pasada < cantEquipos-1 && interruptor; pasada++){
			interruptor = false;
			for (int j=0; j<cantEquipos-1-pasada; j++) {
				if (equipo[j+1].getDGoles() > equipo[j].getDGoles()) {
					tempEquipo = equipo[j];
					equipo[j] = equipo[j+1];
					equipo[j+1] = tempEquipo;
					interruptor = true;
				}
			}
		}
		interruptor = true;
		
		//Mas juegos ganados.
		
		for(int pasada = 0; pasada < cantEquipos-1 && interruptor; pasada++){
			interruptor = false;
			for (int j=0; j<cantEquipos-1-pasada; j++) {
				if (equipo[j+1].getPGanados() > equipo[j].getPGanados()) {
					tempEquipo = equipo[j];
					equipo[j] = equipo[j+1];
					equipo[j+1] = tempEquipo;
					interruptor = true;
				}
			}
		}
		interruptor = true;
		
		//Mas puntos logrados. 
		for(int pasada = 0; pasada < cantEquipos-1 && interruptor; pasada++){
			interruptor = false;
			for (int j=0; j<cantEquipos-1-pasada; j++) {
				if (equipo[j+1].getPuntos() > equipo[j].getPuntos()) {
					tempEquipo = equipo[j];
					equipo[j] = equipo[j+1];
					equipo[j+1] = tempEquipo;
					interruptor = true;
				}
			}
		}
		interruptor = true;
		
		cout << nombreTorneo << endl;
		for (int j = 0; j < cantEquipos; j++) {
			cout << j+1 << ") ";
			cout << equipo[j].getEquipo() << " "
			<< equipo[j].getPuntos() << "p, "
			<< equipo[j].getPJugados() << "j "
			<< "(" << equipo[j].getPGanados() << "-"
			<< equipo[j].getPEmpatados() << "-"
			<< equipo[j].getPPerdidos() << "), "
			<< equipo[j].getDGoles() << "g "
			<< "(" << equipo[j].getGFavor() << "-"
			<< equipo[j].getGContra() << ")"
			<< endl;
			equipo[j].clear();
		}
		
	}

	
}
/*
2
Copa Mundial 1998 – Grupo A
4
Brasil
Noruega
Marruecos
Escocia
6
Brasil#2@1#Escocia
Noruega#2@2#Marruecos
Escocia#1@1#Noruega
Brasil#3@0#Marruecos
Brasil#1@2#Noruega
Marruecos#3@0#Escocia
Algun raro torneo
5
Equipo A
Equipo B
Equipo C
Equipo D
Equipo E
5
Equipo A#1@1#Equipo B
Equipo A#2@2#Equipo C
Equipo A#0@0#Equipo D
Equipo E#2@1#Equipo C
Equipo E#1@2#Equipo D*/