#include "Equipment.hpp"
#include <iostream>
#include <string>
#include <fstream>

Equipment::Equipment() 
    : id("UNKNOWN_ID"), name("UNKNOWN_EQUIPMENT"), baseValue(0) {}
Equipment::Equipment(const std::string& i,const std::string& n,int bV)
    : id(i) , name(n) , baseValue(bV) {}
Equipment::~Equipment() {
    std::cout<<"ID:"<<id    
             <<"Name:"<<name
             <<"Base Value:"<<baseValue
             <<"[DESTROYED]"<<std::endl;
}

std::string Equipment::getId() const {
    return id;
}

std::string Equipment::getName() const {
    return name;
}

int Equipment::getBaseValue() const {
    return baseValue;
}


void Equipment::setId(const std::string& newId) {
    if(!newId.empty()) {
        id = newId;
        return;
    } 
    std::cerr<<"New Id Is Empty"<<std::endl;
}

void Equipment::setName(const std::string& newName) {
    if(!newName.empty()) {
        name = newName;
        return;
    } 
    std::cerr<<"New Name Is Empty"<<std::endl;
}

void Equipment::setBaseValue(int newBaseValue) {
    if(newBaseValue>=0) {
        baseValue = newBaseValue;
        return;
    } 
    std::cerr<<"[INVALID VALUE]"<<std::endl;

}

void Equipment::saveToFile(std::ofstream& file) const {
    if(!file.is_open()) {
        std::cerr<<"File Not Opened"<<std::endl;
        return;
    }

    file << id <<" "<< name <<" "<<baseValue<<" ";
}
