#ifndef _COMPORTEMENT_H_
#define _COMPORTEMENT_H_

#include "Comportement.h"
#include <vector>

using namespace std;

class Bestiole;


class Comportement {

public:

    virtual std::vector<double> move(Bestiole b1, std::vector<Bestiole> listBestiolesVues)=0;
};


#endif