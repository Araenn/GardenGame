#ifndef COORDONNEES
#define COORDONNEES

#include <iostream>
using namespace std;

class Coordonnees {
    public:
        int x;
        int y;
        Coordonnees();
        Coordonnees(int x, int y);
        void set_coordonnees(int *);
        void afficher_coordonnees();
        friend ostream& operator<<(ostream& c, Coordonnees coord);
};



#endif