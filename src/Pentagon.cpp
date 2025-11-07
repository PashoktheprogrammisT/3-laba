#include "Pentagon.h"
#include <iostream>
#include <cmath>

const double PI = 3.14159265358979323846;

Pentagon::Pentagon(double side) : side_length(side) {
    calculateVertices();
}

Pentagon::Pentagon(const std::vector<std::pair<double, double>>& verts) : Figure(verts) {
    if (verts.size() >= 2) {
        double dx = verts[0].first - verts[1].first;
        double dy = verts[0].second - verts[1].second;
        side_length = std::sqrt(dx * dx + dy * dy);
    }
}

Pentagon::Pentagon(const Pentagon& other) : Figure(other), side_length(other.side_length) {}

std::pair<double, double> Pentagon::getCenter() const {
    if (vertices.empty()) return {0, 0};
    
    double sum_x = 0, sum_y = 0;
    for (const auto& vertex : vertices) {
        sum_x += vertex.first;
        sum_y += vertex.second;
    }
    return {sum_x / vertices.size(), sum_y / vertices.size()};
}

double Pentagon::getArea() const {
    return (5.0 * side_length * side_length) / (4.0 * std::tan(PI / 5.0));
}

void Pentagon::printVertices() const {
    std::cout << "Pentagon vertices: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        std::cout << "(" << vertices[i].first << ", " << vertices[i].second << ")";
        if (i != vertices.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

void Pentagon::readFromStream(std::istream& is) {
    is >> side_length;
    calculateVertices();
}

Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (this != &other) {
        Figure::operator=(other);
        side_length = other.side_length;
    }
    return *this;
}

Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {
    if (this != &other) {
        Figure::operator=(std::move(other));
        side_length = other.side_length;
    }
    return *this;
}

bool Pentagon::operator==(const Pentagon& other) const {
    return Figure::operator==(other) && side_length == other.side_length;
}

double Pentagon::getSideLength() const {
    return side_length;
}

void Pentagon::calculateVertices() {
    vertices.clear();
    for (int i = 0; i < 5; ++i) {
        double angle = 2.0 * PI * i / 5.0 - PI / 2.0;
        double radius = side_length / (2.0 * std::sin(PI / 5.0));
        double x = radius * std::cos(angle);
        double y = radius * std::sin(angle);
        vertices.push_back({x, y});
    }
}
