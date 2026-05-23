#pragma once
#include <string>

class Equipment {
    private:
    std::string id;
    std::string name;
    int baseValue;
    public:
    Equipment();
    Equipment(const std::string& i,const std::string& n,int bV);
    virtual ~Equipment();

    std::string getId() const;
    std::string getName() const;
    int getBaseValue() const;

    void setId(const std::string& newId);
    void setName(const std::string& newName);
    void setBaseValue(int newBaseValue);

    virtual double calculateOperationalPower() const = 0;
    virtual void saveToFile(std::ofstream& file) const;
};