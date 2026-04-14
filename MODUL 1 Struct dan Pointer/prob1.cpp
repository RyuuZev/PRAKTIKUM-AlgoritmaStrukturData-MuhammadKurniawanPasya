#include <iostream>
#include "line.h"
#include "point.h"

int main() {
    Line l;
    Point p;

    while (std::cin >> l.a >> l.b >> l.c >> p.x >> p.y) {
        double val = gradient(&l, &p);
        std::cout << CheckPointPosition(val) << std::endl;
    }

    return 0;
}