#include <iostream>
#include <windows.h>
#include "Keeper.h"
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"
#include "Exception.h"

void displayMenu() {

    
    std::cout << "\n===== МЕНЮ ВУЗ =====\n"
              << "1. Добавить студента\n"
              << "2. Добавить преподавателя\n"
              << "3. Добавить администратора\n"
              << "4. Вывести всех\n"
              << "5. Изменить данные объекта\n"
              << "6. Удалить объект\n"
              << "7. Сохранить в файл\n"
              << "8. Загрузить из файла\n"
              << "0. Выход\n"
              << "Выберите действие: ";
}

int main() {
    
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Keeper vuz;
    int choice = -1;

    while (choice != 0) {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        try {
            switch (choice) {
                case 1: {
                    Base* s = new Student();
                    s->edit();
                    vuz += s;
                    break;
                }
                case 2: {
                    Base* t = new Teacher();
                    t->edit();
                    vuz += t;
                    break;
                }
                case 3: {
                    Base* a = new Admin();
                    a->edit();
                    vuz += a;
                    break;
                }
                case 4:
                    vuz.printAll();
                    break;
                case 5: {
                    int id;
                    std::cout << "Введите ID для изменения: ";
                    std::cin >> id;
                    vuz.editElement(id);
                    break;
                }
                case 6: {
                    int id;
                    std::cout << "Введите ID для удаления: ";
                    std::cin >> id;
                    vuz -= id;
                    std::cout << "Объект успешно удален.\n";
                    break;
                }
                case 7:
                    vuz.saveToFile("vuz_data.txt");
                    break;
                case 8:
                    vuz.loadFromFile("vuz_data.txt");
                    break;
                case 0:
                    std::cout << "Завершение программы.\n";
                    break;
                default:
                    std::cout << "Неизвестный пункт меню!\n";
            }
        } catch (const Exception& e) {
            std::cerr << "\n[!] ПЕРЕХВАЧЕНО ИСКЛЮЧЕНИЕ: " << e.getMessage() << "\n";
        }
    }
    return 0;
}