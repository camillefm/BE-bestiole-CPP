main : main.cpp Bestiole.o Oeil.o Aquarium.o Milieu.o Prevoyante.o Peureuse.o Oreille.o Gregaire.o Kamikaze.o
	g++ -Wall -std=c++11 -o main main.cpp Bestiole.o Prevoyante.o Peureuse.o Oeil.o Oreille.o Aquarium.o Kamikaze.o Gregaire.o Milieu.o -I . -lX11 -lpthread

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Oeil.o : Oeil.h Oeil.cpp Capteur.h
	g++ -Wall -std=c++11  -c Oeil.cpp -I .

Oreille.o : Oreille.h Oreille.cpp Capteur.h
	g++ -Wall -std=c++11  -c Oreille.cpp -I .

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

Gregaire.o : Gregaire.h Gregaire.cpp Comportement.h
	g++ -Wall -std=c++11 -c Gregaire.cpp -I .

Kamikaze.o : Kamikaze.h Kamikaze.cpp Comportement.h
	g++ -Wall -std=c++11 -c Kamikaze.cpp -I .

Peureuse.o : Peureuse.h Peureuse.cpp Comportement.h
	g++ -Wall -std=c++11 -c Peureuse.cpp -I .

Prevoyante.o : Prevoyante.h Prevoyante.cpp Comportement.h
	g++ -Wall -std=c++11 -c Prevoyante.cpp -I .