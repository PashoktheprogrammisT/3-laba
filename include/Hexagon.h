#ifndef HEXAGON_H
#define HEXAGON_H

#include "Figure.h"

class Hexagon : public Figure {
private:
    double side_length;
    
public:
    Hexagon() = default;
    Hexagon(double side);
    Hexagon(const std::vector<std::pair<double, double>>& verts);
    Hexagon(const Hexagon& other);
    
    std::pair<double, double> getCenter() const override;
    double getArea() const override;
    void printVertices() const override;
    void readFromStream(std::istream& is) override;
    
    Hexagon& operator=(const Hexagon& other);
    Hexagon& operator=(Hexagon&& other) noexcept;
    bool operator==(const Hexagon& other) const;
    
    double getSideLength() const;
    
private:
    void calculateVertices();
};

#endif
