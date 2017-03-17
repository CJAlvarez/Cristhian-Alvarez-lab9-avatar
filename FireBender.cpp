// FireBender.cpp
#include "FireBender.h"

FireBender::FireBender() : Bender() {
	
}

FireBender::FireBender(string nombre, int HP, int defensa, int ofensa, int fuerza, int suerte) : Bender(nombre, HP, defensa, ofensa, fuerza, suerte) {

}

void FireBender::AtaqueRegular(Bender* bender) {
	bender -> setHP(bender -> getHP() - ofensa + (bender -> getDefensa() * 0.40));
	if(smash() == 1) {
			bender -> setHP(bender -> getHP() - ((ofensa * 0.50) + ofensa));
	}
}
void FireBender::AtaqueEspecial(Bender* bender) {
	if(typeid(*bender) == typeid(AirBender)) {
		bender -> setHP(bender -> getHP() - ((ofensa * 0.15) + ofensa));		
	} else {
		bender -> setHP(bender -> getHP() - ofensa + (bender -> getDefensa() * 0.40));
	}
	if(smash() == 1) {
			bender -> setHP(bender -> getHP() - ((ofensa * 0.50) + ofensa));
	}
}