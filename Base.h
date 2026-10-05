#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Base {
public:
    Base() { std::cout << "[Base] Вызван конструктор без параметров\n"; }
    virtual ~Base() { std::cout << "[Base] Вызван деструктор\n"; }
    
    virtual void print() const = 0;
    virtual void edit() = 0;
    virtual void save(std::ofstream& out) const = 0;
    virtual void load(std::ifstream& in) = 0;
    virtual int getType() const = 0;
};