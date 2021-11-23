#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Capteur.h"
#include "Oeil.h"

#include <iostream>

using namespace std;


int main()
{

   Bestiole b1;
   Bestiole b2;






   //Aquarium       ecosysteme( 640, 480, 30 );

   //for ( int i = 1; i <= 2; ++i )
   //   ecosysteme.getMilieu().addMember( Bestiole() );


   b1.setX(1);
   b1.setY(1);

   b2.setX(2);
   b2.setY(2);

   Oeil o;
   std::cout <<o.vois(b1,b2,100,1) <<std::endl;

   //printf(b1.getX());



   //ecosysteme.run();


   return 0;

}
