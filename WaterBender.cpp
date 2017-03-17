// WaterBender.cpp
#include "WaterBender.h"

WaterBender::WaterBender() : Bender() {
	
}
WaterBender::WaterBender(string nombre, int HP, int defensa, int ofensa, int fuerza, int suerte) : Bender(nombre, HP, defensa, ofensa, fuerza, suerte) {

}

void WaterBender::AtaqueRegular(Bender* bender) {
	bender -> setHP(bender -> getHP() - ofensa + (bender -> getDefensa() * 0.40));
	if(smash() == 1) {
		bender -> setHP(bender -> getHP() - ((ofensa * 0.50) + ofensa) + (bender -> getDefensa() * 0.40));
	}
}

void WaterBender::AtaqueEspecial(Bender* bender) {
	if(typeid(*bender) == typeid(FireBender)) {
		bender -> setHP(bender -> getHP() - ((ofensa * 0.15) + ofensa));
	} else {
		bender -> setHP(bender -> getHP() - ofensa + (bender -> getDefensa() * 0.40));
	}
	if(smash() == 1) {
			bender -> setHP(bender -> getHP() - ((ofensa * 0.50) + ofensa) );
	}
}

void WaterBender::Recuperar() {
	if(ofensa >= 110) {
		HP += 75;
	} else {
		cout << "Movimiento fallido, cuenta como turno" << endl;
	}
}