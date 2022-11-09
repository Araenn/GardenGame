#include "coordonnees.h"

Coordonnees::Coordonnees() :
Coordonnees(0, 0){}

Coordonnees::Coordonnees(int x, int y) {
    this->x = x;
    this->y = y;
}

void Coordonnees::set_coordonnees(int *coord) {
    x = coord[0];
    y = coord[1];
}

void Coordonnees::afficher_coordonnees() {
    cout << "{" << x << ", " << y << "}" << endl;
}

ostream& operator<<(ostream& c, Coordonnees coord) {
    c << "{" << coord.x << ", " << coord.y << "}" << endl;
}