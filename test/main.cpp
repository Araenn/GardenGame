#include "main.h"

int main(int argc, char *argv[]) {

	load_jardinier_images(); //chargement des images des jardiniers
	loadImagesVariete(); //idem pour plantes


	Champs champs(35);
	CImg<unsigned char> fenetre(1200, 1050, 1, 3, 0);
	
	Fleurs rose(Variete::ROSE);
	Fleurs tulipe(Variete::TULIPE);
	Legumes tomate(Variete::TOMATE);
	Fleurs marguerite(Variete::TOURNESOL);
	Seed_plants cafe(10, Variete::CAFE);
	Legumes framboise(Variete::FRAMBOISE);
	Seed_plants ble(10, Variete::BLE);
	
	
	
	
	Jardiniers j("Jean", Coordonnees(10, 1));
	Jardiniers j2("Claude", Coordonnees(0, 1));
	champs.dessiner_champs(&fenetre);

	CImgDisplay jeu(1200, 1050, "Garden Game");
	champs.placer_plante(Coordonnees(2, 0), rose, &fenetre);
	champs.placer_plante(Coordonnees(4, 4), tulipe, &fenetre);
	champs.placer_plante(Coordonnees(5, 0), tomate, &fenetre);
	champs.placer_plante(Coordonnees(2, 1), marguerite, &fenetre);
	champs.placer_plante(Coordonnees(3, 5), cafe, &fenetre);
	champs.placer_plante(Coordonnees(5, 1), framboise, &fenetre);
	champs.placer_plante(Coordonnees(0, 1), ble, &fenetre);


	while (!jeu.is_closed()) {//d'abord mood, puis action, puis dessin champs, update champs (plantes), et dessin jardiniers
		j.update_mood();
		//j2.update_mood();

		//champs.action(j2, &fenetre);
		champs.action(j, &fenetre);

		champs.dessiner_champs(&fenetre);
		champs.update_champs(&fenetre);

		//j2.dessiner_jardiniers_champs(&fenetre);
		j.dessiner_jardiniers_champs(&fenetre);

		fenetre.display(jeu);
		sleep(1);
	}

	return 0;
}

