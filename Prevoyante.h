#ifndef _PREVOYANTE_H_
#define _PREVOYANTE_H_

#include <math.h>
#include "Comportement.h"
#include "Prevoyante.h"
#include "Bestiole.h"

using namespace std;

class Bestiole;

class Prevoyante : virtual public Comportement {

private :
    double getDistance(Bestiole b1, Bestiole b2);
    double getSquarredDistance(Bestiole b1, Bestiole b2);
    std::vector<double> getNextPosition(Bestiole b);
    double getOppositeOrientation(Bestiole peureuse, std::vector<double> bariBestiole);
    std::vector<double> getFutureBariBestiole(Bestiole peureuse,vector<Bestiole> listBestiolesVues);

public:
    Prevoyante(void);
    std::vector<double>  move(Bestiole b1, std::vector<Bestiole> listBestiolesVues);

};

#endif