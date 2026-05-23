#include "Electronics.hpp"
#include <iostream>
#include <string>
#include <fstream>

Electronics::Electronics(const std::string& i, const std::string& n, int bV, int pC, bool iF)
    :  Equipment(i,n,bV) , powerConsuption(pC) , isFrequencyHopping(iF) {}
Electronics::~Electronics() {}

double Electronics::calculateOperationalPower() const {
   if(isFrequencyHopping) {
    return (getBaseValue() * 2);
   }

   else {
    return getBaseValue();
   }
}
  

void Electronics::saveToFile(std::ofstream& file) const {
  if(!file.is_open()) {
        std::cerr<<"File Not Opened"<<std::endl;
        return;
    }

    Equipment::saveToFile(file);

    file << powerConsuption << " " << isFrequencyHopping <<" ";

}


