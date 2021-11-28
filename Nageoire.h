#ifndef _NAGEOIRE_H_
#define _NAGEOIRE_H_
#include <iostream>
// #include <CImg.h>
#include "Bestiole.h"
#include "Accessoire.h"

class Nageoire{

	private :
		double maxV;



	public :
		Nageoire(double maxv); 
		virtual ~Nageoire( void );
		Nageoire();

		void modifieCaracteristique(Bestiole& bestiole) ;

};




#endif