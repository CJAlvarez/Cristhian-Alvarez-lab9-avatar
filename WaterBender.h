// WaterBender.h
#pragma once
#include "Bender.h"
#include "AirBender.h"
#include "EarthBender.h"
#include "FireBender.h"

class WaterBender : public Bender{
	protected:


	public:
		WaterBender();
		// @param nombre, HP, defensa, ofensa, fuerza, suerte
		WaterBender(string, int, int, int, int, int);
		virtual void AtaqueRegular(Bender*);
		virtual void AtaqueEspecial(Bender*);

		void Recuperar(Bender*);
};