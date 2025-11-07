#include "Octagon.h"
#include <iostream>
#include <cmath>

const double PI = 3.14159265358979323846;

Octagon::Octagon(double side) : side_length(side) {
    calculateVertices();
}

Octagon::Octagon(const std::vector<std::pair<double, double>>& verts) : Figure(verts) {
    if (verts.size() >= 2) {
        double dx = verts[0].first - verts[1].first;
        double dy = verts[0].second - verts[1].second;
        side_length = std::sqrt(dx * dx + dy * dy);
    }
}

Octagon::Octagon(const Octagon& other) : Figure(other), side_length(other.side_length) {}

std::pair<double, double> Octagon::getCenter() const {
    if (vertices.empty()) return {0, 0};
    
    double sum_x = 0, sum_y = 0;
    for (const auto& vertex : vertices) {
        sum_x += vertex.first;
        sum_y += vertex.second;
    }
    return {sum_x / vertices.size(), sum_y / vertices.size()};
}

double Octagon::getArea() const {
    return 2.0 * (1.0 + std::sqrt(2.0)) * side_length * side_length;
}

void Octagon::printVertices() const {
    std::cout << "Octagon vertices: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        std::cout << "(" << vertices[i].first << ", " << vertices[i].second << ")";
        if (i != vertices.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

void Octagon::readFromStream(std::istream& is) {
    is >> side_length;
    calculateVertices();
}

Octagon& Octagon::operator=(const Octagon& other) {
    if (this != &other) {
        Figure::operator=(other);
        side_length = other.side_length;
    }
    return *this;
}

Octagon& Octagon::operator=(Octagon&& other) noexcept {
    if (this != &other) {
        Figure::operator=(std::move(other));
        side_length = other.side_length;
    }
    return *this;
}

bool Octagon::operator==(const Octagon& other) const {
    return Figure::operator==(other) && side_length == other.side_length;
}

double Octagon::getSideLength() const {
    return side_length;
}

void Octagon::calculateVertices() {
    vertices.clear();
    for (int i = 0; i < 8; ++i) {
        double angle = 2.0 * PI * i / 8.0 - PI / 8.0;
        double radius = side_length / (2.0 * std::sin(PI / 8.0));
        double x = radius * std::cos(angle);
        double y = radius * std::sin(angle);
        vertices.push_back({x, y});
    }
}
