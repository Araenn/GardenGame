#include "champs.h"

/*
initialize a field full of plants. for a "hole", the cell is filled with a "default plant"
*/
Champs::Champs(int size_grille) {
    for (int i = 0; i < size_grille; i++) {
        vector<Plantes> line;
        for (int j = 0; j < size_grille; j++) {
            line.push_back(Plantes::DEFAULT);
        }
        this->grille.push_back(line);

    }
    this->size_grille = size_grille;
}

/*
debug visualization of the field, as a matrix
*/
void Champs::afficher_champs() const {
    for (int i = 0; i < this->size_grille; i++) {
		for (int j = 0; j < this->size_grille; j++) {
			cout << '[' << this->grille[j][i] << "] ";
		}
		cout << endl;
	}
}

/*
place a plant in the field, according to its coordinates
*/
void Champs::placer_plante(const Coordonnees &coord, const Plantes &p) {
    grille[coord.getX()][coord.getY()] = p;
}

/*
get the plants coordinates if placed in the field
*/
Coordonnees Champs::get_coordonnees(const Plantes &p) const {
    for (int i = 0; i < this->size_grille; i++) {
        for (int j = 0; j < this->size_grille; j++) {
            if (grille[i][j].get_id() == p.get_id()) {
                Coordonnees coordonnees(i, j); 
                return coordonnees;
            }
        }
    }
    Coordonnees coordonnees(-1, -1); 
    return coordonnees;
}

/*
compute the distance between a gardener and a plant
*/
double Champs::calcul_distance(const Plantes &p, const Jardiniers &jardiniers) const {
    Coordonnees coordsPlante = get_coordonnees(p);
    Coordonnees coordsJardinier = jardiniers.get_position();

    double distance = sqrt(pow(coordsPlante.getY() - coordsJardinier.getY(), 2) + pow(coordsPlante.getX() - coordsJardinier.getX(), 2));

    return distance;
}

/*
gather all types of plants present in the field in a vector
*/
vector<Plantes> Champs::getAllPlantType(const Plants_types &plants_types) {
    vector<Plantes> plantes;

    for (int i = 0; i < size_grille; i++) {
        for (int j = 0; j < size_grille; j++) {
            if (this->grille[i][j].get_type() == plants_types) {
                plantes.push_back(this->grille[i][j]);
            }
        }
    }

    return plantes;
}

/*
determine the closest plant to the gardener, thanks to the Champs::calul_distance()
*/
Plantes &Champs::plus_proche_plante(const Jardiniers &jardinier, const Plants_types &plants_types) {

    vector<Plantes> plantes = getAllPlantType(plants_types);

    if (plantes.size() == 0) {
        return this->grille[4][4];
    }

    Coordonnees coordsMins = get_coordonnees(plantes[0]);
    double minDistance = calcul_distance(this->grille[coordsMins.getX()][coordsMins.getY()], jardinier);

    for (unsigned long int i = 1; i < plantes.size(); i++) {
        const Plantes &currentPlant = plantes[i];
        double currentDistance = calcul_distance(currentPlant, jardinier);
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            coordsMins = get_coordonnees(currentPlant);
        }
    }

    return this->grille[coordsMins.getX()][coordsMins.getY()];
}

/*
determine if the plant is in the field 
*/
bool Champs::contains_plant_type(const Plants_types &plant_type) {
    for (int i = 0; i < size_grille; i++) {
        for (int j = 0; j < size_grille; j++) {
            if (grille[i][j].get_type() == plant_type) {
                return true;
            }
        }
    }
    return false;
}

/*
remove the plant in the field and place a "default" one instead
*/
void Champs::detruire_plante(const Plantes &plante, CImg<unsigned char> *fenetre) {
    placer_plante(get_coordonnees(plante), Plantes::DEFAULT);
}

