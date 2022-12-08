#ifndef FLEURS_H
#define FLEURS_H

#include "plantes.h"
#include "plants_types.h"
#include "varietes.h"

class Fleurs : public Plantes {

	public:
		Fleurs(const Variete &variete);

};

#endif
