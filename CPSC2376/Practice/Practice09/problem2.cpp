#include <iostream>

struct Point {
    float x;
    float y;
};

Point calcMidpoint(const Point* p1, const Point* p2) {
    
    Point midpoint;
    midpoint.x = (p1->x + p2->x) / 2.0f;
    midpoint.y = (p1->y + p2->y) / 2.0f;
    return midpoint;
}

int main() {
    
    Point a{ 1.0f, 2.0f };
    Point b{ 5.0f, 6.0f };

    Point mid = calcMidpoint(&a, &b);

    std::cout << "Midpoint is at (" << mid.x << ", " << mid.y << ")" << std::endl;

    return 0;
}
