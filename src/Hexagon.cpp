#include "Hexagon.h"
#include <iostream>
#include <cmath>

const double PI = 3.14159265358979323846;

Hexagon::Hexagon(double side) : side_length(side) {
    calculateVertices();
}

Hexagon::Hexagon(const std::vector<std::pair<double, double>>& verts) : Figure(verts) {
    if (verts.size() >= 2) {
        double dx = verts[0].first - verts[1].first;
        double dy = verts[0].second - verts[1].second;
        side_length = std::sqrt(dx * dx + dy * dy);
    }
}

Hexagon::Hexagon(const Hexagon& other) : Figure(other), side_length(other.side_length) {}

std::pair<double, double> Hexagon::getCenter() const {
    if (vertices.empty()) return {0, 0};
    
    double sum_x = 0, sum_y = 0;
    for (const auto& vertex : vertices) {
        sum_x += vertex.first;
        sum_y += vertex.second;
    }
    return {sum_x / vertices.size(), sum_y / vertices.size()};
}

double Hexagon::getArea() const {
    return (3.0 * std::sqrt(3.0) * side_length * side_length) / 2.0;
}

void Hexagon::printVertices() const {
    std::cout << "Hexagon vertices: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        std::cout << "(" << vertices[i].first << ", " << vertices[i].second << ")";
        if (i != vertices.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

void Hexagon::readFromStream(std::istream& is) {
    is >> side_length;
    calculateVertices();
}

Hexagon& Hexagon::operator=(const Hexagon& other) {
    if (this != &other) {
        Figure::operator=(other);
        side_length = other.side_length;
    }
    return *this;
}

Hexagon& Hexagon::operator=(Hexagon&& other) noexcept {
    if (this != &other) {
        Figure::operator=(std::move(other));
        side_length = other.side_length;
    }
    return *this;
}

bool Hexagon::operator==(const Hexagon& other) const {
    return Figure::operator==(other) && side_length == other.side_length;
}

double Hexagon::getSideLength() const {
    return side_length;
}

void Hexagon::calculateVertices() {
    vertices.clear();
    for (int i = 0; i < 6; ++i) {
        double angle = 2.0 * PI * i / 6.0;
        double x = side_length * std::cos(angle);
        double y = side_length * std::sin(angle);
        vertices.push_back({x, y});
    }
}
