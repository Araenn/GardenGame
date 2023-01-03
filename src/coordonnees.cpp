#include "coordonnees.h"

Coordonnees::Coordonnees() :
Coordonnees(-1, -1) {}

Coordonnees::Coordonnees(int x, int y) {
    this->x = x;
    this->y = y;
}

void Coordonnees::set_coordonnees(int x, int y) {
    this->x = x;
    this->y = y;
}

int Coordonnees::getX() const {
    return this->x;
}

int Coordonnees::getY() const {
    return this->y;
}

ostream& operator<<(ostream& c, const Coordonnees &coord) {
    return c << "{" << coord.x << ", " << coord.y << "}";
}

bool Coordonnees::operator!=(const Coordonnees &c2) {
    if ((this->getX() != c2.getX()) || (this->getY() != c2.getY())) {
        return true;
    }
    return false;
}

bool Coordonnees::operator==(const Coordonnees &c2) {
    if ((this->getX() == c2.getX()) && (this->getY() == c2.getY())) {
        return true;
    }
    return false;
}