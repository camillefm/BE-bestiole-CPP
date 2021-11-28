#ifndef _CAPTEUR_H_
#define _CAPTEUR_H_

#include <math.h>
#include "Bestiole.h"

class Bestiole;


class Capteur {

public:

    virtual bool vois(Bestiole b1, Bestiole b2, double distance, double angle)=0;

    virtual float getDistance(int v[2])=0; 
};


#endif
