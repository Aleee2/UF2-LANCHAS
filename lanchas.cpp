#include "Lanchas.h"  

// CONSTRUCTOR
Lanchas::Lanchas(std::string pName, int pVelocidad, int pDistancia, int pNitro) {
	Name = pName;
	Vel = pVelocidad;
	Dis = pDistancia;
	Nit = pNitro;
}

//GETTERS

std::string Lanchas::getName() {
	return Name;
}

int Lanchas::getVelocidad() {
	return Vel;
}

int Lanchas::getDistancia() {
	return Dis;
}
int Lanchas::getNitro() {
	return Nit;
}

//SETTERS
void Lanchas::setName(std::string pName) {
	Name = pName;
}

void Lanchas::setVelocidad(int pVelocidad) {
	Vel = pVelocidad;
}

void Lanchas::setDistancia(int pDistancia) {
	Dis = pDistancia;
}
void Lanchas::setNitro(int pNitro) {
	Nit = pNitro;
}

// metodos
void Lanchas::sumaVelocidad(int Dado) {
	Vel = Vel + Dado;
}
int Lanchas::nitro(int Dado, int& Vel) {
	if (Dado == 0) {
		Vel = Vel / 2;
	}
	else {
		Vel = Vel * 2;
	}
	return Vel;
}