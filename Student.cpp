#include "Student.h"

Student::Student() : fio(""), group(""), specialty(""), course(1), avgGrade(0.0) {
    std::cout << "[Student] Вызван конструктор без параметров\n";
}

Student::Student(std::string f, std::string g, std::string s, int c, float avg) 
    : fio(f), group(g), specialty(s), course(c), avgGrade(avg) {
    std::cout << "[Student] Вызван конструктор с параметрами\n";
}

Student::Student(const Student& other) 
    : fio(other.fio), group(other.group), specialty(other.specialty), course(other.course), avgGrade(other.avgGrade) {
    std::cout << "[Student] Вызван конструктор копирования\n";
}

Student::~Student() {
    std::cout << "[Student] Вызван деструктор\n";
}

void Student::print() const {
    std::cout << "--- СТУДЕНТ ---\n"
              << "ФИО: " << fio << "\nГруппа: " << group 
              << "\nСпециальность: " << specialty 
              << "\nКурс: " << course << "\nСредний балл: " << avgGrade << "\n";
}

void Student::edit() {
    std::cout << "Введите ФИО: "; std::cin.ignore(); std::getline(std::cin, fio);
    std::cout << "Введите группу: "; std::getline(std::cin, group);
    std::cout << "Введите специальность: "; std::getline(std::cin, specialty);
    std::cout << "Введите курс: "; std::cin >> course;
    std::cout << "Введите средний балл: "; std::cin >> avgGrade;
}

void Student::save(std::ofstream& out) const {
    out << fio << "\n" << group << "\n" << specialty << "\n" << course << "\n" << avgGrade << "\n";
}

void Student::load(std::ifstream& in) {
    std::getline(in >> std::ws, fio);
    std::getline(in >> std::ws, group);
    std::getline(in >> std::ws, specialty);
    in >> course >> avgGrade;
}