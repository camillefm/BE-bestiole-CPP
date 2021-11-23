#include "Capteur.h"

#include <cmath>

float Capteur::getDistance(float *) {
        return sqrt ( pow(v[0],2)+pow(v[1],2) )
}