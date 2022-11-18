#ifndef JARDINIERS
#define JARDINIERS

#include <iostream>
#include <unistd.h>
#include "seed_plants.h"
#include "legumes.h"
#include "coordonnees.h"
#include "fleurs.h"
#include "CImg.h"

using namespace std;
using namespace cimg_library;

class Jardiniers {
protected:
  string name;
  int mood;
  Coordonnees position;
  int date_mood_changed;

public:
  Jardiniers();
  Jardiniers(string);
  Jardiniers(string, int);
  Jardiniers(string, int, Coordonnees);
  string get_name();
  void set_name(string);
  int get_mood();
  string get_mood_name();
  void set_mood(int);
  Coordonnees get_position();
  void set_position(Coordonnees);
  int get_dateMoodChanged();
  void mood_change();
	int recolter_grains(Seed_plants*);
	void manger_legumes(Legumes*);
  CImg<unsigned char> dessiner_jardiniers();
};

#endif
