#include <iostream>
#include <memory>
#include <string>
#include "Array.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"

// Функция для вывода меню пользователя
void printMenu() {
    std::cout << "1. Print all figures" << std::endl;  // Вывод всех фигур
    std::cout << "2. Add Pentagon" << std::endl;  // Добавить пятиугольник
    std::cout << "3. Print all areas" << std::endl;// Вывести площади всех фигур
    std::cout << "4. Add Hexagon" << std::endl;  // Добавить шестиугольник
    std::cout << "5. Remove figure by index" << std::endl;   // Удалить фигуру по индексу
    std::cout << "6. Print total area" << std::endl;     // Вывести общую площадь
    std::cout << "7. Add Octagon" << std::endl;         // Добавить восьмиугольник
    std::cout << "8. Print all centers" << std::endl;   // Вывести центры всех фигур
    std::cout << "9. Exit" << std::endl;      // Выход из программы
}

int main(){
    Array figures;      // Создаем массив для хранения фигур
    int choice;    // Переменная для выбора пользователя
    
    // Бесконечный цикл меню
    while (true) {
        printMenu();      // Показываем меню
        std::cin >> choice;  // Читаем выбор пользователя
        
        // Обрабатываем выбор пользователя
        switch (choice) {
            case 1: {
                // Добавление пятиугольника
                std::cout << "Enter pentagon side length: ";
                double side;
                std::cin >> side;
                figures.addFigure(std::make_unique<Pentagon>(side));
                std::cout << "Pentagon added successfully!" << std::endl;
                break;
            }
            case 2: {
                // Добавление шестиугольника
                std::cout << "Enter hexagon side length: ";
                double side;
                std::cin >> side;
                figures.addFigure(std::make_unique<Hexagon>(side));
                std::cout << "Hexagon added successfully!" << std::endl;
                break;
            }
            case 3: {
                // Добавление восьмиугольника
                std::cout << "Enter octagon side length: ";
                double side;
                std::cin >> side;
                figures.addFigure(std::make_unique<Octagon>(side));
                std::cout << "Octagon added successfully!" << std::endl;
                break;
            }
            case 4: {
                // Удаление фигуры по индексу
                if (figures.size() == 0) {
                    std::cout << "No figures to remove!" << std::endl;
                    break;
                }
                std::cout << "Enter index to remove (0-" << figures.size() - 1 << "): ";
                size_t index;
                std::cin >> index;
                try {
                    figures.removeFigure(index);
                    std::cout << "Figure removed successfully!" << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            }
            case 5: {
                // Вывод всех фигур
                if (figures.size() == 0) {
                    std::cout << "No figures to display!" << std::endl;
                } else {
                    std::cout << figures;  // Используем перегруженный оператор <<
                }
                break;
            }
            case 6: {
                // Вывод геометрических центров всех фигур
                if (figures.size() == 0) {
                    std::cout << "No figures to display!" << std::endl;
                } else {
                    figures.printAllCenters();
                }
                break;
            }
            case 7: {
                // Вывод площадей всех фигур
                if (figures.size() == 0) {
                    std::cout << "No figures to display!" << std::endl;
                } else {
                    figures.printAllAreas();
                }
                break;
            }
            case 8: {
                // Вывод общей площади всех фигур
                if (figures.size() == 0) {
                    std::cout << "No figures to calculate total area!" << std::endl;
                } else {
                    double total = figures.getTotalArea();
                    std::cout << "Total area of all figures: " << total << std::endl;
                }
                break;
            }
            case 9: {
                // Выход из программы
                std::cout << "Goodbye!" << std::endl;
                return 0;
            }
            default: {
                // Неверный ввод
                std::cout << "Invalid choice! Please try again." << std::endl;
                break;
            }
        }
    }
}
