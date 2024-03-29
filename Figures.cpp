#include "Figures.h"

#include "figures/Trapezoid.h"
#include "figures/Rectangle.h"
#include "Figures.h"

#include "iostream"

using namespace std;

void Figures::add() {
    int choice;
    cout << "Select the figure\n1 - Trapezoid\n2 - Rectangle" << endl << "> ";
    cin >> choice;

    if (choice == 1) {
        auto *temp = new Trapezoid;
        temp->initFromDialog();
        allFigures.insert(temp);
    } else if (choice == 2) {
        auto *temp = new Rectangle;
        temp->initFromDialog();
        allFigures.insert(temp);
    } else {
        cout << "Error: Wrong Option!" << endl;
        return;
    }

    cout << "Success" << endl;
}

void Figures::display() {
    for (auto i: allFigures)
        i->draw();
}

double Figures::totalSquare() {
    double counter = 0;
    for (auto i: allFigures)
        counter += i->square();

    return counter;
}

double Figures::totalPerimeter() {
    double counter = 0;
    for (auto i: allFigures)
        counter += i->perimeter();

    return counter;
}

CVector2D Figures::centerPosition() {
    CVector2D ans{0, 0};
    double curX = 0;
    double curY = 0;
    double m = 0;

    for (auto i: allFigures) {
        curX += i->position().x * i->mass();
        curY += i->position().y * i->mass();
        m += i->mass();
    }

    ans.x = curX / m;
    ans.y = curY / m;

    return ans;
}

unsigned int Figures::totalMemory() {
    unsigned int ans = 0;

    for (auto i: allFigures)
        ans += i->size();

    return ans;
}
