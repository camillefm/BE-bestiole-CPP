#include "Oeil.h"
#include "Capteur.h"
#include <iostream>
#include <cmath>


double Oeil::getAngle(int v[2]) {
    if (v[1]==0){return 0;}
    return atan (v[0]/v[1]);
}

Oeil::Oeil(void){
    return;
};

float Oeil::getDistance(int v[2]) {
        return sqrt ( pow(v[0],2) + pow(v[1],2) );
}

bool Oeil::vois(Bestiole b1, Bestiole b2, double distance, double angle) {
    int v2[2] = {b2.getX() - b1.getX(), b2.getY() - b1.getY()};
    if (getDistance(v2) <= distance) {
        if (abs(getAngle(v2)-b1.getOrientation()) <= (angle / 2)){
            return true;}
    }
    return false;
};
