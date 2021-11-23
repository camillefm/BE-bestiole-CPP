#include "Oeil.h"
#include "Bestiole.h"

#include <cmath>

double Oeil::getAngle(int v[2]) {
    return atan (v[0]/v[1]);
}

Oeil::Oeil(void) : Capteur(){};

bool Oeil::vois(Bestiole b1, Bestiole b2, double distance, double angle) {
    int v2[2] = {b2.getX() - b1.getX(), b2.getY() - b1.getY()};
    if (getDistance(v2) <= distance) {
        return (abs(getAngle(v2)-b1.getOrientation()) <= (angle / 2));
    }
    return false;
};


