#ifndef _CAPTEUR_H_
<<<<<<< HEAD
#define _CAPTEUR_H_

#include <math.h>

#include "Bestiole.h"

=======
#define _CAPGTEUR_H_

#include <math.h>

>>>>>>> 9f331f5777de1ac2252e2e7d986080e629567341

class Capteur {

public:
    Capteur();

<<<<<<< HEAD
    virtual bool vois(Bestiole b1, Bestiole b2, double distance, double angle);

    float getDistance(int v[2]); 
};


#endif
=======
    virtual bool vois(Bestiole b1, Bestiole b2, float distance, float angle) = 0;

    float getDistance(float[2] v);
};


>>>>>>> 9f331f5777de1ac2252e2e7d986080e629567341
