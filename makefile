# makefile
main.exe: main.o Bender.o AirBender.o EarthBender.o WaterBender.o FireBender.o
	g++ main.o Bender.o -o run -std=c++0x

main.o: main.cpp
	g++ main.cpp -c -std=c++0x

Bender.o: Bender.h Bender.cpp
	g++ Bender.cpp -c -std=c++0x

AirBender.o: AirBender.h AirBender.cpp Bender.h
	g++ AirBender.cpp -c -std=c++0x

EarthBender.o: EarthBender.h EarthBender.cpp Bender.h
	g++ EarthBender.cpp -c -std=c++0x

WaterBender.o: WaterBender.h WaterBender.cpp Bender.h
	g++ WaterBender.cpp -c -std=c++0x

FireBender.o: FireBender.h FireBender.cpp Bender.h
	g++ FireBender.cpp -c -std=c++0x