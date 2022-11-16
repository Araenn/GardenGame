#include "jardiniers.h"

Jardiniers::Jardiniers(string name, int mood, Coordonnees position) {
  this->name = name;
  this->mood = mood;
  this->position = position;
  this->date_mood_changed = time(NULL);
}

Jardiniers::Jardiniers(string n, int m) : 
Jardiniers(n, m, {0, 0}) {}

Jardiniers::Jardiniers(string n) :
Jardiniers(n, 1, {0, 0}) {}

Jardiniers::Jardiniers() :
Jardiniers("Jardinier 1", 1, {0, 0}) {}

string Jardiniers::get_name() {
  return this->name;
}

void Jardiniers::set_name(string name) {
  this->name = name;
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

void Jardiniers::set_mood(int mood) {
  this->mood = mood;
  this->date_mood_changed = time(NULL);
}

Coordonnees Jardiniers::get_position() {
  return this->position;
}

void Jardiniers::set_position(Coordonnees position) {
  this->position = position;
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
	return p->check_recolte_grains();
}

void Jardiniers::manger_legumes(Legumes *l) {
	if ((get_mood() > 1) && (l->is_eatable()) ) {
		set_mood(get_mood() - 1);
    cout << "nouveau mood du jardinier :" << get_mood_name() << endl;
	}
}

CImg<unsigned char> Jardiniers::dessiner_jardiniers(CImg<unsigned char> *fenetre) {
  CImg<unsigned char> jardinier_sheet_content("img_passbas.png");
  CImg<unsigned char> jardinier_sheet_normal("Yellow-Cap-Character-16x18.png");
  CImg<unsigned char> jardinier_sheet_grincheux("Red-Cap-Character-16x18.png");
  switch (get_mood()) {
  case 1:
    return jardinier_sheet_content;
  case 2:
    return jardinier_sheet_normal;
  case 3:
    return jardinier_sheet_grincheux;  
  default:
    CImg<unsigned char> probleme("Crop_Spritesheet.png");
    return probleme;
  }
}