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
	Coordonnees coordonnees;

public:
	Plantes();
	Plantes(string plantType);
	Plantes(int, string plantType);
	Plantes(int, int, string plantType);
	Plantes(int, int, bool, string plantType);
	Plantes(int, int, bool, int, string plantType);
	Plantes(int, int, bool, int, int, string plantType);
	Plantes(const Plantes& p);
	~Plantes();
	int get_dureePousse();
	int get_datePlantation();
	bool is_recoltable();
	int get_etat();
	string get_type();
	void set_durePousse(int);
	void set_datePlantation(int);
	void set_etat_pousse();
	int get_id();
	friend ostream& operator<<(ostream&, Plantes);
	friend bool operator!=(Plantes, Plantes);
	Plantes& operator=(const Plantes& a);
	void set_coordonnees(Coordonnees);
};

Plantes *getDefaultPlant();

#endif
