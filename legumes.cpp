#include "legumes.h"

Legumes::Legumes(int duree_pousse, int date_plantation):
Plantes(duree_pousse, date_plantation, 0, true, "Legumes") {}

Legumes::Legumes(int duree_pousse) :
Legumes(duree_pousse, time(NULL)) {}

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