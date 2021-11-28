#include "Oreille.h"
#include "Capteur.h"
#include <iostream>
#include <cmath>

Oreille::Oreille(void){
    return;
};

float Oreille::getDistance(int v[2]) {
        return sqrt ( pow(v[0],2) + pow(v[1],2) );
}

bool Oreille::vois(Bestiole b1, Bestiole b2, double distance, double angle) {
    int v2[2] = {b2.getX() - b1.getX(), b2.getY() - b1.getY()};
    return (getDistance(v2) <= distance);
};
