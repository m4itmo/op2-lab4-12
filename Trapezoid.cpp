#include "Trapezoid.h"

#include <iostream>
#include <cmath>

using namespace std;

Trapezoid::Trapezoid() {
    a = CVector2D{0, 0};
    b = CVector2D{0, 0};
    c = CVector2D{0, 0};
    d = CVector2D{0, 0};
}

Trapezoid::Trapezoid(CVector2D &v1, CVector2D &v2, CVector2D &v3, CVector2D &v4) {
    a = v1;
    b = v2;
    c = v3;
    d = v4;
}

double Trapezoid::square() {
    return a.x * b.y - a.y * b.x;
}

double Trapezoid::perimeter() {
    return 2 * (sqrt(pow(a.x, 2) + pow(a.y, 2)) + sqrt(pow(b.x, 2) + pow(b.y, 2)));
}

double Trapezoid::mass() {
    return square();
}

CVector2D Trapezoid::position() {
    auto *vec = new CVector2D;
    vec->x = (a.x + c.x) / 2;
    vec->y = (a.y + c.y) / 2;

    return *vec;
}

bool Trapezoid::operator==(const IPhysObject &other) const {
    double first = const_cast<Trapezoid &>(*this).mass();
    double second = const_cast<Trapezoid &>(dynamic_cast<const Trapezoid &>(other)).mass();

    return first == second;
}

bool Trapezoid::operator<(const IPhysObject &other) const {
    double first = const_cast<Trapezoid &>(*this).mass();
    double second = const_cast<Trapezoid &>(dynamic_cast<const Trapezoid &>(other)).mass();

    return first < second;
}

void Trapezoid::draw() {
    cout << "Trapezoid: " << classname() << endl;
    cout << "Coordinates of parallelogram vectors:" << endl;
    cout << "Vector 1: " << a.x << " " << a.y << endl;
    cout << "Vector 2: " << b.x << " " << b.y << endl;
    cout << "Vector 3: " << c.x << " " << c.y << endl;
    cout << "Vector 4: " << d.x << " " << d.y << endl;
    cout << endl;
}

void Trapezoid::initFromDialog() {
    double sx, sy, ax, ay, bx, by, cx, cy, dx, dy;
    cout << "Enter the coordinates of the vectors for the parallelogram" << endl;
    cout << "Coordinates of the offset vector for the starting point:" << endl << "> ";
    cin >> sx >> sy;
    cout << "Part 1 vector coordinates:" << endl << "> ";
    cin >> ax >> ay;
    cout << "Part 2 vector coordinates:" << endl << "> ";
    cin >> bx >> by;
    cout << "Part 3 vector coordinates:" << endl << "> ";
    cin >> cx >> cy;
    cout << "Part 4 vector coordinates:" << endl << "> ";
    cin >> dx >> dy;
    cout << endl;

    a = CVector2D{ax, ay};
    b = CVector2D{bx, by};
    c = CVector2D{cx, cy};
    d = CVector2D{dx, dy};
}

const char *Trapezoid::classname() {
    return typeid(*this).name();
}

unsigned int Trapezoid::size() {
    return sizeof(*this);
}
