#include "seed_plants.h"

Seed_plants::Seed_plants(const Variete &variete):
Crops(Plants_types::SEED_PLANTS, variete) {}

Seed_plants::Seed_plants() :
Seed_plants(Variete::UNKNOWN) {
  cout << "nb grains quand initialise avec rien" << endl;
}
