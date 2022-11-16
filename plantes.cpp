#include "plantes.h"

static int idGrow = 0; 
Plantes defaultPlant(0, 0, false, 0, "DEFAULT");

Plantes::Plantes(int duree_pousse, int date_plantation, bool recoltable, int etat, string plantType) {
	this->duree_pousse = duree_pousse;
	this->date_plantation = date_plantation;
	this->recoltable = recoltable;
	this->etat = 0;
	this->id = idGrow++;
	this->typePlant = plantType;
}

Plantes::Plantes(int duree_pousse, int date_plantation, bool recoltable, string plantType) :
Plantes(duree_pousse, date_plantation, recoltable, 0, plantType) {}

Plantes::Plantes(int duree_pousse, int date_plantation, string plantType) :
Plantes(duree_pousse, date_plantation, true, 0, plantType) {}

Plantes::Plantes(int duree_pousse, string plantType) :
Plantes(duree_pousse, time(NULL), true, 0, plantType) {}

Plantes::Plantes(string plantType) :
Plantes(20, time(NULL), true, 0, plantType) {}

Plantes::Plantes():
Plantes("DEFAULT") {}

Plantes::Plantes(const Plantes& p) :
Plantes(p.duree_pousse, p.date_plantation, p.recoltable, p.etat, p.typePlant) {}

int Plantes::get_dureePousse() {
	return this->duree_pousse;
}

int Plantes::get_datePlantation() {
	return time(NULL) - date_plantation;
}

bool Plantes::is_recoltable() {
	if ((this->recoltable == true) || (this->etat == 5) ){
		cout << "recoltable" << endl;
	} else {
		cout << "non recoltable" << endl;
	}
	return this->recoltable;
}

void Plantes::set_durePousse(int duree_pousse) {
	this->duree_pousse = duree_pousse;
}

void Plantes::set_datePlantation(int date_plantation) {
	this->date_plantation = date_plantation;
}

int Plantes::get_etat() {
	return this->etat;
}

string Plantes::get_type() {
	return this->typePlant;
}


void Plantes::set_etat_pousse() {
	int nbrEtat = 5;
	int duree_plantation = max(this->duree_pousse, get_datePlantation());
	this->etat = (duree_plantation * (nbrEtat + 1)) / this->duree_pousse;
}
/*
void Plantes::set_etat_pousse() {
	int d = this->duree_pousse / 5;
	int etapes[5];
	int planteDepuis = get_datePlantation();
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
*/

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
	return *this;
}

Plantes *getDefaultPlant() {
	return &defaultPlant;
}