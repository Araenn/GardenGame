#include "Seed_plants.h"

Seed_plants::Seed_plants(int duree_p, int date_p, int ngr) {
	duree_pousse = duree_p;
	date_plantation = date_p;
	etat = 0;
  recoltable = true;
  nb_grains_recoltables = ngr;
}

Seed_plants::Seed_plants(int duree_p, int date_p) :
Seed_plants(duree_p, date_p, 10) {}

Seed_plants::Seed_plants(int duree_p) :
Seed_plants(duree_p, time(NULL), 10) {}

Seed_plants::Seed_plants() :
Seed_plants(50, time(NULL), 10) {}

int Seed_plants::get_nb_grains_recoltables() {
  return nb_grains_recoltables;
}

void Seed_plants::set_nb_grains_recoltables(int ngr) {
  nb_grains_recoltables = ngr;
}

int Seed_plants::check_recolte_grains() {
  int grains;
  if (get_datePlantation() >= get_dureePousse()) {
    cout << "nbr de grains a recolter = " << nb_grains_recoltables << endl;
    return grains = nb_grains_recoltables;
  } else {
    cout << "pas encore recoltable" << endl;
    return grains = 0;
  }
}
