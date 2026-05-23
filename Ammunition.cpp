#include "Ammunition.hpp"
#include <iostream>
#include <string>
#include <fstream>

Ammunition::Ammunition(const std::string& i, const std::string& n, int bV,double c,int q)
    :  Equipment(i,n,bV) , caliber(c) , quantity(q) {}
Ammunition::~Ammunition() {}

double Ammunition::calculateOperationalPower() const {
    return (getBaseValue() * quantity * 1.5);
}
  
void Ammunition::saveToFile(std::ofstream& file) const {
  if(!file.is_open()) {
        std::cerr<<"File Not Opened"<<std::endl;
        return;
    }

    file << "AMMUNITION ";
    Equipment::saveToFile(file);

    file << caliber <<" "<<quantity<<" ";

}
