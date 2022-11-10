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
    Coordonnees coordonnees(-1, -1); 
    return coordonnees;
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

Plantes &Champs::plus_proche_plante(Jardiniers jardinier) {
    Plantes par_defaut(0);

//calcul des distances entre jardinier et chaque plante non nulle
    double minDistance = -1.0;
    Plantes &minDistancePlante = grille[0][0];

    int i = 0;
    int j = 0;
    for (; i < size_grille && minDistance == -1.0; i++) {
        for (; j < size_grille && minDistance == -1.0; j++) {
            if (grille[i][j] != par_defaut) {
                minDistance = calcul_distance(grille[i][j], jardinier);
                minDistancePlante = grille[i][j];
            }
        }
        j = 0;
    }

    if (j + 1 == size_grille) {
        j = 0;
        i++;
    }

    for (; i < size_grille; i++) {
        for (; j < size_grille; j++) {
            if (grille[i][j] != par_defaut) {
                double actuellDistance = calcul_distance(grille[i][j], jardinier);
                if (actuellDistance < minDistance) {
                    minDistance = actuellDistance;
                    minDistancePlante = grille[i][j];
                }
            }
        }
        j = 0;
    }
    
    return minDistancePlante;
}