#include "Keeper.h"
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"

Keeper::Keeper() : data(nullptr), size(0) {
    std::cout << "[Keeper] Конструктор\n";
}

Keeper::~Keeper() {
    for (int i = 0; i < size; ++i) delete data[i];
    delete[] data;
    std::cout << "[Keeper] Деструктор\n";
}

Keeper& Keeper::operator+=(Base* obj) {
    Base** newData = new Base*[size + 1];
    for (int i = 0; i < size; ++i) newData[i] = data[i];
    newData[size] = obj;
    delete[] data;
    data = newData;
    size++;
    return *this;
}

Keeper& Keeper::operator-=(int index) {
    if (size == 0) throw Exception("Ошибка: контейнер пуст, удалять нечего!");
    if (index < 0 || index >= size) throw Exception("Ошибка: неверный индекс элемента!");

    Base** newData = new Base*[size - 1];
    delete data[index];

    for (int i = 0, j = 0; i < size; ++i) {
        if (i != index) newData[j++] = data[i];
    }
    delete[] data;
    data = newData;
    size--;
    return *this;
}

void Keeper::printAll() const {
    if (size == 0) {
        std::cout << "ВУЗ пуст.\n";
        return;
    }
    for (int i = 0; i < size; ++i) {
        std::cout << "\n--- ID: " << i << " ---\n";
        data[i]->print();
    }
}

void Keeper::editElement(int index) {
    if (index < 0 || index >= size) throw Exception("Ошибка: неверный индекс для редактирования!");
    data[index]->edit();
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out.is_open()) throw Exception("Ошибка: не удалось открыть файл для записи!");
    out << size << "\n";
    for (int i = 0; i < size; ++i) {
        out << data[i]->getType() << "\n";
        data[i]->save(out);
    }
    out.close();
    std::cout << "Данные успешно сохранены в файл.\n";
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in.is_open()) throw Exception("Ошибка: не удалось открыть файл для чтения!");
    
    for (int i = 0; i < size; ++i) delete data[i];
    delete[] data;
    size = 0;
    data = nullptr;

    int newSize;
    if (!(in >> newSize)) return;

    for (int i = 0; i < newSize; ++i) {
        int type;
        in >> type;
        Base* obj = nullptr;
        if (type == 1) obj = new Student();
        else if (type == 2) obj = new Teacher();
        else if (type == 3) obj = new Admin();
        
        if (obj) {
            obj->load(in);
            *this += obj;
        }
    }
    in.close();
    std::cout << "Данные успешно восстановлены из файла.\n";
}