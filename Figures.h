#ifndef OP2_LAB4_17_FIGURESSTORAGE_H
#define OP2_LAB4_17_FIGURESSTORAGE_H

#include "figures/Trapezoid.h"
#include "figures/Rectangle.h"
#include "Figure.h"

#include <set>

using namespace std;

class Figures {
private:
    set<Figure *> allFigures;
public:
    void add();
    void display();
    double totalSquare();
    double totalPerimeter();
    CVector2D centerPosition();
    unsigned int totalMemory();
};

#endif //OP2_LAB4_17_FIGURESSTORAGE_H
