#include <iostream>
#include "Figures.h"

using namespace std;

int main() {
    Figures figs;

    int choice;
    while (true) {
        cout << "0 - exit" << endl;
        cout << "1 - add" << endl;
        cout << "2 - show all" << endl;
        cout << "3 - total area" << endl;
        cout << "4 - total perimeter" << endl;
        cout << "5 - center of mass" << endl;
        cout << "6 - memory" << endl << "> ";

        cin >> choice;

        if (choice == 0)
            break;
        else if (choice == 1)
            figs.add();
        else if (choice == 2)
            figs.display();
        else if (choice == 3)
            cout << "Total area : " << figs.totalSquare() << endl;
        else if (choice == 4)
            cout << "Total perimeter : " << figs.totalPerimeter() << endl;
        else if (choice == 5)
            cout << "Center of mass coordinates : " << figs.centerPosition().x << " " << figs.centerPosition().y << endl;
        else if (choice == 6)
            cout << "Total figures occupy : " << figs.totalMemory() << " bytes of memory" << endl;
        else
            cout << "Error: Incorrect Selection!" << endl << "Select from 0 to 6" << endl;
    }


    cout << "Exit" << endl;

    return 0;
}