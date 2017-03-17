// WaterBender.cpp
#include "WaterBender.h"

WaterBender::WaterBender() : Bender() {
	
}
WaterBender::WaterBender(string nombre, int HP, int defensa, int ofensa, int fuerza, int suerte) : Bender(nombre, HP, defensa, ofensa, fuerza, suerte) {

}


void WaterBender::AtaqueRegular(Bender* bender) {
	bender -> setHP(bender -> getHP() - ofensa);
	if(smash() == 1) {
			bender -> setHP(bender -> getHP() - ((ofensa * 0.50) + ofensa));
	}
}
void WaterBender::AtaqueEspecial(Bender* bender) {
	if(typeid(*bender) == typeid(FireBender)) {
		bender -> setHP(bender -> getHP() - ((ofensa * 0.15) + ofensa));
	} else {
		bender -> setHP(bender -> getHP() - ofensa);
	}
	if(smash() == 1) {
			bender -> setHP(bender -> getHP() - ((ofensa * 0.50) + ofensa));
	}
}

void WaterBender::Recuperar( Bender* bender) {
	if(bender -> getOfensa() >= 110) {
		bender -> setHP(bender -> getHP() + 75);
	}
}