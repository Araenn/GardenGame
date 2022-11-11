#ifndef FLEURS
#define FLEURS

#include "plantes.h"

class Fleurs : public Plantes {

protected:
	string type = "Fleurs";

public:
  	Fleurs();
	Fleurs(int);
	Fleurs(int, int);
	//~Fleurs();
};

#endif
