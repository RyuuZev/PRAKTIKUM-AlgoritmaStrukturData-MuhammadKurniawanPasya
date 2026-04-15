#include <iostream>
#include "circle.h"
#include "point.h"

int main() {
    Circle c;
    Point p;

    while (std::cin >> c.centre.x >> c.centre.y >> c.radius >> p.x >> p.y) {
        double d = distance(&c, &p);
        std::cout << CheckPointInCircle(d) << std::endl;
    }

    return 0;
}