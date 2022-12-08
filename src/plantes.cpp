#include "plantes.h"

static int idGrow = 0; 
const Plantes Plantes::DEFAULT = Plantes(Plants_types::UNKNOWN, Variete::UNKNOWN);
static vector<vector<CImg<unsigned char>>> plants_imgs; // [state][variete]
static bool plants_imgs_loaded = false;

Plantes::Plantes(const Plants_types &plants_types, const Variete &variete) {
	this->date_plantation = time(NULL);
	this->etat = 0;
	this->id = idGrow++;
	this->plants_types = plants_types;
	this->variete = variete;
}

Plantes::Plantes(const Plantes& plant) {
	this->date_plantation = plant.date_plantation;
	this->etat = plant.etat;
	this->id = plant.id;
	this->plants_types = plant.plants_types;
	this->variete = plant.variete;
}

int Plantes::get_temps_plantation() const {
	return time(NULL) - date_plantation;
}

int Plantes::get_etat() const {
	return this->etat;
}

const Plants_types &Plantes::get_type() const {
	return this->plants_types;
}

const Variete &Plantes::get_variete() const {
	return this->variete;
}

int Plantes::get_id() const {
	return this->id;
}

void Plantes::update_plant() {
	int nbrEtat = 5;
	int duree_plantation = min(this->get_variete().get_duree_pousse(), get_temps_plantation());
	this->etat = (duree_plantation * nbrEtat) / this->get_variete().get_duree_pousse();
}

bool Plantes::operator!=(const Plantes &b) const {
	return b.get_type() != this->get_type();
}

Plantes& Plantes::operator=(const Plantes& a) {
	this->variete = a.variete;
	this->date_plantation = a.date_plantation;
	this->etat = a.etat;
	this->plants_types = a.plants_types;
	this->id = a.id;
	return *this;
}

ostream& operator<<(ostream& c, const Plantes &v) {
	return c << "{id:" << v.get_id() << ",type: " << v.get_type() << "}";
}

CImg<unsigned char> Plantes::choix_img_plantes() const {
	CImg<unsigned char> img_plante = this->get_variete().getImage(get_etat());
	return img_plante;
}
