#pragma once
#include "Base.h"

class Teacher : public Base {
private:
    std::string fio;
    std::string* groups;
    int groupCount;
    std::string* subjects;
    int subjectCount;
public:
    Teacher();
    Teacher(std::string f, int gc, int sc);
    Teacher(const Teacher& other);
    ~Teacher() override;

    void print() const override;
    void edit() override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
    int getType() const override { return 2; }
    
    Teacher& operator=(const Teacher& other);
};