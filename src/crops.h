#ifndef CROPS_H
#define CROPS_H

#include "plantes.h"
#include "varietes.h"

class Crops : public Plantes {

    public:
        Crops(const Plants_types &plants_types, const Variete &variete);

        bool isRecoltable() const;

};

#endif