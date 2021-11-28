#ifndef _OREILLE_H_
#define _OREILLE_H_

#include <math.h>
#include "Capteur.h"
#include "Bestiole.h"

class Bestiole;

class Oreille : virtual public Capteur {


public:
    Oreille(void);
    bool vois(Bestiole b1,Bestiole b2, double distance, double angle);
    float getDistance(int v[2]);

};

#endif