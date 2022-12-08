#include "main.h"

int main(int argc, char *argv[]) {

	load_jardinier_images();


	cout << "valeur du type par defaut: " << Plantes::DEFAULT.get_type().get_name() << endl;
	cout << "id: " << Plantes::DEFAULT.get_id() << endl;

	Champs champs(6);
	CImg<unsigned char> fenetre(1200, 1050, 1, 3, 0);
	
	Fleurs rose(Variete::ROSE);
	Fleurs tulipe(Variete::TULIPE);
	Legumes tomate(Variete::TOMATE);
	Fleurs marguerite(Variete::ROSE);
	Seed_plants cafe(10, Variete::CAFE);
	
	
	
	
	Jardiniers j("Jean", Coordonnees(5, 1));
	champs.dessiner_champs(&fenetre);

	/*CImg<unsigned char> gardener("./data/character/Content/Green.bmp");
	gardener = make_transparent(gardener);
	CImgList<unsigned char> gard1, gard2;
	gard1 = gardener.get_split('x', 3);
	gard2 = gard1[0].get_split('y', 4);
	
	

	
  	//fenetre.draw_image(0, 350, 0, 0, j.dessiner_jardiniers(), gardener);
	fenetre.draw_image(0, 100, 0, 0, gard2[0]);
*/

	CImgDisplay jeu(1200, 1050, "Garden Game");
	champs.placer_plante(Coordonnees(2, 0), rose, &fenetre);
	champs.placer_plante(Coordonnees(4, 4), tulipe, &fenetre);
	champs.placer_plante(Coordonnees(5, 0), tomate, &fenetre);
	champs.placer_plante(Coordonnees(2, 1), marguerite, &fenetre);
	champs.placer_plante(Coordonnees(3, 5), cafe, &fenetre);
	
	while (!jeu.is_closed()) {
		j.update_mood();
		
		cout << j << endl;
		champs.update_champs();
		//champs.dessiner_champs(&fenetre);
		champs.action(j, &fenetre);
		fenetre.display(jeu);
		sleep(1);
	}
	//champs.afficher_champs();
	return 0;
}

