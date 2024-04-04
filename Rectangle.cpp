#include "Rectangle.h"

#include <iostream>
#include <cmath>

using namespace std;

Rectangle::Rectangle() {
    a = CVector2D{0, 0};
    b = CVector2D{0, 0};
}

Rectangle::Rectangle(CVector2D &one, CVector2D &two) {
    a = one;
    b = two;
}

double Rectangle::square() {
    return a.x * b.y - a.y * b.x;
}

double Rectangle::perimeter() {
    return 2 * (sqrt(pow(a.x, 2) + pow(a.y, 2)) + sqrt(pow(b.x, 2) + pow(b.y, 2)));
}

double Rectangle::mass() {
    return square();
}

CVector2D Rectangle::position() {
    auto *vec = new CVector2D;
    vec->x = (a.x + b.x) / 2;
    vec->y = (a.y + b.y) / 2;

    return *vec;
}

bool Rectangle::operator==(const IPhysObject &other) const {
    double first = const_cast<Rectangle &>(*this).mass();
    double second = const_cast<Rectangle &>(dynamic_cast<const Rectangle &>(other)).mass();

    return first == second;
}

bool Rectangle::operator<(const IPhysObject &other) const {
    double first = const_cast<Rectangle &>(*this).mass();
    double second = const_cast<Rectangle &>(dynamic_cast<const Rectangle &>(other)).mass();

    return first < second;
}

void Rectangle::draw() {
    cout << "Rectangle: " << classname() << endl;
    cout << "Coordinates of parallelogram vectors:" << endl;
    cout << "Vector 1: " << a.x << " " << a.y << endl;
    cout << "Vector 2: " << b.x << " " << b.y << endl;
    cout << endl;
}

void Rectangle::initFromDialog() {
    double sx, sy, ax, ay, bx, by;
    cout << "Enter the coordinates of the vectors for the parallelogram" << endl;
    cout << "Coordinates of the offset vector for the starting point:" << endl << "> ";
    cin >> sx >> sy;
    cout << "Part 1 vector coordinates:" << endl << "> ";
    cin >> ax >> ay;
    cout << "Part 2 vector coordinates:" << endl << "> ";
    cin >> bx >> by;
    cout << endl;

    a = CVector2D{ax, ay};
    b = CVector2D{bx, by};
}

const char *Rectangle::classname() {
    return typeid(*this).name();
}

unsigned int Rectangle::size() {
    return sizeof(*this);
}
