#ifndef _KAMIKAZE_H_
#define _KAMIKAZE_H_

#include <math.h>
#include "Comportement.h"
#include "Bestiole.h"

using namespace std;

class Bestiole;

class Kamikaze : virtual public Comportement {

private:
    double getSquarredDistance(Bestiole& b1, Bestiole& b2);
    double getNewOrientation(Bestiole& japanese,Bestiole& american);

public:
    Kamikaze(void);
    virtual ~Kamikaze( void );
    std::vector<double>  move(Bestiole& b1, std::vector<Bestiole> listBestiolesVues) override;

};

#endif