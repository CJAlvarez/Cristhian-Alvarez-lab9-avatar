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
	cout << "\n\t\t\t¡BIENVENIDO!"<< endl;
	srand(time(NULL));
	vector <Bender*>* benders = new vector <Bender*>();
	int salir;
 	do {
 		int menu;
 		cout << "1.- Agregar\n2.- Batalla\n_ ";
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
			} while(ofensa <= 0 || ofensa > 60);
			do{
				cout << "Suerte: ";
				cin >> suerte;
			} while(suerte <= 0 || suerte > 10);

 			cout << "1.- Aire\n2.- Tierra\n3.- Agua\n4.- Fuego\n_ ";
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
 			int bono = 10;
 			int WINNER = -1;
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
		 	
		 	int turn = 0;
		 	int accion;
 			do{
		 		int opciones = 2;
 				cout << "Turno del Oponente " << ((turn % 2) +1) << endl;
 				cout << "1.- Ataque Normal\n2.- Ataque especial\n3.- Huir" << endl;
 				// Agua
 				if(typeid(*(benders -> at(oponentes[turn % 2]))) == typeid(WaterBender)) {
 					opciones++;
 					cout << "4.- Recuperar" << endl;
 				}
 				// Tierra
 				else if(typeid(*(benders -> at(oponentes[turn % 2]))) == typeid(EarthBender)) {
 					opciones++;
 					cout << "4.- Espiar" << endl;
 				}
 				cout << "_ ";
				cin >> accion; 				
				switch(accion) {
					// normal
					case 1: {
						benders -> at(oponentes[turn % 2]) -> AtaqueRegular(benders -> at(oponentes[(turn+1) % 2]));
						break;
					}
					// Especial
					case 2: {
						benders -> at(oponentes[turn % 2]) -> AtaqueEspecial(benders -> at(oponentes[(turn+1) % 2]));
						break;
					}
					// huir
					case 3: {
						// SET WINNER
						cout << "Gana Oponente " << (turn+1)%2 << "\n Su ofensa subio +10" <<  endl;
						benders -> at(oponentes[(turn+1) % 2]) -> setOfensa(benders -> at(oponentes[(turn+1) % 2]) -> getOfensa() + bono);
						WINNER = oponentes[(turn+1) % 2];
						
						benders -> at(oponentes[turn % 2]) -> setHP(0);						
						break;
					}
					case 4: {
						// AGUA
						if(typeid(*(benders -> at(oponentes[turn % 2]))) == typeid(WaterBender)) {
							static_cast<WaterBender*>(benders -> at(oponentes[turn % 2])) -> Recuperar();							
		 				}
		 				// Tierra
		 				else if(typeid(*(benders -> at(oponentes[turn % 2]))) == typeid(EarthBender)) {
		 					static_cast<EarthBender*>(benders -> at(oponentes[turn % 2])) -> Espiar(benders -> at(oponentes[(turn+1) % 2]));		 					
		 				} else {
		 					cout << "INVALIDO" << endl;
		 				}
						break;
					}
					default: {
						cout << "INVALIDO" << endl;
						break;
					}
				}

				if(WINNER != -1){ 
					break;
				}
				if(benders -> at(oponentes[turn % 2]) -> getHP() <= 0) {
					WINNER = oponentes[(turn+1) % 2];
					cout << "Gana Oponente " << (turn+1)%2 << "\n Su ofensa subio +10" <<  endl;
					benders -> at(oponentes[(turn+1) % 2]) -> setOfensa(benders -> at(oponentes[(turn+1) % 2]) -> getOfensa() + bono);										
				} else if(benders -> at(oponentes[(turn+1) % 2]) -> getHP() <= 0) {
					WINNER = oponentes[turn % 2];
					cout << "Gana Oponente " << turn%2 << "\n Su ofensa subio +10" <<  endl;
					benders -> at(oponentes[turn % 2]) -> setOfensa(benders -> at(oponentes[turn % 2]) -> getOfensa() + bono);					
				}
				turn++;
 			} while((benders -> at(oponentes[0]) -> getHP() > 0) && (benders -> at(oponentes[1]) -> getHP() > 0)); 			
 		}
 		cout << "¿Salir?\n1.- Si\n0.- No\n_ ";
 		cin >> salir;
 	} while(salir == 0);
 	for(int i = 0; i < benders -> size(); i++) {
 		delete benders -> at(i);
 	}
 	delete benders;
 	benders -> clear();
 	cout << "¡HASTA PRONTO!" << endl;
	return 0;
}