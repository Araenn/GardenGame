#ifndef CHAMPS
#define CHAMPS

#include "plantes.h"
#include <math.h>
#include "jardiniers.h"
#include "coordonnees.h"

class Champs {
protected:
	Plantes*** grille;
	int size_grille;

public:
	Champs(int);
	void afficher_champs();
	void placer_plante(Coordonnees, Plantes*);
	Coordonnees get_coordonnees(Plantes *p);
	double calcul_distance(Plantes *p, Jardiniers jardiniers);
	Plantes *plus_proche_plante(Jardiniers*, string);
	void detruire_fleurs(Fleurs *);
	void detruire_legumes(Legumes *);
	void detruire_seedplants(Seed_plants *);
	void action(Jardiniers*);
	Plantes *chercher_plante(string);
	Coordonnees *get_plante_coordonnees(Plantes *);
};


#endif