#include "fleurs.h"

Fleurs::Fleurs(int duree_pousse, int date_plantation):
Plantes(duree_pousse, date_plantation, 0, false, "Fleurs") {}

Fleurs::Fleurs(int duree_pousse) :
Fleurs(duree_pousse, time(NULL)) {}

Fleurs::Fleurs() :
Fleurs(50, time(NULL)) {}