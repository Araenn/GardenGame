#include "champs.h"

Champs::Champs(int size_grille) {
    this->grille = (Plantes**)malloc(sizeof(Plantes*)*size_grille);
    for (int i = 0; i < size_grille; i++) {
        grille[i] = (Plantes*)malloc(sizeof(Plantes)*size_grille);
        for (int j = 0; j < size_grille; j++) {
            grille[i][j] = Plantes(0);
        }
    }
    this->size_grille = size_grille;
}

void Champs::afficher_champs() {
    for (int i = 0; i < this->size_grille; i++) {
		for (int j = 0; j < this->size_grille; j++) {
			cout << '[' << grille[j][i] << "] ";
		}
		cout << endl;
	}
}

void Champs::placer_plante(int x, int y, Plantes p) {
    grille[x][y] = p;
}

Coordonnees Champs::get_coordonnees(Plantes p) {
    for (int i = 0; i < this->size_grille; i++) {
        for (int j = 0; j < this->size_grille; j++) {
            if (grille[i][j].get_id() == p.get_id()) {
                Coordonnees coordonnees(i, j); 
                return coordonnees;
            }
        }
    }
}

double Champs::calcul_distance(Plantes p, Jardiniers jardiniers) {
    Coordonnees coordsPlante = get_coordonnees(p);

    /*if (coordsPlante == {0, 0}) { // la plante p n'a pas été trouvée
        // print c'est bizarre;
        return -1;
    }*/

    Coordonnees coordsJardinier = jardiniers.get_position();

    double distance = sqrt(pow(coordsPlante.y - coordsJardinier.y, 2) + pow(coordsPlante.x - coordsJardinier.x, 2));
    return distance;
}

Plantes Champs::plus_proche_plante(Jardiniers jardinier) {
    Plantes plusProche;
    Plantes par_defaut(0, 0, 0);
    for (int i = 0; i < size_grille; i++) {
        for (int j = 0; j < size_grille; j++) {
            while (grille[i][j] != par_defaut) {
                calcul_distance(grille[i][j], jardinier);
                
            }

        }
    }
    return plusProche;
}