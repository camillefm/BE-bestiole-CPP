#ifndef _CAMOUFLAGE_H_
#define _CAMOUFLAGE_H_
#include <iostream>
// #include <CImg.h>
#include "Bestiole.h"
#include "Accessoire.h"
class Camouflage : public Accessoire{

	private :
		double minP;
		double maxP;

	public : 

		Camouflage(double minp, double maxp);
		virtual ~Camouflage( void );
		void modifieCaracteristique(Bestiole& bestiole) override;


};





#endif