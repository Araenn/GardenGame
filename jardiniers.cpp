#include "jardiniers.h"

Jardiniers::Jardiniers(string n, int m, Coordonnees p, int date) {
  name = n;
  mood = m;
  position = p;
  date_mood_changed = time(NULL);
}

Jardiniers::Jardiniers(string n, int m, int date) : 
Jardiniers(n, m, {0, 0}, time(NULL)) {}

Jardiniers::Jardiniers(string n, int date) :
Jardiniers(n, 1, {0, 0}, time(NULL)) {}

Jardiniers::Jardiniers(int date) :
Jardiniers("Jardinier 1", 1, {0, 0}, time(NULL)) {}

string Jardiniers::get_name() {
  return this->name;
}

void Jardiniers::set_name(string n) {
  this->name = n;
}

int Jardiniers::get_mood() {
  return this->mood;
}

string Jardiniers::get_mood_name() {
  switch (get_mood()) {
    case 1: return "Content";
    case 2: return "Normal";
    case 3: return "Grincheux";
    default: return "Mood inconnu";
  }
}

void Jardiniers::set_mood(int m) {
  this->mood = m;
  this->date_mood_changed = time(NULL);
}

Coordonnees Jardiniers::get_position() {
  return this->position;
}

void Jardiniers::set_position(Coordonnees p) {
  this->position = p;
}

int Jardiniers::get_dateMoodChanged() {
  return time(NULL) - this->date_mood_changed;
}

void Jardiniers::mood_change() {
  int d = get_dateMoodChanged(); //date dernier changement de mood
  int seuil = 6; //30s par mood sans manger

  if ((d >= seuil) && (get_mood() < 3) ){
    set_mood(get_mood() + 1);
  }
}

int Jardiniers::recolter_grains(Seed_plants *p) {
	int gr;
	gr = p->check_recolte_grains();
  return gr;
}

void Jardiniers::manger_legumes(Legumes *l) {
	if ((get_mood() > 1) && (l->is_eatable()) ) {
		set_mood(get_mood() - 1);
    cout << "nouveau mood du jardinier :" << get_mood_name() << endl;
	} else {
		set_mood(get_mood());
	}
}