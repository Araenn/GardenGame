#ifndef PLANTES
#define PLANTES


#include <iostream>
#include "CImg.h"
#include <time.h>

using namespace std;
using namespace cimg_library;


class Plantes {
protected:
	int duree_pousse;
	int date_plantation;
	bool recoltable;
	int etat;

public: 
	Plantes();
	Plantes(int);
	Plantes(int, int);
	Plantes(int, int, bool);
	Plantes(int, int, bool, int);
	int get_dureePousse();
	int get_datePlantation();
	bool is_recoltable();
	void set_durePousse(int);
	void set_datePlantation(int);
	int etapes_pousse();
};


#endif
