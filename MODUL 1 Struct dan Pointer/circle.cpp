#include "circle.h"
#include <cmath>

static double savedRadius;

double distance(const Circle * c,const Point * p) {
    savedRadius = c->radius;

    return std::sqrt(
        (p->x - c->centre.x) * (p->x - c->centre.x) +
        (p->y - c->centre.y) * (p->y - c->centre.y)
    );
}

std::string CheckPointInCircle(double d) {
    if (std::abs(d - savedRadius) < EPSILON)
        return "On Circle";
    else if (d < savedRadius)
        return "Inside";
    else
        return "Outside";
}