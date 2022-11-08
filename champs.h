#ifndef CHAMPS
#define CHAMPS

#include "plantes.h"
#include <vector>
#include <math.h>
#include "jardiniers.h"

class Champs {
protected:
	Plantes** grille;
	int size_grille;

public:
	Champs(int);
	void afficher_champs();
	void placer_plante(int, int, Plantes);
	int* get_coordonnees(Plantes p);
	double calcul_distance(Plantes p, Jardiniers jardiniers);

};


#endif