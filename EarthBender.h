// EarthBender.h
#pragma once
#include "Bender.h"
#include "AirBender.h"
#include "WaterBender.h"
#include "FireBender.h"

class EarthBender : public Bender{
	protected:


	public:
		EarthBender();
		// @param nombre, HP, defensa, ofensa, fuerza, suerte
		EarthBender(string, int, int, int, int, int);
		virtual void AtaqueRegular(Bender*);
		virtual void AtaqueEspecial(Bender*);

		void Espiar(Bender*);
};