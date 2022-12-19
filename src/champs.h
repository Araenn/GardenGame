#ifndef CHAMPS_H
#define CHAMPS_H

#include <vector>

#include "plantes.h"
#include "coordonnees.h"
#include "jardiniers.h"
#include "moodType.h"
#include "./lib/CImg.h"

using namespace cimg_library;

class Champs {
protected:
	vector<vector<Plantes>> grille;
	int size_grille;

public:
	Champs(int);

	void afficher_champs() const;
	void placer_plante(const Coordonnees &coordonnees, const Plantes &plant, CImg<unsigned char> *fenetre);
	Coordonnees get_coordonnees(const Plantes &p) const;
	vector<Plantes> getAllPlantType(const Plants_types &plants_types);
	double calcul_distance(const Plantes &p, const Jardiniers &jardiniers) const;
	bool contains_plant_type(const Plants_types &plant_type);
	Plantes &plus_proche_plante(const Jardiniers &, const Plants_types&);
	void detruire_plante(const Plantes &plant, CImg<unsigned char> *fenetre);
	void action(Jardiniers &, CImg<unsigned char> *fenetre);
	Coordonnees &get_plante_coordonnees(const Plantes &plant);
	bool is_empty();
	void dessiner_champs(CImg<unsigned char> *);
	void update_champs(CImg<unsigned char> *fenetre);
	void dessiner_plantes(Plantes &plante, CImg<unsigned char> *fenetre);
};


#endif