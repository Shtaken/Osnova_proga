#include "Teacher.h"

Teacher::Teacher() : fio(""), groups(nullptr), groupCount(0), subjects(nullptr), subjectCount(0) {
    std::cout << "[Teacher] Вызван конструктор без параметров\n";
}

Teacher::Teacher(std::string f, int gc, int sc) : fio(f), groupCount(gc), subjectCount(sc) {
    groups = new std::string[groupCount];
    subjects = new std::string[subjectCount];
    std::cout << "[Teacher] Вызван конструктор с параметрами\n";
}

Teacher::Teacher(const Teacher& other) : fio(other.fio), groupCount(other.groupCount), subjectCount(other.subjectCount) {
    groups = new std::string[groupCount];
    for(int i = 0; i < groupCount; ++i) groups[i] = other.groups[i];
    subjects = new std::string[subjectCount];
    for(int i = 0; i < subjectCount; ++i) subjects[i] = other.subjects[i];
    std::cout << "[Teacher] Вызван конструктор копирования\n";
}

Teacher::~Teacher() {
    delete[] groups;
    delete[] subjects;
    std::cout << "[Teacher] Вызван деструктор\n";
}

void Teacher::print() const {
    std::cout << "--- ПРЕПОДАВАТЕЛЬ ---\nФИО: " << fio << "\nГруппы: ";
    for(int i = 0; i < groupCount; ++i) std::cout << groups[i] << " ";
    std::cout << "\nПредметы: ";
    for(int i = 0; i < subjectCount; ++i) std::cout << subjects[i] << " ";
    std::cout << "\n";
}

void Teacher::edit() {
    std::cout << "Введите ФИО преподавателя: "; std::cin.ignore(); std::getline(std::cin, fio);
    delete[] groups;
    std::cout << "Количество групп: "; std::cin >> groupCount;
    groups = new std::string[groupCount];
    std::cin.ignore();
    for(int i = 0; i < groupCount; ++i) {
        std::cout << "Группа " << i + 1 << ": "; std::getline(std::cin, groups[i]);
    }
    delete[] subjects;
    std::cout << "Количество предметов: "; std::cin >> subjectCount;
    subjects = new std::string[subjectCount];
    std::cin.ignore();
    for(int i = 0; i < subjectCount; ++i) {
        std::cout << "Предмет " << i + 1 << ": "; std::getline(std::cin, subjects[i]);
    }
}

void Teacher::save(std::ofstream& out) const {
    out << fio << "\n" << groupCount << "\n";
    for(int i = 0; i < groupCount; ++i) out << groups[i] << "\n";
    out << subjectCount << "\n";
    for(int i = 0; i < subjectCount; ++i) out << subjects[i] << "\n";
}

void Teacher::load(std::ifstream& in) {
    std::getline(in >> std::ws, fio);
    in >> groupCount;
    delete[] groups;
    groups = new std::string[groupCount];
    for(int i = 0; i < groupCount; ++i) std::getline(in >> std::ws, groups[i]);
    in >> subjectCount;
    delete[] subjects;
    subjects = new std::string[subjectCount];
    for(int i = 0; i < subjectCount; ++i) std::getline(in >> std::ws, subjects[i]);
}