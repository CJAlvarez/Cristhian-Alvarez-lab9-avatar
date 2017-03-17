// WaterBender.h
#include "Bender.h"

class WaterBender : public Bender{
	protected:


	public:
		WaterBender();
		// @param nombre, HP, defensa, ofensa, fuerza, suerte
		WaterBender(string, int, int, int, int, int);
		virtual void AtaqueRegular();
		virtual void AtaqueEspecial();
};