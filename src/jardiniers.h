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
#include "CImgUtils.h"

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
    Jardiniers(const Coordonnees &position);

    string get_name() const;
    MoodType get_mood() const;
    Coordonnees get_position() const;
    void set_position(const Coordonnees &position);
    void set_orientation(const Orientation &orientation);
    
    void update_mood();
    void set_mood(const MoodType &moodType);

    void recolter_grains(const Seed_plants &p);
    void manger_legumes(const Legumes &legume);

    CImg<unsigned char> dessiner_jardiniers();
    void dessiner_jardiniers_champs(CImg<unsigned char> *fenetre);
    void se_deplacer(const Coordonnees &, CImg<unsigned char> *fenetre);

    friend ostream &operator<<(ostream &stream, const Jardiniers &jardinier);

    
};

#endif
