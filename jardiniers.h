#ifndef JARDINIERS
#define JARDINIERS

#include <iostream>
#include <unistd.h>
#include "seed_plants.h"
#include "legumes.h"
//#include "CImg.h"

using namespace std;

class Jardiniers {
protected:
  string name;
  int mood;
  int position[2];
  int date_mood_changed;

public:
  Jardiniers();
  Jardiniers(string);
  Jardiniers(string, int);
  Jardiniers(string, int, int[2]);
  string get_name();
  void set_name(string);
  int get_mood();
  string get_mood_name();
  void set_mood(int);
  int* get_position();
  void set_position(int[2]);
  void action();
  int get_dateMoodChanged();
  void mood_change();
	void recolter_grains(Seed_plants);
	void manger_legumes(Legumes);
  int calcul_distance(Plantes);
};

#endif
