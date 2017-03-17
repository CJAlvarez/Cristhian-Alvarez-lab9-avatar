# makefile
main.exe: main.o Bender.o AirBender.o EarthBender.o WaterBender.o FireBender.o
	g++ main.o Bender.o -o run -std=c++0x

main.o: main.cpp Bender.h AirBender.h EarthBender.h WaterBender.h FireBender.h
	g++ main.cpp -c -std=c++0x

Bender.o: Bender.h Bender.cpp
	g++ Bender.cpp -c -std=c++0x

AirBender.o: AirBender.h AirBender.cpp Bender.h EarthBender.h WaterBender.h FireBender.h
	g++ AirBender.cpp -c -std=c++0x

EarthBender.o: EarthBender.h EarthBender.cpp Bender.h AirBender.h WaterBender.h FireBender.h
	g++ EarthBender.cpp -c -std=c++0x

WaterBender.o: WaterBender.h WaterBender.cpp Bender.h AirBender.h EarthBender.h FireBender.h
	g++ WaterBender.cpp -c -std=c++0x

FireBender.o: FireBender.h FireBender.cpp Bender.h AirBender.h EarthBender.h WaterBender.h 
	g++ FireBender.cpp -c -std=c++0x