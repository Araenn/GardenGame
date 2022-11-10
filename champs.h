#ifndef CHAMPS
#define CHAMPS

#include "plantes.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include "jardiniers.h"
#include "coordonnees.h"

class Champs {
protected:
	Plantes** grille;
	int size_grille;

public:
	Champs(int);
	void afficher_champs();
	void placer_plante(int, int, Plantes);
	Coordonnees get_coordonnees(Plantes p);
	double calcul_distance(Plantes p, Jardiniers jardiniers);
	Plantes& plus_proche_plante(Jardiniers);
};


#endif