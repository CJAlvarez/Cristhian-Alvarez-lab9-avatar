// FireBender.h
#pragma once
#include "Bender.h"
#include "AirBender.h"
#include "EarthBender.h"
#include "WaterBender.h"

class FireBender : public Bender{
	protected:


	public:
		FireBender();
		// @param nombre, HP, defensa, ofensa, fuerza, suerte
		FireBender(string, int, int, int, int, int);
		virtual void AtaqueRegular(Bender*);
		virtual void AtaqueEspecial(Bender*);
};