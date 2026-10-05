#pragma once
#include "Base.h"

class Student : public Base {
private:
    std::string fio;
    std::string group;
    std::string specialty;
    int course;
    float avgGrade;
public:
    Student();
    Student(std::string f, std::string g, std::string s, int c, float avg);
    Student(const Student& other);
    ~Student() override;

    void print() const override;
    void edit() override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
    int getType() const override { return 1; }

    void setFio(std::string f) { fio = f; }
    std::string getFio() const { return fio; }
    void setCourse(int c) { course = c; }
    int getCourse() const { return course; }
};