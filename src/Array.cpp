#include "Array.h"
#include <iostream>
#include <stdexcept>

Array::Array(const Array& other) {
    copyFigures(other);
}

Array::Array(Array&& other) noexcept : figures(std::move(other.figures)) {}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        figures.clear();
        copyFigures(other);
    }
    return *this;
}

Array& Array::operator=(Array&& other) noexcept {
    if (this != &other) {
        figures = std::move(other.figures);
    }
    return *this;
}

void Array::addFigure(std::unique_ptr<Figure> figure) {
    figures.push_back(std::move(figure));
}

void Array::removeFigure(size_t index) {
    if (index >= figures.size()) {
        throw std::out_of_range("Index out of range");
    }
    figures.erase(figures.begin() + index);
}

size_t Array::size() const {
    return figures.size();
}

Figure* Array::getFigure(size_t index) const {
    if (index >= figures.size()) {
        throw std::out_of_range("Index out of range");
    }
    return figures[index].get();
}

void Array::printAllCenters() const {
    std::cout << "Geometric centers of all figures:" << std::endl;
    for (size_t i = 0; i < figures.size(); ++i) {
        auto center = figures[i]->getCenter();
        std::cout << "Figure " << i << ": (" << center.first << ", " << center.second << ")" << std::endl;
    }
}

void Array::printAllAreas() const {
    std::cout << "Areas of all figures:" << std::endl;
    for (size_t i = 0; i < figures.size(); ++i) {
        double area = figures[i]->getArea();
        std::cout << "Figure " << i << ": " << area << std::endl;
    }
}

double Array::getTotalArea() const {
    double total = 0.0;
    for (const auto& figure : figures) {
        total += figure->getArea();
    }
    return total;
}

std::ostream& operator<<(std::ostream& os, const Array& array) {
    for (size_t i = 0; i < array.figures.size(); ++i) {
        os << "Figure " << i << ": ";
        array.figures[i]->printVertices();
    }
    return os;
}

void Array::copyFigures(const Array& other) {
    figures.reserve(other.figures.size());
    for (const auto& figure : other.figures) {
        if (dynamic_cast<const Pentagon*>(figure.get())) {
            figures.push_back(std::make_unique<Pentagon>(*dynamic_cast<const Pentagon*>(figure.get())));
        } else if (dynamic_cast<const Hexagon*>(figure.get())) {
            figures.push_back(std::make_unique<Hexagon>(*dynamic_cast<const Hexagon*>(figure.get())));
        } else if (dynamic_cast<const Octagon*>(figure.get())) {
            figures.push_back(std::make_unique<Octagon>(*dynamic_cast<const Octagon*>(figure.get())));
        }
    }
}
