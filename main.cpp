#include "main.h"

int main(int argc, char *argv[]) {
	Champs champs(6);
	//champs.afficher_champs();
	
	Fleurs rose(5);
	Fleurs tulipe(5);
	Legumes tomate(5);
	Fleurs marguerite(5);
	Seed_plants cafe(2, time(NULL), 10);
	
	
	champs.placer_plante(Coordonnees(2, 0), &rose);
	champs.placer_plante(Coordonnees(4, 4), &tulipe);
	champs.placer_plante(Coordonnees(5, 0), &tomate);
	champs.placer_plante(Coordonnees(2, 1), &marguerite);
	champs.placer_plante(Coordonnees(3, 5), &cafe);

	champs.afficher_champs();
	
	Jardiniers j("Jean", 1);
	j.set_position(Coordonnees(5, 1));
	CImg<unsigned char> jardinier_sheet_content("CMakeInstall.bmp");
	
	CImg<unsigned char> fenetre(500, 500, 1, 3, 0);
	champs.dessiner_champs(&fenetre);

	while (!champs.is_empty()) {
		j.mood_change();
		jardinier_sheet_content.display();
		//j.dessiner_jardiniers(&fenetre);
		champs.action(&j);
		cout << "main : " << j.get_mood_name() << endl;
		cout << j.get_position() << endl;
		champs.afficher_champs();
		fenetre.display();
		sleep(1);
	}
	
	//champs.afficher_champs();
	return 0;
}
