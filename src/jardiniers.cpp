#include "jardiniers.h"

static vector<vector<CImg<unsigned char>>> jardiniers_imgs; // [mood][orientation]
static bool jardiniers_imgs_loaded = false;

Jardiniers::Jardiniers(string name, const Coordonnees &coordonnees) {
  this->name = name;
  this->moodType = MoodType::HAPPY;
  this->position = coordonnees;
  this->date_mood_changed = time(NULL);
  this->orientation = Orientation::SOUTH;
}

Jardiniers::Jardiniers(const Coordonnees &position) {
  this->position = position;
  this->name = name;
  this->moodType = MoodType::HAPPY;
  this->date_mood_changed = time(NULL);
  this->orientation = Orientation::SOUTH;
}

string Jardiniers::get_name() const {
  return this->name;
}

MoodType Jardiniers::get_mood() const {
  return this->moodType;
}

Coordonnees Jardiniers::get_position() const {
  return this->position;
}

void Jardiniers::set_position(const Coordonnees &position) {
  this->position = position;
}

/*
update the mood of the gardeners, according to the threshold determined
they start happy, then normal and finally grumpy
*/
void Jardiniers::update_mood() {
  int timeElapsedFromCurrentMood = time(NULL) - this->date_mood_changed;

  int seuil = 15;

  if ((timeElapsedFromCurrentMood >= seuil) && (get_mood() != MoodType::GRUMPY)){
    set_mood(get_next_mood(this->get_mood()));
  }

}

void Jardiniers::set_mood(const MoodType &moodType) {
  this->moodType = moodType;
  this->date_mood_changed = time(NULL);
}

void Jardiniers::set_orientation(const Orientation &orientation) {
  this->orientation = orientation;
}

/*
get the seeds from a seed plant
*/
void Jardiniers::recolter_grains(const Seed_plants &p) {
	nb_graines_joueur =  20 + nb_graines_joueur;
}

/*
eat vegetables, and change mood from normal to happy
*/
void Jardiniers::manger_legumes(const Legumes &legume) {
	if ((get_mood() != MoodType::HAPPY) && (legume.is_eatable())) {
		set_mood(get_previous_mood(get_mood()));
	}
}

ostream &operator<<(ostream &stream, const Jardiniers &jardinier) {
  return stream << "Jardinier: " << jardinier.get_position() << ", mood: " << jardinier.get_mood();
}

/*
load the gardener picture according to its orientation and mood
*/
CImg<unsigned char> Jardiniers::dessiner_jardiniers() {
  if (!jardiniers_imgs_loaded) {
    throw invalid_argument("You need to use function load_jardinier_images() before !");
  }

  return jardiniers_imgs[this->get_mood().get_id()][this->orientation.get_id()];
}

/*
pre load all the gardener pictures
*/
void load_jardinier_images() {
  if (jardiniers_imgs_loaded) {return;}

  for (int mood_type = 0; mood_type < MAX_MOOD_VALUE + 1; mood_type++) {
    vector <CImg<unsigned char>> vectOfJardiniers;
    for (int orientation_type = 0; orientation_type < 4; orientation_type++) {
      string fileName = "./data/character/" + get_mood_type_from_id(mood_type).get_name() + "/" + get_orientation_from_id(orientation_type).get_name() + ".bmp";
      const char *fileName1 = fileName.c_str();
      CImg<unsigned char> img(fileName1);
      img.resize(img.height() * 3.5, img.width() * 4.5);
      vectOfJardiniers.push_back(img);
    }
    jardiniers_imgs.push_back(vectOfJardiniers);
  }

  jardiniers_imgs_loaded = true;
}

