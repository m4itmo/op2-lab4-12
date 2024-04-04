#ifndef OP2_LAB4_12_FIGURE_H
#define OP2_LAB4_12_FIGURE_H

class IGeoFig {
public:
    virtual double square() = 0;

    virtual double perimeter() = 0;
};

class CVector2D {
public:
    double x, y;
};

class IPhysObject : public IGeoFig {
public:
    virtual double mass() = 0;

    virtual CVector2D position() = 0;

    virtual bool operator==(const IPhysObject &ob) const = 0;

    virtual bool operator<(const IPhysObject &ob) const = 0;
};

class IPrintable : public IPhysObject {
public:
    virtual void draw() = 0;
};


class IDialogInitiable : public IPrintable {
    virtual void initFromDialog() = 0;
};

class BaseCObject : public IDialogInitiable {
public:
    virtual const char *classname() = 0;

    virtual unsigned int size() = 0;
};

class Figure : public BaseCObject {};

#endif //OP2_LAB4_12_FIGURE_H
