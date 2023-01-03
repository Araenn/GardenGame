#include "plantes.h"

static int idGrow = 0; 
const Plantes Plantes::DEFAULT = Plantes(Plants_types::UNKNOWN, Variete::UNKNOWN);

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

void Plantes::set_variete(const Variete &v) {
	this->variete = v;
}

int Plantes::get_id() const {
	return this->id;
}

/*
update the plant stage according its time to grow
*/
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

/*
draw plants on the screen according their species and stages
*/
void Plantes::dessiner_plantes(CImg<unsigned char> *fenetre, int x, int y) {
    CImg<unsigned char> img_plante = choix_img_plantes();
	CImg<float> mask = make_transparent(img_plante);

	fenetre->draw_image(x, y, 0, 0, img_plante, mask);
}

/*
determine the right picture for the plant according its species and stage
*/
CImg<unsigned char> Plantes::choix_img_plantes() const {
	loadImagesVariete();
	return this->get_variete().getImage(get_etat());
}

/*
get the coord of plants pictures on the spritesheet
*/
Coordonnees get_spritesheet_plantes_coord(const Variete variete, int etat) {
	int line = variete.get_posY() * 6 * PLANT_IMAGE_SIZE[1] + PLANT_IMAGE_SIZE[1] * (5 - etat);
	int col = variete.get_posX() * PLANT_IMAGE_SIZE[0];
	Coordonnees posVariete(line, col);
	return posVariete;
}
