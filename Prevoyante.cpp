#include "Prevoyante.h"
#include "Comportement.h"
#include <iostream>
#include <vector>

using namespace std;

double Prevoyante::getDistance(Bestiole b1, Bestiole b2){
    return sqrt (pow ((b2.getX()-b1.getX()) , 2) + pow ((b2.getY()-b1.getY()) , 2) );
}

Prevoyante::Prevoyante(void){
    return;
};

std::vector<double> Prevoyante::getFutureBariBestiole(Bestiole peureuse,vector<Bestiole> listBestiolesVues){
    double xmoy=0;
    double ymoy=0;
    double totalDistance=0;

    for(Bestiole bestiole : listBestiolesVues){
        vector<double> nextPos = getNextPosition(bestiole);
        double distance=getDistance(peureuse,bestiole);
        totalDistance+=distance;
        xmoy+= distance * nextPos[0];
        ymoy+= distance * nextPos[1];
    }

    xmoy=xmoy/totalDistance;
    ymoy=ymoy/totalDistance;

    vector<double> result = {xmoy,ymoy};
    return result;
}

double Prevoyante::getOppositeOrientation(Bestiole peureuse, std::vector<double> bariBestiole){
    double v[2] = {(double)(bariBestiole[0]-peureuse.getX()),(double)(bariBestiole[1]-peureuse.getY())};
    if (v[0]==0){
        if (v[1] >0) { return 3*M_PI/2;}
        else {return M_PI/2;}
    }
    else if (v[1]==0) {
        if (v[0] >0) { return M_PI;}
        else {return 0;}
    }
    else if(v[1]>0){
        if (v[0]>0){
            return (M_PI + atan(v[1]/v[0]));}
        else { 
            return (2*M_PI-atan(-v[1]/v[0]));}
    }
    else if (v[1]<0){
        if (v[0]>0){
            return M_PI-atan (-v[1]/v[0]);}
        else { return atan ( v[1]/v[0]);}
    }
    return 0;
}

std::vector<double> Prevoyante::move(Bestiole b1, std::vector<Bestiole> listBestiolesVues){
    vector<double> futureBariBestiole = getFutureBariBestiole(b1,listBestiolesVues);
    double newOrientation = getOppositeOrientation(b1,futureBariBestiole);
    
    double newSpeed = b1.getSpeed();
    vector<double> result = {newSpeed, newOrientation};
    return result;
}

std::vector<double> Prevoyante::getNextPosition(Bestiole b){
    double speed = b.getSpeed();
    double orientation = b.getOrientation();
    double dx = cos( orientation )*speed;
    double dy = -sin( orientation )*speed;

    vector<double> result = {b.getX() + dx , b.getY() + dy};
    return result;
}
