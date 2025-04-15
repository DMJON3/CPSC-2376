#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <cmath> 
#include <sstream> 


class Shape {
public:
    virtual ~Shape() = default; 
    virtual double getArea() const = 0; 
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double getArea() const override {
        return width * height;
    }

private:
    double width;
    double height;
};

class Circle : public Shape {
public:
    Circle(double radius) : radius(radius) {}

    double getArea() const override {
        return M_PI * radius * radius;
    }

private:
    double radius;
};

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->getArea() << std::endl;
    }
}

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;

    std::ifstream inputFile("shapes.txt");
    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string shapeType;
        ss >> shapeType;

        if (shapeType == "rectangle") {
            double width, height;
            ss >> width >> height;
            shapes.push_back(std::make_unique<Rectangle>(width, height));
        }
        else if (shapeType == "circle") {
            double radius;
            ss >> radius;
            shapes.push_back(std::make_unique<Circle>(radius));
        }
    }

    inputFile.close();

    printAllAreas(shapes);

    return 0;
}

