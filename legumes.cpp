#include "legumes.h"

Legumes::Legumes(int duree_p, int date_p):
Plantes(duree_p, date_p, 0, true) {}

Legumes::Legumes(int duree_p) :
Legumes(duree_p, time(NULL)) {}

Legumes::Legumes() :
Legumes(30, time(NULL)) {}

bool Legumes::is_eatable() {
	if (get_datePlantation() >= get_dureePousse()) {
		cout << "legume arrive a maturite" << endl;
		return true;
	} else {
		cout << "pas encore mur" << endl;
		return false;
	}
}
