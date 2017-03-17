// AirBender.h
#pragma once
#include "Bender.h"
#include "EarthBender.h"
#include "WaterBender.h"
#include "FireBender.h"

class AirBender : public Bender{
	private:


	public:
		AirBender();
		// @param nombre, HP, defensa, ofensa, fuerza, suerte
		AirBender(string, int, int, int, int, int);
		virtual void AtaqueRegular(Bender*);
		virtual void AtaqueEspecial(Bender*);
};