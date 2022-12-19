#ifndef LEGUMES_H
#define LEGUMES_H

#include "crops.h"
#include "plants_types.h"
#include "varietes.h"

class Legumes : public Crops {

    public:
        Legumes();
        Legumes(const Variete &variete);
      
        bool is_eatable() const;
};

#endif
