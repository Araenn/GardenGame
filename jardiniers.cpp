#include "jardiniers.h"

Jardiniers::Jardiniers(string n, int m, int p[2]) {
  name = n;
  mood = m;
  position[0] = p[0];
  position[1] = p[1];
  date_mood_changed = time(NULL);
}

Jardiniers::Jardiniers(string n, int m) {
  name = n;
  mood = m;
  position[0] = 0;
  position[1] = 0;
  date_mood_changed = time(NULL);
}

Jardiniers::Jardiniers(string n) {
  name = n;
  mood = 1;
  position[0] = 0;
  position[1] = 0;
  date_mood_changed = time(NULL);
}

Jardiniers::Jardiniers() {
  name = "Jardinier 1";
  mood = 1;
  position[0] = 0;
  position[1] = 0;
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

int Jardiniers::get_position() {
  return position[2];
}

void Jardiniers::set_position(int p[2]) {
  position[0] = p[0];
  position[1] = p[1];
}

int Jardiniers::choix_action() {
  int action;
  if (get_mood_name() == "Content") {
    return action = 0; //recolte grains
  } else if (get_mood_name() == "Normal") {
    return action = 1; //grains ou legums, le plus proche
  } else {
    return action = 2; //legume si proche, sinon fleur detruite
  }
}

int Jardiniers::get_dateMoodChanged() {
  return time(NULL) - date_mood_changed;
}

void Jardiniers::mood_change() {
  int t = time(NULL); //temps ecoule
  int d = get_dateMoodChanged(); //date dernier changement de mood
  int seuil = 30; //30s par mood sans manger

  if ((t - d > seuil) && (get_mood() != 3) ){
    set_mood(get_mood() + 1);
  }
}
