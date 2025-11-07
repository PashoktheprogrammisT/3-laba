#include <gtest/gtest.h>
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"
#include "Array.h"
#include <memory>
#include <cmath>

// Тест для проверки площади пятиугольника
TEST(PentagonTest, BasicArea) {
    // Создаем пятиугольник со стороной 5
    Pentagon pentagon(5.0);
    // Вычисляем ожидаемую площадь по формуле
    double expected_area = (5.0 * 5.0 * 5.0) / (4.0 * std::tan(M_PI / 5.0));
    // Проверяем, что площадь, возвращаемая методом, очень близка к ожидаемой
    EXPECT_NEAR(pentagon.getArea(), expected_area, 1e-10);
}
TEST(PentagonTest, Center) {
    Pentagon pentagon(5.0);
    auto center = pentagon.getCenter();
    EXPECT_NEAR(center.first, 0.0, 1e-10);
    EXPECT_NEAR(center.second, 0.0, 1e-10);
}

TEST(HexagonTest, BasicArea) {
    Hexagon hexagon(4.0);
    double expected_area = (3.0 * std::sqrt(3.0) * 4.0 * 4.0) / 2.0;
    EXPECT_DOUBLE_EQ(hexagon.getArea(), expected_area);
}

TEST(HexagonTest, Center) {
    Hexagon hexagon(4.0);
    auto center = hexagon.getCenter();
    EXPECT_NEAR(center.first, 0.0, 1e-10);
    EXPECT_NEAR(center.second, 0.0, 1e-10);
}

TEST(OctagonTest, BasicArea) {
    Octagon octagon(3.0);
    double expected_area = 2.0 * (1.0 + std::sqrt(2.0)) * 3.0 * 3.0;
    EXPECT_DOUBLE_EQ(octagon.getArea(), expected_area);
}

TEST(OctagonTest, Center) {
    Octagon octagon(3.0);
    auto center = octagon.getCenter();
    EXPECT_NEAR(center.first, 0.0, 1e-10);
    EXPECT_NEAR(center.second, 0.0, 1e-10);
}

TEST(ArrayTest, AddAndSize) {
    Array array;
    array.addFigure(std::make_unique<Pentagon>(5.0));
    array.addFigure(std::make_unique<Hexagon>(4.0));
    EXPECT_EQ(array.size(), 2);
}

TEST(ArrayTest, TotalArea) {
    Array array;
    array.addFigure(std::make_unique<Pentagon>(5.0));
    array.addFigure(std::make_unique<Hexagon>(2.0));
    double total = array.getTotalArea();
    EXPECT_GT(total, 0.0);
}

TEST(PolymorphismTest, VirtualMethods) {
    Array figures;
    
    figures.addFigure(std::make_unique<Pentagon>(5.0));
    figures.addFigure(std::make_unique<Hexagon>(4.0));
    figures.addFigure(std::make_unique<Octagon>(3.0));
    
    double totalArea = 0.0;
    for (size_t i = 0; i < figures.size(); ++i) {
        totalArea += figures.getFigure(i)->getArea();
    }
    
    EXPECT_GT(totalArea, 0.0);
}

TEST(OperatorTest, DoubleConversion) {
    Pentagon pentagon(5.0);
    double area = static_cast<double>(pentagon);
    EXPECT_GT(area, 0.0);
}
