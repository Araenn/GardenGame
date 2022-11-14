#include "seed_plants.h"

Seed_plants::Seed_plants(int duree_pousse, int date_plantation, int nb_grains_recoltables):
Plantes(duree_pousse, date_plantation, 0, true, "Seed_plants") {
  this->nb_grains_recoltables = nb_grains_recoltables;
}

Seed_plants::Seed_plants(int duree_pousse, int date_plantation) :
Seed_plants(duree_pousse, date_plantation, 10) {}

Seed_plants::Seed_plants(int duree_pousse) :
Seed_plants(duree_pousse, time(NULL), 10) {}

Seed_plants::Seed_plants() :
Seed_plants(50, time(NULL), 10) {}

int Seed_plants::get_nb_grains_recoltables() {
  return nb_grains_recoltables;
}

void Seed_plants::set_nb_grains_recoltables(int nb_grains_recoltables) {
  this->nb_grains_recoltables = nb_grains_recoltables;
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
