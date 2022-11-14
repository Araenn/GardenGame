#ifndef PLANTES
#define PLANTES


#include <iostream>
//#include "CImg.h"
#include <time.h>
#include "coordonnees.h"

using namespace std;
//using namespace cimg_library;

class Plantes {
protected:
	int duree_pousse;
	int date_plantation;
	bool recoltable;
	int etat;
	string typePlant;
	int id;

public:
	Plantes();
	Plantes(string plantType);
	Plantes(int, string plantType);
	Plantes(int, int, string plantType);
	Plantes(int, int, bool, string plantType);
	Plantes(int, int, bool, int, string plantType);
	Plantes(const Plantes& p);

	int get_dureePousse();
	int get_datePlantation();
	bool is_recoltable();
	int get_etat();
	string get_type();
	void set_durePousse(int);
	void set_datePlantation(int);
	void set_etat_pousse();
	int get_id();

	Plantes& operator=(const Plantes& a);
	
	friend ostream& operator<<(ostream&, Plantes);
	friend bool operator!=(Plantes, Plantes);
	
};

Plantes *getDefaultPlant();

#endif
