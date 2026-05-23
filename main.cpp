#pragma once
#include <string>
#include <fstream>
#include <iostream>

class Equipment {
private:
    std::string id;
    std::string name;
    int baseValue;

public:
    Equipment();
    Equipment(const std::string& i, const std::string& n, int bV);
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

inline Equipment::Equipment() 
    : id("UNKNOWN_ID"), name("UNKNOWN_EQUIPMENT"), baseValue(0) {}

inline Equipment::Equipment(const std::string& i, const std::string& n, int bV)
    : id(i), name(n), baseValue(bV) {}

inline Equipment::~Equipment() {
    std::cout << "ID:" << id << " Name:" << name << " Base Value:" << baseValue << " [DESTROYED]" << std::endl;
}

inline std::string Equipment::getId() const { return id; }
inline std::string Equipment::getName() const { return name; }
inline int Equipment::getBaseValue() const { return baseValue; }

inline void Equipment::setId(const std::string& newId) {
    if(!newId.empty()) { id = newId; return; }
    std::cerr << "New Id Is Empty" << std::endl;
}

inline void Equipment::setName(const std::string& newName) {
    if(!newName.empty()) { name = newName; return; }
    std::cerr << "New Name Is Empty" << std::endl;
}

inline void Equipment::setBaseValue(int newBaseValue) {
    if(newBaseValue >= 0) { baseValue = newBaseValue; return; }
    std::cerr << "[INVALID VALUE]" << std::endl;
}

inline void Equipment::saveToFile(std::ofstream& file) const {
    file << id << " " << name << " " << baseValue << " ";
}