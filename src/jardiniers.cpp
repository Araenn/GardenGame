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

void Jardiniers::update_mood() {
  int timeElapsedFromCurrentMood = time(NULL) - this->date_mood_changed;

  int seuil = 6; //30s par mood sans manger

  if ((timeElapsedFromCurrentMood >= seuil) && (get_mood() != MoodType::GRUMPY)){
    set_mood(get_next_mood(this->get_mood()));
  }

}

void Jardiniers::set_mood(const MoodType &moodType) {
  this->moodType = moodType;
  this->date_mood_changed = time(NULL);
}

int Jardiniers::recolter_grains(const Seed_plants &p) const {
	return p.check_recolte_grains();
}

void Jardiniers::manger_legumes(const Legumes &legume) {
	if ((get_mood() != MoodType::HAPPY) && (legume.is_eatable())) {
		set_mood(get_previous_mood(get_mood()));
    cout << "nouveau mood du jardinier :" << get_mood().get_name() << endl;
	}
}

ostream &operator<<(ostream &stream, const Jardiniers &jardinier) {
  return stream << "Jardinier: " << jardinier.get_position() << ", mood: " << jardinier.get_mood();
}

CImg<unsigned char> Jardiniers::dessiner_jardiniers() {
  if (!jardiniers_imgs_loaded) {
    throw invalid_argument("You need to use function load_jardinier_images() before !");
  }

  cout << "mood : " << this->get_mood().get_name() << endl;
  cout << "orientation : " << this->orientation.get_id() << endl;
  return jardiniers_imgs[this->get_mood().get_id()][this->orientation.get_id()];
}

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
  dy = (y2 - y1) * 2;

  load_jardinier_images();
  CImg<unsigned char> jard = dessiner_jardiniers();
  CImg<float> mask = make_transparent(jard);

  if ((coordPlante.getX() > get_position().getX() ) && (coordPlante.getY() > get_position().getY())) {
    cout << "position actuelle du jard : " << get_position() << endl;
    while (x1 <= x2) {
      x1 = x1 + 1;
      set_position({x1, y1});
      fenetre->draw_image(x1*18, y1*18, 0, 0, jard, mask);
      cout << "nouvelle position : " << get_position() << endl;
      if ( (e = e - dy ) <= 0) {
        y1 = y1 + 1;
        set_position({x1, y1});
        fenetre->draw_image(x1*18, y1*18, 0, 0, jard, mask);
        cout << "nouvelle position : " << get_position() << endl;
        e = e + dx;
      }
    }

  } else if ((coordPlante.getX() == get_position().getX() ) && (coordPlante.getY() > get_position().getY())) {
    cout << "position actuelle du jard : " << get_position() << endl;
    while (y1 < y2) {
      y1 = y1 + 1;
      set_position({x1, y1});
      fenetre->draw_image(x1*18, y1*18, 0, 0, jard, mask);
      cout << "nouvelle position : " << get_position() << endl;
    }

  } else if ((coordPlante.getX() > get_position().getX() ) && (coordPlante.getY() == get_position().getY())) {
    cout << "position actuelle du jard : " << get_position() << endl;
    while (x1 < x2) {
      x1 = x1 + 1;
      set_position({x1, y1});
      fenetre->draw_image(x1*18, y1*18, 0, 0, jard, mask);
      cout << "nouvelle position : " << get_position() << endl;
    } 

  } else if ((coordPlante.getX() > get_position().getX()) && (coordPlante.getY() < get_position().getY()) ){
    cout << "position actuelle du jard : " << get_position() << endl;
    while (x1 <= x2) {
      x1 = x1 + 1;
      set_position({x1, y1});
      fenetre->draw_image(x1*18, y1*18, 0, 0, jard, mask);
      cout << "nouvelle position : " << get_position() << endl;
      if ( (e = e - dy ) <= 0) {
        y1 = y1 - 1;
        set_position({x1, y1});
        fenetre->draw_image(x1*18, y1*18, 0, 0, jard, mask);
        cout << "nouvelle position : " << get_position() << endl;
        e = e + dx;
      }
    }

  } else if ((coordPlante.getX() == get_position().getX() ) && (coordPlante.getY() < get_position().getY())) {
    cout << "position actuelle du jard : " << get_position() << endl;
    while (y1 > y2) {
      y1 = y1 - 1;
      set_position({x1, y1});
      fenetre->draw_image(x1*18, y1*18, 0, 0, jard, mask);
      cout << "nouvelle position : " << get_position() << endl;
    }
    
  } else if ((coordPlante.getX() < get_position().getX() ) && (coordPlante.getY() == get_position().getY())) {
    cout << "position actuelle du jard : " << get_position() << endl;
    while (x1 > x2) {
      x1 = x1 - 1;
      set_position({x1, y1});
      fenetre->draw_image(x1*18, y1*18, 0, 0, jard, mask);
      cout << "nouvelle position : " << get_position() << endl;
    }
    
  } else if ((coordPlante.getX() > get_position().getX() ) && (coordPlante.getY() == get_position().getY())) {
    cout << "position actuelle du jard : " << get_position() << endl;
    while (x1 < x2) {
      x1 = x1 + 1;
      set_position({x1, y1});
      fenetre->draw_image(x1*18, y1*18, 0, 0, jard, mask);
      cout << "nouvelle position : " << get_position() << endl;
    }
    
  } else if ((coordPlante.getX() < get_position().getX()) && (coordPlante.getY() > get_position().getY()) ) {
    cout << "position actuelle du jard : " << get_position() << endl;
    while (x1 <= x2) {
      x1 = x1 - 1;
      set_position({x1, y1});
      fenetre->draw_image(x1*18, y1*18, 0, 0, jard, mask);
      cout << "nouvelle position : " << get_position() << endl;
      if ( (e = e - dy ) <= 0) {
        y1 = y1 + 1;
        set_position({x1, y1});
        fenetre->draw_image(x1*18, y1*18, 0, 0, jard, mask);
        cout << "nouvelle position : " << get_position() << endl;
        e = e + dx;
      }
      cout << "nouvelle position : " << get_position() << endl;
    }
    
  } else if ((coordPlante.getX() < get_position().getX()) && (coordPlante.getY() < get_position().getY()) ) {
    cout << "position actuelle du jard : " << get_position() << endl;
    while (x1 <= x2) {
      x1 = x1 - 1;
      set_position({x1, y1});
      fenetre->draw_image(x1*18, y1*18, 0, 0, jard, mask);
      cout << "nouvelle position : " << get_position() << endl;
      if ( (e = e - dy ) <= 0) {
        y1 = y1 - 1;
        set_position({x1, y1});
        fenetre->draw_image(x1*18, y1*18, 0, 0, jard, mask);
        cout << "nouvelle position : " << get_position() << endl;
        e = e + dx;
      }
    }
    
  } else {
    cout << "probleme de position plante/jard" << endl;
  }

}