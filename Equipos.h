#include <iostream>
#include <string>
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