/*
main function, determine the behavior of the gardeners.
According to their mood : 
if happy, then gardener seek a seed plant
if normal, seek a seed plant or a vegetable, according to the closest
if grumpy, seek a vegetable or a flower, according to the closest

when the right plant is found, gardener will move to it until his coordinates are the same than the plant
seed plants are vowed to be recolted, vegetables to be eat and flowers to be destroyed
action with the plants can only be done if they are a stage 5, fully grown
*/
void Champs::action(Jardiniers &jardinier, CImg<unsigned char> *fenetre, CImgDisplay &jeu) {
    
    if (jardinier.get_mood() == MoodType::HAPPY) {
        
        if (contains_plant_type(Plants_types::SEED_PLANTS)) {
            
            Seed_plants *a_recolter = (Seed_plants *) &plus_proche_plante(jardinier, Plants_types::SEED_PLANTS);
            if (a_recolter->isRecoltable()) {
                while (jardinier.get_position() != get_coordonnees(*a_recolter)) {
                    jardinier.se_deplacer(get_coordonnees(*a_recolter), fenetre);
                    
                }
                jardinier.recolter_grains(*a_recolter);
                detruire_plante(*a_recolter, fenetre);
                
                cout << "Le jardinier " << jardinier.get_name() << " était content et a supprimé la plante à graine en " << jardinier.get_position() << "." << endl;
            } else {
                
                //cout << "Le jardinier était content mais la plante a graine la plus proche n'était pas récoltable." << endl;
            }
        } else {
            
            //cout << "Le jardinier était content, il voulait récolter du grain, mais il n'en a pas trouvé dans le champs." << endl;
        }
    
    } else if (jardinier.get_mood() == MoodType::NORMAL) {
        
        if (contains_plant_type(Plants_types::LEGUME)) {
            
            Legumes *a_manger = (Legumes *) &plus_proche_plante(jardinier, Plants_types::LEGUME);
            if (a_manger->is_eatable()) {
                while (jardinier.get_position() != get_coordonnees(*a_manger)) {
                    jardinier.se_deplacer(get_coordonnees(*a_manger), fenetre);
                    
                }
                jardinier.manger_legumes(*a_manger);
                detruire_plante(*a_manger, fenetre);
                
                cout << "Le jardinier " << jardinier.get_name() << " était normal et a supprimé le légume en " << jardinier.get_position() << endl;
            } else {
                
                //cout << "Le jardinier était normal mais le legume la plus proche n'était pas récoltable." << endl;
            }
        } else if (contains_plant_type(Plants_types::SEED_PLANTS)) {
            
            Seed_plants *a_recolter = (Seed_plants *) &plus_proche_plante(jardinier, Plants_types::SEED_PLANTS);
            if (a_recolter->isRecoltable()) {
                while (jardinier.get_position() != get_coordonnees(*a_recolter)) {
                    jardinier.se_deplacer(get_coordonnees(*a_recolter), fenetre);
                    
                }
                jardinier.recolter_grains(*a_recolter);
                detruire_plante(*a_recolter, fenetre);
                
                cout << "Le jardinier " << jardinier.get_name() << " était normal et a supprimé la plante  à graine en " << jardinier.get_position() << endl;
            } else {
                
                //cout << "Le jardinier était normal mais la plante à graine la plus proche n'était pas récoltable." << endl;
            }
        } else {
            
            //cout << "Le jardinier était normal mais n'a pas trouvé de plante a graine et de legume." << endl;
        }

    } else if (jardinier.get_mood() == MoodType::GRUMPY) {
        
        if (contains_plant_type(Plants_types::LEGUME)) {
            Legumes *a_manger = (Legumes *) &plus_proche_plante(jardinier, Plants_types::LEGUME);
            
            if (a_manger->is_eatable()) {
                while (jardinier.get_position() != get_coordonnees(*a_manger)) {
                    jardinier.se_deplacer(get_coordonnees(*a_manger), fenetre);
                    
                }
                jardinier.manger_legumes(*a_manger);
                detruire_plante(*a_manger, fenetre);
                
                cout << "Le jardinier " << jardinier.get_name() << " était pas content et a supprimé le légume en " << jardinier.get_position() << endl;
            } else {
                
                //cout << "Le jardinier était pas content mais le légume la plus proche n'était pas récoltable." << endl;
            }

        } else if (contains_plant_type(Plants_types::FLOWER)) {
            Fleurs *a_detruire = (Fleurs *) &plus_proche_plante(jardinier, Plants_types::FLOWER);
            while (jardinier.get_position() != get_coordonnees(*a_detruire)) {
                jardinier.se_deplacer(get_coordonnees(*a_detruire), fenetre);
                
            }
            detruire_plante(*a_detruire, fenetre);
            jardinier.set_mood(MoodType::NORMAL);
            
            cout << "Le jardinier " << jardinier.get_name() << " était pas content et a supprimé la fleur en " << jardinier.get_position() << endl;
        } else {
            
            //cout << "RIEN d'accessible" << endl;
        }

    } else {
        
        cout << "oulala c'est bizarre" << endl;
        cout << "debug pb : " << jardinier.get_mood().get_name() << endl;
        cout << "debug pb : " << jardinier.get_position() << endl;
    }
  }

