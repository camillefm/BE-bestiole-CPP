#ifndef _GREGAIRE_H_
#define _GREGAIRE_H_

#include <math.h>
#include "Comportement.h"
#include "Bestiole.h"

using namespace std;

class Bestiole;

class Gregaire : virtual public Comportement {

public:
    Gregaire(void);
    std::vector<double>  move(Bestiole b1, std::vector<Bestiole> listBestiolesVues);

};

#endif