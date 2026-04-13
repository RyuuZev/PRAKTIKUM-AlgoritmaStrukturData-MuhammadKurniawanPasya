#include <iostream>
using namespace std;

string CheckPointPosition(int a, int b, int c, int xP, int yP) {
    int value = a * xP + b * yP + c;

    if (value == 0) {
        return "On Line";
    } else if (value > 0) {
        return "Left";
    } else {
        return "Right";
    }
}

int main() {
    int a, b, c, xP, yP;
    cin >> a >> b >> c >> xP >> yP;

    cout << CheckPointPosition(a, b, c, xP, yP);

    return 0;
}