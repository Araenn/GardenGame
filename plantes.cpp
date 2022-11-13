#include "plantes.h"

static int idGrow = 0; 
Plantes defaultPlant(0, 0, false, 0, "DEFAULT");

Plantes::Plantes(int duree_p, int date_p, bool rec, int et, string plantType) {
	duree_pousse = duree_p;
	et = 0;
	date_plantation = date_p;
	recoltable = rec;
	etat = et;
	id = idGrow++;
	this->typePlant = plantType;
}

Plantes::Plantes(int duree_p, int date_p, bool rec, int et, int idd, string plantType) {
	duree_pousse = duree_p;
	date_plantation = date_p;
	recoltable = rec;
	etat = et;
	id = idd; 
	this->typePlant = plantType;
}

Plantes::Plantes(int duree_p, int date_p, bool rec, string plantType) :
Plantes(duree_p, date_p, rec, 0, plantType) {}

Plantes::Plantes(int duree_p, int date_p, string plantType) :
Plantes(duree_p, date_p, true, 0, plantType) {}

Plantes::Plantes(int duree_p, string plantType) :
Plantes(duree_p, time(NULL), true, 0, plantType) {}

Plantes::Plantes(string plantType) :
Plantes(20, time(NULL), true, 0, plantType) {}

Plantes::Plantes():
Plantes("DEFAULT") {}

Plantes::Plantes(const Plantes& p) :
Plantes(p.duree_pousse, p.date_plantation, p.recoltable, p.etat, p.id, p.typePlant) {}

Plantes::~Plantes() {}

int Plantes::get_dureePousse() {
	return duree_pousse;
}

int Plantes::get_datePlantation() {
	return time(NULL) - date_plantation;
}

bool Plantes::is_recoltable() {
	if (this->recoltable == true) {
		cout << "recoltable" << endl;
	} else {
		cout << "non recoltable" << endl;
	}
	return recoltable;
}

void Plantes::set_durePousse(int duree_p) {
	duree_pousse = duree_p;
}

void Plantes::set_datePlantation(int date_p) {
	date_plantation = date_p;
}

int Plantes::get_etat() {
	return etat;
}

string Plantes::get_type() {
	return this->typePlant;
}

void Plantes::set_etat_pousse() {
	int d = duree_pousse/5;
	int etapes[5];
	int planteDepuis = time(NULL) - date_plantation;
	for (int i = 0; i <= 4; i++) {
		etapes[i] = d*i;
	}

	if (planteDepuis == duree_pousse) {
			cout << "plant fully grown" << endl;
	}

	if ((0 <= planteDepuis) && (planteDepuis <= etapes[0])) {
		etat = 0;
	} else if ((etapes[0] < planteDepuis) && (planteDepuis <= etapes[1])) {
		etat = 1;
	} else if ((etapes[1] < planteDepuis) && (planteDepuis <= etapes[2])) {
		etat = 2;
	} else if ((etapes[2] < planteDepuis) && (planteDepuis <= etapes[3])) {
		etat = 3;
	} else if ((etapes[3] < planteDepuis) && (planteDepuis <= etapes[4])) {
		etat = 4;
	} else if (planteDepuis >= etapes[4]) {
		etat = 4;
	} else {
		etat = 0;
	}
}

ostream& operator<<(ostream& c, Plantes v) {
	c << "type = " << v.get_type() << ".";
	return c;
}

int Plantes::get_id() {
	return this->id;
}

bool operator!=(Plantes a, Plantes b) {
	if ( (a.get_datePlantation() != b.get_datePlantation()) || (a.get_dureePousse() != b.get_dureePousse()) || (a.get_etat() != b.get_etat())) {
		return true;
	} else {
		return false;
	}
}

Plantes& Plantes::operator=(const Plantes& a) {
	this->duree_pousse = a.duree_pousse;
	this->date_plantation = a.date_plantation;
	this->recoltable = a.recoltable;
	this->etat = a.etat;
	this->typePlant = a.typePlant;
	this->id = a.id;
	this->coordonnees = a.coordonnees;
	return *this;
}

void Plantes::set_coordonnees(Coordonnees coord) {
	this->coordonnees = coord;
}

Plantes *getDefaultPlant() {
	return &defaultPlant;
}