/*
determine if the field is empty
*/
bool Champs::is_empty() {
    for (int i = 0; i < size_grille; i++) {
        for (int j = 0; j < size_grille; j++) {
            if (grille[i][j] != Plantes::DEFAULT) {
                return false;
            }
        }
    }
    return true;
}

/*
draw the field and currently the menu
*/
void Champs::dessiner_champs(CImg<unsigned char> *fenetre) {
    //dessin du fond
    unsigned char coyote_brown[] = {129, 97, 60};
    fenetre->draw_rectangle(0, 0, WIDTH_GAME, 640*2, coyote_brown);

    //dessin du champs
    CImg<unsigned char> grass("./data/grass.bmp");
    grass.resize(grass.width() * 1.2, grass.height() * 1.2);
    fenetre->draw_image(0, 0, grass);

    //dessin du menu
    unsigned char brown[] = {144, 84, 47};
    fenetre->draw_rectangle(WIDTH_C, 0, WIDTH_GAME, HEIGHT_MENU, brown);

    //dessin du contour de "jardin"
    unsigned char black[] = {0, 0, 0};
    int lineWidth = 200;
    int offset = 1;
    fenetre->draw_line(WIDTH_C + offset, HEIGHT_MENU/1.5, WIDTH_GAME, HEIGHT_MENU/1.5, black, lineWidth);//hor bas
    fenetre->draw_line(WIDTH_C + offset, 0, WIDTH_C + offset, HEIGHT_MENU, black, lineWidth);//vert gauche
    fenetre->draw_line(WIDTH_C, 0, WIDTH_GAME, 0, black, lineWidth);//hor haut
    fenetre->draw_line(WIDTH_GAME - offset, 0, WIDTH_GAME - offset, HEIGHT_MENU, black, lineWidth);//vert droite

    //dessin separation menu
    fenetre->draw_line(WIDTH_C, HEIGHT_MENU, WIDTH_GAME, HEIGHT_MENU, black); //hor bas
    fenetre->draw_line(WIDTH_C + ((WIDTH_GAME - WIDTH_C)/ 2), HEIGHT_MENU/1.5, WIDTH_C + ((WIDTH_GAME - WIDTH_C)/ 2), HEIGHT_MENU, black); //vert milieu

    CImg <unsigned char> logo("./data/logo_gardengame.bmp");
    logo.resize(logo.width()/9, logo.height()/9);
    CImg <float> mask = make_transparent(logo);
    fenetre->draw_image(WIDTH_C + 50, 0, logo, mask);
    
} 

/*
update the field by drawing again the field, changing plants stages and drawing them
*/
void Champs::update_champs(CImg<unsigned char> *fenetre) {
    dessiner_champs(fenetre);
    quadrillage(fenetre);
    for (int i = 0; i < this->size_grille; i++) {
        for (int j = 0; j < this->size_grille; j++) {
            if (grille[i][j] != Plantes::DEFAULT) {
                grille[i][j].update_plant();
                Coordonnees plantCoords = get_coordonnees(grille[i][j]);
                grille[i][j].dessiner_plantes(fenetre, plantCoords.getX() * 48, plantCoords.getY() * 48);
            }
        }
    }
}