#ifndef _OEIL_H_
#define _OEIL_H_

#include <math.h>


class Oeil : Capteur {

private:
    //Mesure l'angle entre le vecteur v1 et v2
    float getAngle(float[2] v1, float[2] v2);

    //v est le vecteur dont on calcule la norme
    float getNorm(float[2] v);

public:
    Oeil();
    bool vois(Bestiole b1,Bestiole b2, double distance, double angle);

};