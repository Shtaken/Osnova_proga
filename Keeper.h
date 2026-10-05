#pragma once
#include "Base.h"
#include "Exception.h"

class Keeper {
private:
    Base** data;
    int size;
public:
    Keeper();
    ~Keeper();

    Keeper& operator+=(Base* obj);
    Keeper& operator-=(int index);

    void printAll() const;
    void editElement(int index);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};