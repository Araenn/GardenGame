#include "seed_plants.h"

Seed_plants::Seed_plants(int duree_p, int date_p, int ngr):
Plantes(duree_p, date_p, 0, true, ngr, "Seed_plants") {}

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
  if (get_datePlantation() >= get_dureePousse()) {
    cout << "nbr de grains a recolter = " << this->nb_grains_recoltables << endl;
    this->recoltable = true;
    return this->nb_grains_recoltables;
  } else {
    cout << "pas encore recoltable" << endl;
    this->recoltable = false;
    return 0;
  }
}
