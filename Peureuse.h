#ifndef _PEUREUSE_H_
#define _PEUREUSE_H_

#include <math.h>
#include "Comportement.h"
#include "Bestiole.h"

using namespace std;

class Bestiole;

class Peureuse : virtual public Comportement {

private :
    const int nb_bstl_envi_max=0;
    double getOppositeOrientation(Bestiole& peureuse, std::vector<double> bariBestiole);
    std::vector<double> getBariBestiole(vector<Bestiole> listBestiolesVues);

public:
    Peureuse(void);
    std::vector<double>  move(Bestiole& b1, std::vector<Bestiole> listBestiolesVues);

};

#endif