#ifndef SEED_PLANTS_H
#define SEED_PLANTS_H

#include "crops.h"
#include "plants_types.h"
#include "varietes.h"

class Seed_plants : public Crops {
    protected:
      
    public:
        Seed_plants();
        Seed_plants(const Variete &variete);
};

#endif
