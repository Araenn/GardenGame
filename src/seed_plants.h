#ifndef SEED_PLANTS_H
#define SEED_PLANTS_H

#include "crops.h"
#include "plants_types.h"
#include "varietes.h"

class Seed_plants : public Crops {
    protected:
        int nb_grains_recoltables;
      
    public:
        Seed_plants();
        Seed_plants(int, const Variete &variete);
        
        int get_nb_grains_recoltables() const;
        int check_recolte_grains() const;
};

#endif
