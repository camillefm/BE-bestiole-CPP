main : main.cpp Bestiole.o Capteur.o Oeil.o Aquarium.o Milieu.o
	g++ -Wall -std=c++11 -o main main.cpp Capteur.o Bestiole.o Oeil.o Aquarium.o Milieu.o -I . -lX11 -lpthread

Capteur.o : Capteur.h Capteur.cpp
	g++ -Wall -std=c++11  -c Capteur.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Oeil.o : Oeil.h Oeil.cpp
	g++ -Wall -std=c++11  -c Oeil.cpp -I .

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .
