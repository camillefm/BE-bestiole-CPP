#ifndef _CAPTEUR_H_
#define _CAPTEUR_H_

#include <math.h>

#include "Bestiole.h"


class Capteur {

public:
    Capteur();

    virtual bool vois(Bestiole b1, Bestiole b2, double distance, double angle);

    float getDistance(int v[2]); 
};


#endif
