#ifndef OP2_LAB4_12_RECTANGLE_H
#define OP2_LAB4_12_RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure {
private:
    CVector2D a{};
    CVector2D b{};
public:
    Rectangle();

    Rectangle(CVector2D &, CVector2D &);

    double square() override;

    double perimeter() override;

    double mass() override;

    CVector2D position() override;

    bool operator==(const IPhysObject &) const override;

    bool operator<(const IPhysObject &) const override;

    void draw() override;

    void initFromDialog() override;

    const char *classname() override;

    unsigned int size() override;
};


#endif //OP2_LAB4_12_RECTANGLE_H
