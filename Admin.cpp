#include "Admin.h"

Admin::Admin() : fio(""), position(""), phone(""), responsibility("") {
    std::cout << "[Admin] Вызван конструктор без параметров\n";
}

Admin::Admin(std::string f, std::string p, std::string ph, std::string r) 
    : fio(f), position(p), phone(ph), responsibility(r) {
    std::cout << "[Admin] Вызван конструктор с параметрами\n";
}

Admin::Admin(const Admin& other) 
    : fio(other.fio), position(other.position), phone(other.phone), responsibility(other.responsibility) {
    std::cout << "[Admin] Вызван конструктор копирования\n";
}

Admin::~Admin() {
    std::cout << "[Admin] Вызван деструктор\n";
}

void Admin::print() const {
    std::cout << "--- АДМИНИСТРАТОР ---\nФИО: " << fio 
              << "\nДолжность: " << position << "\nТелефон: " << phone 
              << "\nЗона ответственности: " << responsibility << "\n";
}

void Admin::edit() {
    std::cout << "Введите ФИО: "; std::cin.ignore(); std::getline(std::cin, fio);
    std::cout << "Введите должность: "; std::getline(std::cin, position);
    std::cout << "Введите телефон: "; std::getline(std::cin, phone);
    std::cout << "Введите зону ответственности: "; std::getline(std::cin, responsibility);
}

void Admin::save(std::ofstream& out) const {
    out << fio << "\n" << position << "\n" << phone << "\n" << responsibility << "\n";
}

void Admin::load(std::ifstream& in) {
    std::getline(in >> std::ws, fio);
    std::getline(in >> std::ws, position);
    std::getline(in >> std::ws, phone);
    std::getline(in >> std::ws, responsibility);
}