/*
update the new position of the gardener according to its current position and the plants coordinates
*/
void Jardiniers::se_deplacer(const Coordonnees &coordPlante, CImg<unsigned char> *fenetre) {
  int dx, dy;
  int e;
  int x1, x2, y1, y2;
  x1 = this->get_position().getX();
  y1 = this->get_position().getY();
  x2 = coordPlante.getX();
  y2 = coordPlante.getY();
  e = x2 - x1;
  dx = e*2;
  dy = (y1 - y2) * 2;

  //cout << "Le jardinier doit aller de " << this->get_position() << " à " << coordPlante << endl;

  //plante haut droite
  if ((coordPlante.getX() > get_position().getX() ) && (coordPlante.getY() > get_position().getY())) {
    if (x1 <= x2) {
      x1 = x1 + 1;
      set_position({x1, y1});
      set_orientation(Orientation::EAST);
      
      if ( (e = e - dy ) <= 0) {
        y1 = y1 - 1;
        set_position({x1, y1});
        set_orientation(Orientation::SOUTH);
        
        e = e + dx;
      }
    }

  } else if ((coordPlante.getX() == get_position().getX() ) && (coordPlante.getY() > get_position().getY())) {
    
    if (y1 < y2) {
      y1 = y1 + 1;
      set_position({x1, y1});
      set_orientation(Orientation::SOUTH);
      
    }

  } else if ((coordPlante.getX() > get_position().getX() ) && (coordPlante.getY() == get_position().getY())) {
    
    if (x1 < x2) {
      x1 = x1 + 1;
      set_position({x1, y1});
      set_orientation(Orientation::EAST);
      
    } 

  } else if ((coordPlante.getX() > get_position().getX()) && (coordPlante.getY() < get_position().getY()) ){
    
    if (x1 <= x2) {
      x1 = x1 + 1;
      set_position({x1, y1});
      set_orientation(Orientation::EAST);
      
      if ( (e = e - dy ) <= 0) {
        y1 = y1 + 1;
        set_position({x1, y1});
        set_orientation(Orientation::SOUTH);
        
        e = e + dx;
      }
    }

  } else if ((coordPlante.getX() == get_position().getX() ) && (coordPlante.getY() < get_position().getY())) {
    
    if (y1 > y2) {
      y1 = y1 - 1;
      set_position({x1, y1});
      set_orientation(Orientation::NORTH);
      
    }
    
  } else if ((coordPlante.getX() < get_position().getX() ) && (coordPlante.getY() == get_position().getY())) {
    
    if (x1 > x2) {
      x1 = x1 - 1;
      set_position({x1, y1});
      set_orientation(Orientation::WEST);
      
    }
    
  } else if ((coordPlante.getX() > get_position().getX() ) && (coordPlante.getY() == get_position().getY())) {
    
    if (x1 < x2) {
      x1 = x1 + 1;
      set_position({x1, y1});
      set_orientation(Orientation::EAST);
      
    }
    
  } else if ((coordPlante.getX() < get_position().getX()) && (coordPlante.getY() > get_position().getY()) ) {
    
    if (x1 >= x2) {
      x1 = x1 - 1;
      set_position({x1, y1});
      set_orientation(Orientation::WEST);
      
      if ( (e = e - dy ) <= 0) {
        y1 = y1 + 1;
        set_position({x1, y1});
        set_orientation(Orientation::SOUTH);
        
        e = e + dx;
      }
    }
    
  } else if ((coordPlante.getX() < get_position().getX()) && (coordPlante.getY() < get_position().getY()) ) {
    
    if (x1 >= x2) {
      x1 = x1 - 1;
      set_position({x1, y1});
      set_orientation(Orientation::WEST);
      
      if ( (e = e - dy ) <= 0) {
        y1 = y1 + 1;
        set_position({x1, y1});
        set_orientation(Orientation::SOUTH);
        
        e = e + dx;
      }
    }
    
  } else if ((coordPlante.getX() == get_position().getX() ) && (coordPlante.getY() == get_position().getY())) {
    cout << "jardiniers et plantes au même endroit !" << endl;
  } 
    else {
    cout << "probleme de position plante/jard" << endl;
  }

}


/*
draw the gardeners to the screen
*/
void Jardiniers::dessiner_jardiniers_champs(CImg<unsigned char> *fenetre) {
  
  int x1, y1;
  x1 = this->get_position().getX();
  y1 = this->get_position().getY();

  load_jardinier_images();
  CImg<unsigned char> jard = dessiner_jardiniers();
  CImg<float> mask = make_transparent(jard);
  fenetre->draw_image(x1*48, y1*48, 0, 0, jard, mask);
}