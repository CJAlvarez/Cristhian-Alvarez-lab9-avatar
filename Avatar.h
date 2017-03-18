// Avatar.h
#pragma once

#include "Bender.h"
#include "EarthBender.h"
#include "AirBender.h"
#include "WaterBender.h"
#include "FireBender.h"


class Avatar : public Bender {


	public:
		Avatar();
		// @param nombre, HP, defensa, ofensa, fuerza, suerte
		Avatar(string, int, int, int, int, int);
		virtual void AtaqueRegular(Bender*);
		virtual void AtaqueEspecial(Bender*);

		void Recuperar();
		void Espiar(Bender*);
};