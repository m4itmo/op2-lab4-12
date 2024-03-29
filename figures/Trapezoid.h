#ifndef OP2_LAB4_12_PARALLELOGRAM_H
#define OP2_LAB4_12_PARALLELOGRAM_H

#include "../Figure.h"

class Trapezoid : public Figure {
private:
    CVector2D a{};
    CVector2D b{};
    CVector2D c{};
    CVector2D d{};
public:
    Trapezoid();

    Trapezoid(CVector2D &, CVector2D &, CVector2D &, CVector2D &);

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


#endif //OP2_LAB4_12_PARALLELOGRAM_H
