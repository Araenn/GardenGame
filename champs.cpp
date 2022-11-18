#include "champs.h"

Champs::Champs(int size_grille) {
    this->grille = (Plantes***) malloc(sizeof(Plantes**) * size_grille);
    for (int i = 0; i < size_grille; i++) {
        this->grille[i] = (Plantes**) malloc(sizeof(Plantes*) * size_grille);
        for (int j = 0; j < size_grille; j++) {
            this->grille[i][j] = getDefaultPlant();
        }
    }
    this->size_grille = size_grille;
}

Champs::~Champs() {
    for (int i = 0; i < size_grille; i++) {
        free(this->grille[i]);
    }
    free(this->grille);
}

void Champs::afficher_champs() {
    for (int i = 0; i < this->size_grille; i++) {
		for (int j = 0; j < this->size_grille; j++) {
			cout << '[' << *this->grille[j][i] << "] ";
		}
		cout << endl;
	}
}

void Champs::placer_plante(Coordonnees coord, Plantes *p) {
    grille[coord.x][coord.y] = p;
}

Coordonnees Champs::get_coordonnees(Plantes *p) {
    for (int i = 0; i < this->size_grille; i++) {
        for (int j = 0; j < this->size_grille; j++) {
            if (grille[i][j]->get_id() == p->get_id()) {
                Coordonnees coordonnees(i, j); 
                return coordonnees;
            }
        }
    }
    Coordonnees coordonnees(-1, -1); 
    return coordonnees;
}

double Champs::calcul_distance(Plantes *p, Jardiniers *jardiniers) {
    Coordonnees coordsPlante = get_coordonnees(p);
    Coordonnees coordsJardinier = jardiniers->get_position();

    double distance = sqrt(pow(coordsPlante.y - coordsJardinier.y, 2) + pow(coordsPlante.x - coordsJardinier.x, 2));
    return distance;
}

Plantes *Champs::plus_proche_plante(Jardiniers *jardinier, string planteType) {

//calcul des distances entre jardinier et chaque plante non nulle
    double minDistance = -1.0;
    Plantes *minDistancePlante = grille[0][0];

    for (int i = 0; i < size_grille && minDistance == -1.0; i++) {
        for (int j = 0; j < size_grille && minDistance == -1.0; j++) {
            if (grille[i][j]->get_type().compare(planteType) == 0) {
                minDistance = calcul_distance(grille[i][j], jardinier);
                minDistancePlante = grille[i][j];
            }
        }
    }

    for (int i = 0; i < size_grille; i++) {
        for (int j = 0; j < size_grille; j++) {
            if (grille[i][j]->get_type() == planteType) {
                double actuellDistance = calcul_distance(grille[i][j], jardinier);
                if (actuellDistance < minDistance) {
                    minDistance = actuellDistance;
                    minDistancePlante = grille[i][j];
                }
            }
        }
    }
    
    return minDistancePlante;
}

void Champs::detruire_plante(Plantes *plante) {
    placer_plante(get_coordonnees(plante), getDefaultPlant());
}

Plantes *Champs::chercher_plante(string planteType) {
    for (int i = 0; i < size_grille; i++) {
        for (int j = 0; j < size_grille; j++) {
            if (grille[i][j]->get_type() == planteType) {
                return grille[i][j];
            }
        }
    }
    return getDefaultPlant();
}

void Champs::action(Jardiniers *jardinier) {

  if (jardinier->get_mood_name() == "Content") {

    if (plus_proche_plante(jardinier, "Seed_plants")->is_recoltable()) {
        Seed_plants *a_recolter = (Seed_plants *) plus_proche_plante(jardinier, "Seed_plants");
        Coordonnees seedplantsCoord = get_coordonnees((Plantes *) a_recolter);
        jardinier->set_position(seedplantsCoord);
        jardinier->recolter_grains(a_recolter); //recolte grains
        detruire_plante(a_recolter);
        cout << "debug : " << jardinier->get_mood_name() << endl;
        cout << "debug : " << jardinier->get_position() << endl;

    } else {
        cout << "debug : " << jardinier->get_mood_name() << endl;
        cout << "debug : " << jardinier->get_position() << endl;
    }
    
  } else if (jardinier->get_mood_name() == "Normal") {
        cout << "debug : " << jardinier->get_mood_name() << endl;
      if ( plus_proche_plante(jardinier, "Legumes")->is_recoltable()) {
        Legumes *a_manger = (Legumes *) plus_proche_plante(jardinier, "Legumes");
        Coordonnees legumesCoord = get_coordonnees((Plantes *)a_manger);
        cout << "coordplante : " << legumesCoord << endl;
        jardinier->set_position(legumesCoord);
        jardinier->manger_legumes(a_manger);
        detruire_plante(a_manger);
        cout << "debug : " << jardinier->get_position() << endl;

      } else if (plus_proche_plante(jardinier, "Seed_plants")->is_recoltable()) {
        Seed_plants *a_recolter = (Seed_plants *) plus_proche_plante(jardinier, "Seed_plants");
        Coordonnees seedplantsCoord = get_coordonnees((Plantes *) a_recolter);
        jardinier->set_position(seedplantsCoord);
        jardinier->recolter_grains(a_recolter);//grains ou legums, le plus proche
        detruire_plante(a_recolter);
        cout << "debug : " << jardinier->get_mood_name() << endl;
        cout << "debug : " << jardinier->get_position() << endl;
    } else {
        cout << "il faut attendre " << endl;
    }
  } else if (jardinier->get_mood_name() == "Grincheux") {
        cout << "debug : " << jardinier->get_mood_name() << endl;
        if (plus_proche_plante(jardinier, "Legumes")->is_recoltable()) {
            Legumes *a_manger = (Legumes *) plus_proche_plante(jardinier, "Legumes");
            Coordonnees legumesCoord = get_coordonnees((Plantes *)a_manger);
            cout << "coordplante : " << legumesCoord << endl;
            jardinier->set_position(legumesCoord);
            jardinier->manger_legumes(a_manger);
            detruire_plante(a_manger);
            cout << "debug : " << jardinier->get_mood_name() << endl;
            cout << "debug : " << jardinier->get_position() << endl;

        } else if (plus_proche_plante(jardinier, "Fleurs")->is_recoltable()) {
            Fleurs *a_detruire = (Fleurs *) plus_proche_plante(jardinier, "Fleurs");
            Coordonnees fleursCoord = get_coordonnees((Plantes *)a_detruire);
            jardinier->set_position(fleursCoord);
            detruire_plante(a_detruire); //detruit fleur si pas de legume
            jardinier->set_mood(2);
            cout << "debug : " << jardinier->get_mood_name() << endl;
            cout << "debug : " << jardinier->get_position() << endl;

        } else {
            cout << "ni fleur ni legume" << endl;
        }
  } else {
        cout << "oulala c'est bizarre" << endl;
        cout << "debug pb : " << jardinier->get_mood_name() << endl;
        cout << "debug pb : " << jardinier->get_position() << endl;
    }
  }

bool Champs::is_empty() {
    for (int i = 0; i < size_grille; i++) {
        for (int j = 0; j < size_grille; j++) {
            if (grille[i][j] != getDefaultPlant()) {
                return false;
            }
        }
    }
    return true;
}

void Champs::dessiner_champs(CImg<unsigned char> *fenetre) {
    CImg<unsigned char> grass("grass.bmp");
    grass.resize(grass.width()*1.2, grass.height()*1.2);
    fenetre->draw_image(0, 0, grass);
} 