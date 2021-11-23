#ifndef _CAPTEUR_H_
#define _CAPGTEUR_H_

#include <math.h>


class Capteur {

public:
    Capteur();

    virtual bool vois(Bestiole b1, Bestiole b2, float distance, float angle) = 0;

    float getDistance(float[2] v);
};


