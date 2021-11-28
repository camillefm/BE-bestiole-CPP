#include "Nageoire.h"

#include <ctime>
#include <cstdlib>
using namespace std;


Nageoire::Nageoire(double maxv) {
	maxV=maxv;
}

Nageoire::Nageoire(){}
Nageoire::~Nageoire(){}

void Nageoire::modifieCaracteristique(Bestiole& bestiole){
	srand ( time(NULL) );
	double random = (rand()%(int)((maxV-1)*1000)+ 1000)/1000.0;
	bestiole.setV(random);
}