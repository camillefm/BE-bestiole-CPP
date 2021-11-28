#ifndef _CARAPACE_H_
#define _CARAPACE_H_
#include <iostream>
// #include <CImg.h>
#include "Bestiole.h"
#include "Accessoire.h"

class Carapace : public Accessoire{

	private : 
		double maxW;
		double maxN;


	public :

		Carapace(double maxw, double maxn);
		virtual ~Carapace( void );

		void modifieCaracteristique(Bestiole& bestiole) override;

};






#endif