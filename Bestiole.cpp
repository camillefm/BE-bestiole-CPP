#include "Bestiole.h"
#include "Comportement.h"
#include "Gregaire.h"
#include "Kamikaze.h"
#include "Peureuse.h"


#include "Milieu.h"

#include <cstdlib>
#include <cmath>


const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;

int               Bestiole::next = 0;



Bestiole::Bestiole( void )
{

   Gregaire comportement();

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par defaut" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

}


Bestiole::Bestiole( const Bestiole & b )
{

   comportement = new Peureuse;

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par copie" << endl;

   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   couleur = new T[ 3 ];
   memcpy( couleur, b.couleur, 3*sizeof(T) );

}


Bestiole::~Bestiole( void )
{

   delete[] couleur;

   cout << "dest Bestiole" << endl;

}


void Bestiole::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}


void Bestiole::bouge( int xLim, int yLim ,std::vector<Bestiole> listBestioles)
{



   double         nx, ny;
   double         dx = cos( orientation )*vitesse;
   double         dy = -sin( orientation )*vitesse;
   int            cx, cy;


   cx = 0 ;//static_cast<int>( cumulX ); cumulX -= cx;
   cy =0 ;// static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }

   vector<double> future = comportement->move(*this,listBestioles);



   double kaka=future[1]-orientation;

   if (kaka<-M_PI){kaka+=7*2*M_PI;}
   while (kaka>=M_PI){
      kaka-=2*M_PI;

   }

   std::cout <<"Pré-Orientation="<<std::endl;
   std::cout <<orientation<<std::endl;
   std::cout <<"KAKA="<<std::endl;
   std::cout <<kaka<<std::endl;
   orientation = future[1];
   //orientation += 0.5*kaka/6;
   std::cout <<"Après-Orientation= "<<std::endl;
   std::cout <<orientation<<std::endl;

}


void Bestiole::action( Milieu & monMilieu )
{

   bouge( monMilieu.getWidth(), monMilieu.getHeight() , monMilieu.getlisteBestioles());

}


void Bestiole::draw( UImg & support )
{

   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;


   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

}


bool operator==( const Bestiole & b1, const Bestiole & b2 )
{

   return ( b1.identite == b2.identite );

}


bool Bestiole::jeTeVois( const Bestiole & b ) const
{

   double         dist;


   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   return ( dist <= LIMITE_VUE );

}

int Bestiole::getX(){
   return x;
}

int Bestiole::getY(){
   return y;
}

void Bestiole::setX(int newX){
   x=newX;
}

void Bestiole::setY(int newY){
   y=newY;
}

double Bestiole::getSpeed(){
   return vitesse;
}

double Bestiole::getFleeingSpeed(){
   return vitesse;
}

double Bestiole::getOrientation(){
   return orientation;
}

void Bestiole::setSpeed(double speed){
   vitesse=speed;
}

void Bestiole::setOrientation(double angle){
   orientation=angle;
}

void Bestiole::setV(double v){
   V=v;
}

void Bestiole::setW(double w){
   W=w;
}

void Bestiole::setN(double n){
   N=n;
}


void Bestiole::setP(double p){
   P=p;
}