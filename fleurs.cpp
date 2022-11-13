#include "fleurs.h"

Fleurs::Fleurs(int duree_p, int date_p):
Plantes(duree_p, date_p, 0, false, "Fleurs") {}

Fleurs::Fleurs(int duree_p) :
Fleurs(duree_p, time(NULL)) {}

Fleurs::Fleurs() :
Fleurs(50, time(NULL)) {}