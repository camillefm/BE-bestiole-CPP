
#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"
#include "Comportement.h"
//#include "Accessoire.h"

#include <iostream>

using namespace std;


class Milieu;


class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;


private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;

   T               * couleur;

      //new code :
   //Comportement      comportement;

   //listCapteurs :    listCapteur
   //listAccessoires:  listAccesoires
   //int               dieProbabilty;
   //int               camouflage;

   //int :             ageLimite;
   //int :             age;



private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );

   int getX();
   int getY();
   void setX(int newX);
   void setY(int newY);

   double getSpeed();
   double getOrientation(); 

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

};


#endif
