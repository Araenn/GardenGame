#ifndef LEGUMES
#define LEGUMES

#include "plantes.h"


class Legumes : public Plantes {

protected:
  string type = "Legumes";
  
public:
  Legumes();
	Legumes(int);
	Legumes(int, int);
  bool is_eatable();
};

#endif
