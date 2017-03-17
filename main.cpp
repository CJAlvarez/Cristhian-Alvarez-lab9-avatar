// main.cpp
#include "Bender.h"
#include "AirBender.h"
#include "EarthBender.h"
#include "WaterBender.h"
#include "FireBender.h"

#include <iostream>
#include <typeinfo>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
	srand(time(NULL));
	vector <Bender*>* benders = new vector <Bender*>();
	int salir;
 	do {
 		int menu;
 		cout << "1.- Agregar\n2.- Batalla";
 		cin >> menu;

 		// AGREGAR
 		if(menu == 1) {
 			int tipo; 	
			string nombre;
			int HP;
			int defensa;
			int ofensa;
			int fuerza; // INUTIL
			int suerte;
			cout << "Nombre: ";
			cin >> nombre;
			cout << "HP: ";
			cin >> HP;
			cout << "Defensa: ";
			cin >> defensa;
			do{
				cout << "Ofensa: ";
				cin >> ofensa;
			} while(ofensa < 0 || ofensa >60);
			do{
				cout << "Suerte: ";
				cin >> suerte;
			} while(suerte < 0 || suerte > 10);

 			cout << "1.- Aire\n2.- Tierra\n3.- Agua\n4.- Fuego";
 			cin >> tipo;
 			switch(tipo) {
 				case 1: {
 					benders -> push_back(new AirBender(nombre, HP, defensa, ofensa, fuerza, suerte));
 					break;
 				}
 				case 2: {
 					benders -> push_back(new EarthBender(nombre, HP, defensa, ofensa, fuerza, suerte));
 					break;
 				}
 				case 3: {
 					benders -> push_back(new WaterBender(nombre, HP, defensa, ofensa, fuerza, suerte));
 					break;
 				}
 				case 4: {
 					benders -> push_back(new FireBender(nombre, HP, defensa, ofensa, fuerza, suerte));
 					break;
 				}
 			}
 		} 
 		// BATALLA
 		else if(menu == 2) {
 			int oponentes[2];
	 		for(int i = 0; i < benders -> size(); i++) {
		 		cout << i << ".- " << benders -> at(i) -> getNombre() << "[" << typeid(*(benders -> at(i))).name() << "]" << endl;
		 	}
		 	do {
		 		cout << "Primer Oponente: ";
		 		cin >> oponentes[0];
		 	} while(oponentes[0] < 0 || oponentes[0] >= benders -> size());
		 	do {
		 		cout << "Segundo Oponente: ";
		 		cin >> oponentes[1];
		 		if(oponentes[0] == oponentes[1]) {
		 			cout << "YA FUE ELEGIDO" << endl;
		 			oponentes[1] = -1;
		 		}
		 	} while(oponentes[1] < 0 || oponentes[1] >= benders -> size());
 			
 		}
 		cout << "¿Salir?\n1.- Si\n0.- No";
 		cin >> salir;
 	} while(salir == 0);
 	for(int i = 0; i < benders -> size(); i++) {
 		delete benders -> at(i);
 	}
 	delete benders;
 	benders -> clear();
	return 0;
}