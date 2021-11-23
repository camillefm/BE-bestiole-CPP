#ifndef _ACCESSOIRE_H_
#define _ACCESSOIRE_H_
#include <iostream>
#include <CImg.h>
#include "Bestiole.h"



class Accessoire {
	private:
		double minV;
		double maxV;

		double minW;
		double maxW;

		double minP;
		double maxP;

	public : 
		void modifieCaracteristique(int value, Bestiole bestiole);

}















#endif
