// EarthBender.h
#include "Bender.h"

class EarthBender : public Bender{
	protected:


	public:
		EarthBender();
		// @param nombre, HP, defensa, ofensa, fuerza, suerte
		EarthBender(string, int, int, int, int, int);
		virtual void AtaqueRegular();
		virtual void AtaqueEspecial();
};