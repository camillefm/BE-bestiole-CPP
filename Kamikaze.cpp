#include "Kamikaze.h"
#include "Comportement.h"
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;


Kamikaze::Kamikaze(void){
    return;
};

double Kamikaze::getSquarredDistance(Bestiole b1, Bestiole b2){
    return pow ((b2.getX()-b1.getX()) , 2) + pow ((b2.getY()-b1.getY()) , 2);
}

double Kamikaze::getNewOrientation(Bestiole japanese, Bestiole american){
    double v[2] = {(double)(american.getX()-japanese.getX()),(double)(american.getY()-japanese.getY())};
    if (v[0]==0){
        if (v[1] >0) { return M_PI/2;}
        else {return 3*M_PI/2;}
    }
    else if (v[1]==0) {
        if (v[0] >0) { return 0;}
        else {return M_PI;}
    }
    else if(v[1]>0){
        if (v[0]>0){
    
            return atan(v[1]/v[0]);}
        else { 
            return (M_PI-atan(-v[1]/v[0]));}
    }
    else if (v[1]<0){
        if (v[0]>0){
            return 2*M_PI-atan (v[1]/v[0]);}
        else { return M_PI + atan ( - v[1]/v[0]);}
    }
    return 0;
}

std::vector<double> Kamikaze::move(Bestiole b1, std::vector<Bestiole> listBestiolesVues){
    double minDistance=getSquarredDistance(b1,listBestiolesVues.front());
    int closestBestioleIndex=0;
    float newDistance=0;
    for (int i=1; i<(int)listBestiolesVues.size();i=i+1 ){
        newDistance=getSquarredDistance(listBestiolesVues[i],b1);
        if (newDistance<minDistance){
            minDistance=newDistance;
            closestBestioleIndex=i;
        }
    }

    double newOrientation = getNewOrientation(b1,listBestiolesVues[closestBestioleIndex]);
    vector<double>  result = {b1.getSpeed(),newOrientation};
    return result;
}
