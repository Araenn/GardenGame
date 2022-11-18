#include "main.h"

CImg<float> make_transparent(CImg<unsigned char>&image);

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
	
	CImg<unsigned char> fenetre(1200, 1050, 1, 3, 0);
	champs.dessiner_champs(&fenetre);

	CImg<unsigned char> gardener = j.dessiner_jardiniers();
	gardener = make_transparent(gardener);
	CImgList<unsigned char> gard1, gard2;
	gard1 = gardener.get_split('x', 3);
	gard2 = gard1[0].get_split('y', 4);
	gard2[0].display();
	
  	fenetre.draw_image(0, 350, 0, 0, j.dessiner_jardiniers(), gardener);
	fenetre.draw_image(0, 100, 0, 0, gard2[0]);

  	fenetre.display();

	/*

	while (!champs.is_empty()) {
		j.mood_change();
		j.dessiner_jardiniers(&fenetre);
		champs.action(&j);
		cout << "main : " << j.get_mood_name() << endl;
		cout << j.get_position() << endl;
		champs.afficher_champs();
		fenetre.display();
		sleep(1);
	}
	*/
	//champs.afficher_champs();
	return 0;
}

CImg<float> make_transparent(CImg<unsigned char>&image) {
	CImg<float> opacite(image.width(), image.height(), 1, 1, 0);
	for (int x = 0; x < opacite.width(); x++)
		for (int y = 0; y < opacite.height(); y++)
			if (image(x, y, 0) == 0 && image(x, y, 1) == 0 && image(x, y, 2) == 0) {
				opacite(x, y) = 0;
			}
			else {
				opacite(x, y) = 1;
			}
	return opacite;
}
