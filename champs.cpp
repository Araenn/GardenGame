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

int* Champs::get_coordonnees(Plantes p) {
    for (int i = 0; i < this->size_grille; i++) {
        for (int j = 0; j < this->size_grille; j++) {
            if (grille[i][j].get_id() == p.get_id()) {
                int* coordonnees = (int *) malloc(sizeof(int)*2);
                coordonnees[0] = i;
                coordonnees[1] = j;
                return coordonnees;
            }
        }
    }
    return NULL;
}

double Champs::calcul_distance(Plantes p, Jardiniers jardiniers) {
    int *coordsPlante = get_coordonnees(p);

    if (coordsPlante == NULL) { // la plante p n'a pas été trouvés
        // print c'est bizarre;
        return -1;
    }

    int *coordsJardinier = jardiniers.get_position();

    double distance = sqrt(pow(coordsPlante[1] - coordsJardinier[1], 2) + pow(coordsPlante[0] - coordsJardinier[1], 2));
    free(coordsPlante);
    return distance;
}