#include "Peureuse.h"
#include "Comportement.h"
#include <iostream>
#include <vector>

using namespace std;


Peureuse::Peureuse(void){
};

std::vector<double> Peureuse::getBariBestiole(vector<Bestiole> listBestiolesVues){
    double xmoy=0;
    double ymoy=0;
    for(Bestiole bestiole : listBestiolesVues){
        xmoy+=bestiole.getX();
        ymoy+=bestiole.getY();
    }
    vector<double> result = {xmoy/listBestiolesVues.size(),ymoy/listBestiolesVues.size()};
    return result;
}

double Peureuse::getOppositeOrientation(Bestiole& peureuse, std::vector<double> bariBestiole){
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

std::vector<double> Peureuse::move(Bestiole& b1, std::vector<Bestiole> listBestiolesVues){
    double newOrientation = b1.getOrientation();
    double newSpeed = b1.getSpeed();

    if((int)listBestiolesVues.size()>nb_bstl_envi_max){
        vector<double> bariBestiole = getBariBestiole(listBestiolesVues);
        newOrientation = getOppositeOrientation(b1,bariBestiole);
        newSpeed = b1.getFleeingSpeed();};
    
    vector<double> result = {newSpeed, newOrientation};
    return result;
}
