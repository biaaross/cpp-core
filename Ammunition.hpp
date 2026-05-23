#pragma once
#include "Equipment.hpp"
#include <iostream>
#include <string>


class Ammunition : public Equipment {
    private:
    double caliber;
    int quantity;

    public:
    Ammunition(const std::string& i, const std::string& n, int bV,double c,int q);
    ~Ammunition() override;
    double calculateOperationalPower() const override;
    void saveToFile(std::ofstream& file) const override;
};