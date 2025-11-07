#include <iostream>
#include <memory>
#include <string>
#include "Array.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"

void printMenu() {
    std::cout << "1. Add Pentagon" << std::endl;
    std::cout << "2. Add Hexagon" << std::endl;
    std::cout << "3. Add Octagon" << std::endl;
    std::cout << "4. Remove figure by index" << std::endl;
    std::cout << "5. Print all figures" << std::endl;
    std::cout << "6. Print all centers" << std::endl;
    std::cout << "7. Print all areas" << std::endl;
    std::cout << "8. Print total area" << std::endl;
    std::cout << "9. Exit" << std::endl;

}

int main() {
    Array figures;
    int choice;

    
    while (true) {
        printMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                std::cout << "Enter pentagon side length: ";
                double side;
                std::cin >> side;
                figures.addFigure(std::make_unique<Pentagon>(side));
                std::cout << "Pentagon added successfully!" << std::endl;
                break;
            }
            case 2: {
                std::cout << "Enter hexagon side length: ";
                double side;
                std::cin >> side;
                figures.addFigure(std::make_unique<Hexagon>(side));
                std::cout << "Hexagon added successfully!" << std::endl;
                break;
            }
            case 3: {
                std::cout << "Enter octagon side length: ";
                double side;
                std::cin >> side;
                figures.addFigure(std::make_unique<Octagon>(side));
                std::cout << "Octagon added successfully!" << std::endl;
                break;
            }
            case 4: {
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
                if (figures.size() == 0) {
                    std::cout << "No figures to display!" << std::endl;
                } else {
                    std::cout << figures;
                }
                break;
            }
            case 6: {
                if (figures.size() == 0) {
                    std::cout << "No figures to display!" << std::endl;
                } else {
                    figures.printAllCenters();
                }
                break;
            }
            case 7: {
                if (figures.size() == 0) {
                    std::cout << "No figures to display!" << std::endl;
                } else {
                    figures.printAllAreas();
                }
                break;
            }
            case 8: {
                if (figures.size() == 0) {
                    std::cout << "No figures to calculate total area!" << std::endl;
                } else {
                    double total = figures.getTotalArea();
                    std::cout << "Total area of all figures: " << total << std::endl;
                }
                break;
            }
            case 9: {
                std::cout << "Goodbye!" << std::endl;
                return 0;
            }
            default: {
                std::cout << "Invalid choice! Please try again." << std::endl;
                break;
            }
        }
    }
    
    return 0;
}
