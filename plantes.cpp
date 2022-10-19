#include "plantes.h"

Plantes::Plantes(int duree_p, int date_p, bool rec, int et) {
	duree_pousse = duree_p;
	et = 0;
	date_plantation = date_p;
	recoltable = rec;
	etat = et;
}

Plantes::Plantes(int duree_p, int date_p, bool rec) :
Plantes(duree_p, date_p, rec, 0) {}

Plantes::Plantes(int duree_p, int date_p) :
Plantes(duree_p, date_p, true, 0) {}

Plantes::Plantes(int duree_p) : 
Plantes(duree_p, time(NULL), true, 0) {}

Plantes::Plantes() :
Plantes(20, time(NULL), true, 0) {}


int Plantes::get_dureePousse() {
	return duree_pousse;
}

int Plantes::get_datePlantation() {
	return date_plantation;
}

bool Plantes::is_recoltable() {
	if (recoltable == true) {
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

int Plantes::etapes_pousse() {
	int d = duree_pousse/5;
	int etapes[5];
	int planteDepuis = time(NULL) - date_plantation;
	for (int i = 0; i <= 4; i++) {
		etapes[i] = d*i;
	}
	if ((0 <= planteDepuis) && (planteDepuis <= etapes[0])) {
		return etat = 0;
	} else if ((etapes[0] < planteDepuis) && (planteDepuis <= etapes[1])) {
		return etat = 1;
	} else if ((etapes[1] < planteDepuis) && (planteDepuis <= etapes[2])) {
		return etat = 2;
	} else if ((etapes[2] < planteDepuis) && (planteDepuis <= etapes[3])) {
		return etat = 3;
	} else if ((etapes[3] < planteDepuis) && (planteDepuis <= etapes[4])) {
		return etat = 4;
	} else if (planteDepuis >= etapes[4]) {
		return etat = 4;
	} else {
		return -1;
	}
	
}


