#include "seed_plants.h"

Seed_plants::Seed_plants(int nb_grains_recoltables, const Variete &variete):
Crops(Plants_types::SEED_PLANTS, variete) {
  this->nb_grains_recoltables = nb_grains_recoltables;
}

Seed_plants::Seed_plants() :
Seed_plants(-1, Variete::UNKNOWN) {}

int Seed_plants::get_nb_grains_recoltables() const {
  return nb_grains_recoltables;
}

int Seed_plants::check_recolte_grains() const {
  if (isRecoltable()) {
    return this->nb_grains_recoltables;
  } else {
    // La plante n'est pas encore arrivé à maturié
    return -1;
  }
}
