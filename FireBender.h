// FireBender.h
#include "Bender.h"

class FireBender : public Bender{
	protected:


	public:
		FireBender();
		// @param nombre, HP, defensa, ofensa, fuerza, suerte
		FireBender(string, int, int, int, int, int);
		virtual void AtaqueRegular();
		virtual void AtaqueEspecial();
};