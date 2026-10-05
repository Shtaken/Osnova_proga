#pragma once
#include "Base.h"

class Admin : public Base {
private:
    std::string fio;
    std::string position;
    std::string phone;
    std::string responsibility;
public:
    Admin();
    Admin(std::string f, std::string p, std::string ph, std::string r);
    Admin(const Admin& other);
    ~Admin() override;

    void print() const override;
    void edit() override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
    int getType() const override { return 3; }
};