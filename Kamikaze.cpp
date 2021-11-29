#include "Kamikaze.h"
#include "Comportement.h"
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;


Kamikaze::Kamikaze(void){
};

Kamikaze::~Kamikaze(){}

double Kamikaze::getSquarredDistance(Bestiole& b1, Bestiole& b2){
    return pow ((b2.getX()-b1.getX()) , 2) + pow ((b2.getY()-b1.getY()) , 2);
}

double Kamikaze::getNewOrientation(Bestiole& japanese, Bestiole& american){

    double v[2] = {(double)(american.getX()-japanese.getX()),(double)(american.getY()-japanese.getY())};
    
    std::cout <<v[0]<<std::endl;
    std::cout <<v[1]<<std::endl;
   
    if (v[0]==0){
        if (v[1] >0) { 
            return M_PI/2;}
        else {return 3*M_PI/2;}
    }
    else if (v[0]>0) {
        return atan(v[1]/v[0]);
    }

    else if(v[0]<0){
        return M_PI+atan(v[1]/v[0]);}
    return 0;
}

std::vector<double> Kamikaze::move(Bestiole& b1, std::vector<Bestiole> listBestiolesVues){
    double minDistance=getSquarredDistance(*listBestiolesVues.begin(),b1);
    int closestBestioleIndex=0;
    int index=0;
    float newDistance=0;

    for ( std::vector<Bestiole>::iterator it = listBestiolesVues.begin() ; it != listBestiolesVues.end() ; ++it ){
        newDistance=getSquarredDistance(*it,b1);
        std::cout <<"distance"<<std::endl;
        std::cout <<newDistance<<std::endl;
        std::cout <<"minDistance"<<std::endl;
        std::cout <<minDistance<<std::endl;
        if ((newDistance>100) && (newDistance<=minDistance)){
            std::cout <<newDistance<<std::endl;
            minDistance=newDistance;
            closestBestioleIndex=index;}
        index+=1;
    }
    std::cout <<"finalIndex"<<std::endl;
    std::cout <<closestBestioleIndex<<std::endl;

    double newOrientation = getNewOrientation(b1,*listBestiolesVues.begin());
    std::cout <<newOrientation<<std::endl;
    vector<double>  result = {b1.getSpeed(),newOrientation};
    return result;
}
