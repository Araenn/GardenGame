#ifndef PLANTES
#define PLANTES


#include <iostream>
//#include "CImg.h"
#include <time.h>

using namespace std;
//using namespace cimg_library;

class Plantes {
protected:
	int duree_pousse;
	int date_plantation;
	bool recoltable;
	int etat;

	int id;

public:
	Plantes();
	Plantes(int);
	Plantes(int, int);
	Plantes(int, int, bool);
	Plantes(int, int, bool, int);
	int get_dureePousse();
	int get_datePlantation();
	bool is_recoltable();
	int get_etat();
	void set_durePousse(int);
	void set_datePlantation(int);
	void set_etat_pousse();
	int get_id();
	friend ostream& operator<<(ostream&, Plantes);
};


#endif
