#ifndef _OEIL_H_
#define _OEIL_H_

#include <math.h>
#include "Capteur.h"
#include "Bestiole.h"

class Bestiole;

class Oeil : virtual public Capteur {

private:
    //Mesure l'angle entre le vecteur v1 et v2
    double getAngle(int v2[2]);

public:
    Oeil(void);
    bool vois(Bestiole b1,Bestiole b2, double distance, double angle);
    float getDistance(int v[2]);

};

#endif
