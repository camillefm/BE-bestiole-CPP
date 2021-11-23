#include "Capteur.h"

#include <cmath>

float Capteur::getDistance(int v[2]) {
        return sqrt ( pow(v[0],2) + pow(v[1],2) );
}

Capteur::Capteur(void){};