#include "Camouflage.h"
#include "Bestiole.h"
#include <ctime>
#include <cstdlib>
using namespace std;


Camouflage::Camouflage(double minp,double maxp) {
	minP=minp;
	maxP=maxp;
}
Camouflage::~Camouflage(){}
void Camouflage::modifieCaracteristique(Bestiole& bestiole){
	srand ( time(NULL) );
	double random = (rand()%(int)((maxP-minP)*1000)+ minP*1000)/1000.0;
	bestiole.setP(random);
}