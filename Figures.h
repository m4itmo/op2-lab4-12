#ifndef OP2_LAB4_12_FIGURES_H
#define OP2_LAB4_12_FIGURES_H

#include "Trapezoid.h"
#include "Rectangle.h"
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

#endif //OP2_LAB4_12_FIGURES_H
