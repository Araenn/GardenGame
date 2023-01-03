#ifndef PLANTES_H
#define PLANTES_H

#include <iostream>
#include <time.h>
#include "coordonnees.h"
#include "plants_types.h"
#include "varietes.h"
#include "CImgUtils.h"

constexpr int PLANT_IMAGE_SIZE[] = {16, 16};


using namespace std;

Coordonnees get_spritesheet_plantes_coord(const Variete variete, int etat);

class Plantes {

	protected:
		int date_plantation;
		int etat;
		Plants_types plants_types;
		int id;
		Variete variete;

	public:
		static const Plantes DEFAULT;

		Plantes(const Plants_types &plants_types, const Variete &variete);
		Plantes(const Plantes& plant);

		int get_temps_plantation() const;
		int get_etat() const;
		int get_id() const;
		void set_variete(const Variete &v);
		const Variete &get_variete() const;
		const Plants_types &get_type() const;
		void update_plant();

		Plantes& operator=(const Plantes& a);
		bool operator!=(const Plantes &) const ;
		
		friend ostream& operator<<(ostream&, const Plantes &v);

		CImg<unsigned char> choix_img_plantes() const;

		
		void dessiner_plantes(CImg<unsigned char> *fenetre, int x, int y);
		
};

#endif
