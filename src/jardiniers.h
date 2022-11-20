#ifndef JARDINIERS_H
#define JARDINIERS_H

#include <iostream>
#include <unistd.h>
#include "seed_plants.h"
#include "legumes.h"
#include "coordonnees.h"
#include "fleurs.h"
#include "orientation.h"
#include "moodType.h"
#include "lib/CImg.h"

using namespace std;
using namespace cimg_library;

void load_jardinier_images();

class Jardiniers {
    
  protected:
    string name;
    MoodType moodType;
    Coordonnees position;
    int date_mood_changed;
    Orientation orientation;

  public:
    Jardiniers(string, const Coordonnees &coordonnees);
    
    string get_name() const;
    MoodType get_mood() const;
    Coordonnees get_position() const;
    void set_position(const Coordonnees &position);

    void update_mood();
    void set_mood(const MoodType &moodType);

    int recolter_grains(const Seed_plants &p) const;
    void manger_legumes(const Legumes &legume);

    CImg<unsigned char> dessiner_jardiniers();
    void se_deplacer(Coordonnees);

    friend ostream &operator<<(ostream &stream, const Jardiniers &jardinier);
};

#endif
