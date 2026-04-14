#include <iostream>
#include "line.h"
using namespace std;

int main() {
    Line l;
    Point p;

    cout << "Masukkan a b c x y: ";
    cin >> l.a >> l.b >> l.c >> p.x >> p.y;

    double val = gradient(&l, &p);
    cout << CheckPointPosition(val) << endl;

    return 0;
}