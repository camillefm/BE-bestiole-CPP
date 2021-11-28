#include "Gregaire.h"
#include "Comportement.h"
#include <iostream>
#include <vector>

using namespace std;


Gregaire::Gregaire(void){
    return;
};

std::vector<double> Gregaire::move(Bestiole b1, std::vector<Bestiole> listBestiolesVues){
    double totalOrientation=0;
    for (Bestiole d : listBestiolesVues){
        totalOrientation+=d.getOrientation();
    }
    double newOrientation = totalOrientation/listBestiolesVues.size();
    vector<double>  result = {b1.getSpeed(),newOrientation};
    return result;
}
