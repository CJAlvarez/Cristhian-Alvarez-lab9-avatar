// Bender.cpp
#include "Bender.h"

Bender::Bender() {
	HP = defensa = ofensa = fuerza = suerte = 0;
}

Bender::Bender(string nombre, int HP, int defensa, int ofensa, int fuerza, int suerte) {
	this -> nombre = nombre;
	this -> HP = HP;
	this -> defensa = defensa;
	this -> ofensa = ofensa;
	this -> fuerza = fuerza;
	this -> suerte = suerte;
}

void Bender::AtaqueRegular(Bender* bender) {
}
void Bender::AtaqueEspecial(Bender* bender) {
}