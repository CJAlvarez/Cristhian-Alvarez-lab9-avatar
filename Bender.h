// Bender.h
#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
#include <typeinfo>

using namespace std;

class Bender {
	protected:
		string nombre;
		int HP;
		int defensa;
		int ofensa;
		int fuerza; // INUTIL
		int suerte;

	public:
		Bender();
		// @param nombre, HP, defensa, ofensa, fuerza, suerte
		Bender(string, int, int, int, int, int);
		virtual void AtaqueRegular(Bender*) = 0;
		virtual void AtaqueEspecial(Bender*) = 0;

		string getNombre();
		int getHP();
		int getDefensa();
		int getOfensa();
		int getFuerza();
		int getSuerte();	

		void setNombre(string);
		void setHP(int);
		void setDefensa(int);
		void setOfensa(int);
		void setFuerza(int);
		void setSuerte(int);
};