#include "Oeil.h"
#include "Bestiole.h"

#include <cmath>

float Oeil::getAngle(float *) {
    return acos ((v1[0]*v2[0]+v1[1]*v2[1])/(getNorm(v1)* getNorm(v2)))
}

float Oeil::getNorm(float *) {
    return sqrt( pow (v[0],2) + pow (v[1],2) )
}

bool Oeil::vois(Bestiole b1, Bestiole b2, double distance, double angle) {
    float[2]
    v2 = {b2.getX() - b1.getX(), b2.getY() - b1.getY()};
    if (getDistance(v2) <= distance) {
        float[2]
        v1 = {b1.getVX(), b1.getVY()};
        return (abs(getAngle(v1, v2)) <= (angle / 2))
    }
    return false
}


