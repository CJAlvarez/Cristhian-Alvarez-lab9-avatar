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

string Bender::getNombre(){
	return nombre;
}
int Bender::getHP(){
	return HP;
}
int Bender::getDefensa(){
	return defensa;
}
int Bender::getOfensa(){
	return ofensa;
}
int Bender::getFuerza(){
	return fuerza;
}
int Bender::getSuerte(){
	return suerte;
}	

void Bender::setNombre(string nombre){
	this -> nombre = nombre;
}
void Bender::setHP(int HP){
	this -> HP = HP;
}
void Bender::setDefensa(int defensa){
	this -> defensa = defensa;
}
void Bender::setOfensa(int ofensa){
	this -> ofensa = ofensa;
}
void Bender::setFuerza(int fuerza){
	this -> fuerza = fuerza;
}
void Bender::setSuerte(int suerte){
	this -> suerte = suerte;
}

int Bender::smash() {
	srand(time(NULL));
	int random;
	if(suerte > 0 && suerte <= 5) {
		random = rand() % 1000 + 1;
		if(random == 50) {
			return 1;
		}
	} 
	else if(suerte >= 6 && suerte <= 9) {
		random = rand() % 100 + 1;
		if(random % 5 == 0) {
			return 1;
		}
	}
	else {
		random = rand() % 10 + 1;
		if(random % 3 == 0) {
			return 1;
		}
	}
	return 0;
}