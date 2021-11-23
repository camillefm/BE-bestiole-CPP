#ifndef _OEIL_H_
#define _OEIL_H_

#include <math.h>
#include "Bestiole.h"

#include "Capteur.h"


class Oeil : public Capteur {

private:
    //Mesure l'angle entre le vecteur v1 et v2
    double getAngle(int v2[2]);

public:
    Oeil();
    bool vois(Bestiole b1,Bestiole b2, double distance, double angle);

};

#endif