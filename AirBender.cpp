// AirBender.cpp
#include "AirBender.h"

AirBender::AirBender() : Bender() {
	
}

AirBender::AirBender(string nombre, int HP, int defensa, int ofensa, int fuerza, int suerte) : Bender(nombre, HP, defensa, ofensa, fuerza, suerte) {

}

void AirBender::AtaqueRegular(Bender* bender) {
	bender -> setHP(bender -> getHP() - ofensa + (bender -> getDefensa() * 0.40));
	if(smash() == 1) {
			bender -> setHP(bender -> getHP() - ((ofensa * 0.50) + ofensa));
	}
}

void AirBender::AtaqueEspecial(Bender* bender) {
	if(typeid(*bender) == typeid(EarthBender)) {
		bender -> setHP(bender -> getHP() - ((ofensa * 0.25) + ofensa));
	} else {
		bender -> setHP(bender -> getHP() - ofensa + (bender -> getDefensa() * 0.40));
	}
	if(smash() == 1) {
			bender -> setHP(bender -> getHP() - ((ofensa * 0.50) + ofensa));
	}
}