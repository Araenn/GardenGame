#include "fleurs.h"

Fleurs::Fleurs(int duree_p, int date_p) {
	duree_pousse = duree_p;
	date_plantation = date_p;
	etat = 0;
  recoltable = false;
}

Fleurs::Fleurs(int duree_p) :
Fleurs(duree_p, time(NULL)) {}

Fleurs::Fleurs() :
Fleurs(50, time(NULL)) {}

//Fleurs::~Fleurs() {}
