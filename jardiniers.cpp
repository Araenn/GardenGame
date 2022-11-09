#include "jardiniers.h"

Jardiniers::Jardiniers(string n, int m, Coordonnees p) {
  name = n;
  mood = m;
  position = p;
  date_mood_changed = time(NULL);
}

Jardiniers::Jardiniers(string n, int m) {
  name = n;
  mood = m;
  position = {0, 0};
  date_mood_changed = time(NULL);
}

Jardiniers::Jardiniers(string n) {
  name = n;
  mood = 1;
  position = {0, 0};
  date_mood_changed = time(NULL);
}

Jardiniers::Jardiniers() {
  name = "Jardinier 1";
  mood = 1;
  position = {0, 0};
  date_mood_changed = time(NULL);
}

string Jardiniers::get_name() {
  return name;
}

void Jardiniers::set_name(string n) {
  name = n;
}

int Jardiniers::get_mood() {
  return mood;
}

string Jardiniers::get_mood_name() {
  if (get_mood() == 1) {
    return "Content";
  } else if (get_mood() == 2) {
    return "Normal";
  } else {
    return "Grincheux";
  }
}

void Jardiniers::set_mood(int m) {
  mood = m;
  date_mood_changed = time(NULL);
}

Coordonnees Jardiniers::get_position() {
  return position;
}

void Jardiniers::set_position(Coordonnees p) {
  position = p;
}

int Jardiniers::get_dateMoodChanged() {
  return time(NULL) - date_mood_changed;
}

void Jardiniers::mood_change() {
  int d = get_dateMoodChanged(); //date dernier changement de mood
	cout << d << endl;
  int seuil = 30; //30s par mood sans manger

  if ((d >= seuil) && (get_mood() != 3) ){
    set_mood(get_mood() + 1);
  }
}

void Jardiniers::recolter_grains(Seed_plants p) {
	int grains;
	grains = p.check_recolte_grains();
}

void Jardiniers::manger_legumes(Legumes l) {
	if (get_mood() > 1) {
		set_mood(get_mood() - 1);
	} else {
		set_mood(get_mood());
	}
}

void Jardiniers::action() {
  int action;
	Seed_plants p;
  if (get_mood_name() == "Content") {
     recolter_grains(p); //recolte grains
  } else if (get_mood_name() == "Normal") {
     action = 1; //grains ou legums, le plus proche
  } else {
     action = 2; //legume si proche, sinon fleur detruite
  }
}