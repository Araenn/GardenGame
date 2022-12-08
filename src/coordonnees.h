#ifndef COORDONNEES_H
#define COORDONNEES_H

#include <iostream>
using namespace std;

class Coordonnees {

    private:
        int x;
        int y;

    public:
        Coordonnees();
        Coordonnees(int x, int y);
        void set_coordonnees(int x, int y);
        int getX()const ;
        int getY()const ;
        void afficher_coordonnees() const;
        friend ostream& operator<<(ostream& c, const Coordonnees &coord);
};



#endif