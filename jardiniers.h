#ifndef JARDINIERS
#define JARDINIERS

#include <iostream>
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
  int get_position();
  void set_position(int[2]);
  int choix_action();
  int get_dateMoodChanged();
  void mood_change();
};

#endif
