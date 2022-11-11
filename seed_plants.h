#ifndef SEED_PLANTS
#define SEED_PLANTS

#include "plantes.h"

class Seed_plants : public Plantes {
protected:
  int nb_grains_recoltables;
  string type = "Seed_plants";
  
public:
  Seed_plants();
	Seed_plants(int);
	Seed_plants(int, int);
	Seed_plants(int, int, int);
  int get_nb_grains_recoltables();
  void set_nb_grains_recoltables(int);
  int check_recolte_grains();
};

#endif
