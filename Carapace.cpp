#include "Carapace.h"
#include "Bestiole.h"
#include <ctime>
#include <cstdlib>
using namespace std;



Carapace::Carapace(double maxw,double maxn) {
	maxW=maxw;
	maxN=maxn;
}

Carapace::~Carapace(){}

void Carapace::modifieCaracteristique(Bestiole& bestiole){
	srand ( time(NULL) );
	double random1 = (rand()%(int)((maxW-1)*1000)+ 1000)/1000.0;
	double random2 = (rand()%(int)((maxN-1)*1000)+ 1000)/1000.0;
	bestiole.setW(random1);
	bestiole.setN(random2);
}