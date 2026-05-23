#pragma once
#include <iostream>
#include <string>
#include <fstream>

template <typename T> 
class Military {
    private:
    T** items;
    int count;
    int capacity;

    public:
    Military(int cap = 20)
        : capacity(cap) , count(0) {
            items = new T*[capacity];
        }

    ~Military() {
        for(int i=0;i<count;i++) {
            delete items[i];
        }
        delete[] items;
    }

      void resize() {
        int newCapacity = capacity * 2;
        T** newItems = new T*[newCapacity];

        for(int i=0;i<capacity;i++) {
        newItems[i] = items[i];
        }

        for(int i=capacity;i<newCapacity;i++) {
            newItems[i] = nullptr;
        }

        delete[] items;
        items = newItems;
        capacity = newCapacity;
    }



    void addItem(T* I) {
        if(count>=capacity) {
            resize();
        }
        items[count] = I;
        count++;
    }


    
void saveFighters(const std::string& filename) {
        std::ofstream file(filename);

        if (!file.is_open()) {
            std::cerr << "Error: Could not open file for writing!" << std::endl;
            return;
        }

        file << count << "\n";

        for (int i = 0; i < count; i++) {
            if (items[i] != nullptr) {
          items[i]->saveToFile(file);
          file<<"\n";
            }
        }

        file.close();
        std::cout << "Successfully saved living fighters to " << filename << std::endl;
    }

void loadFighters(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for reading!" << std::endl;
        return;
    }
    
    for (int i = 0; i < count; i++) {
        if (items[i] != nullptr) {
            delete items[i];
        }
    }
    count = 0;

    int savedCount = 0;
    if (!(file >> savedCount)) {
        file.close();
        return; 
    }

    std::string type, id, name;
    int baseValue;

    for (int i = 0; i < savedCount; i++) {
        if (!(file >> type >> id >> name >> baseValue)) {
            break;
        }

        if (type == "AMMUNITION") {
            double caliber;
            int quantity;
            file >> caliber >> quantity; 

            T* newAmmo = reinterpret_cast<T*>(new Ammunition(id, name, baseValue, caliber, quantity));
            addItem(newAmmo);
        } 
        else if (type == "ELECTRONICS") {
            int powerConsumption;
            bool isFrequencyHopping;
            file >> powerConsumption >> isFrequencyHopping; 

            T* newElectro = reinterpret_cast<T*>(new Electronics(id, name, baseValue, powerConsumption, isFrequencyHopping));
            addItem(newElectro);
        }
    }

    file.close();
    std::cout << "Successfully loaded " << count << " items from " << filename << std::endl;
}
};
