#pragma once
#include "Equipment.hpp"
#include <iostream>
#include <string>

class Electronics : public Equipment {
    private:
    int powerConsuption;
    bool isFrequencyHopping;

    public:
    Electronics(const std::string& i, const std::string& n, int bV,int pC, bool iF = true);
    ~Electronics() override;
    double calculateOperationalPower() const override;
    void saveToFile(std::ofstream& file) const override;
};