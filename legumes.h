#ifndef LEGUMES
#define LEGUMES

#include "plantes.h"


class Legumes : public Plantes {

public:
  Legumes();
	Legumes(int);
	Legumes(int, int);
  bool is_eatable();
};

#endif
