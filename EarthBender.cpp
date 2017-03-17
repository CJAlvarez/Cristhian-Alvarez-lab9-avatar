// EarthBender.cpp
#include "EarthBender.h"

EarthBender::EarthBender() : Bender() {
	
}

EarthBender::EarthBender(string nombre, int HP, int defensa, int ofensa, int fuerza, int suerte) : Bender(nombre, HP, defensa, ofensa, fuerza, suerte) {

}

void EarthBender::AtaqueRegular(Bender* bender) {
	bender -> setHP(bender -> getHP() - ofensa + (bender -> getDefensa() * 0.40));
	if(smash() == 1) {
			bender -> setHP(bender -> getHP() - ((ofensa * 0.50) + ofensa));
	}
}
void EarthBender::AtaqueEspecial(Bender* bender) {
	if(typeid(*bender) == typeid(WaterBender)) {
		bender -> setHP(bender -> getHP() - ((ofensa * 0.25) + ofensa));
	} else {
		bender -> setHP(bender -> getHP() - ofensa + (bender -> getDefensa() * 0.40));
	}
	if(smash() == 1) {
			bender -> setHP(bender -> getHP() - ((ofensa * 0.50) + ofensa));
	}
}

void EarthBender::Espiar(Bender* bender) {
	cout << "Nombre: " << bender -> getNombre() << "\nHP: " << bender -> getHP() << "\nDefensa: " << bender -> getDefensa() << "\nOfensa: " << bender -> getOfensa() << "\nSuerte: " << bender -> getSuerte()  << endl;
}