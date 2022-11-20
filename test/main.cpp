#include "main.h"

int main(int argc, char *argv[]) {

	load_jardinier_images();


	cout << "valeur du type par defaut: " << Plantes::DEFAULT.get_type().get_name() << endl;
	cout << "id: " << Plantes::DEFAULT.get_id() << endl;

	Champs champs(6);
	//champs.afficher_champs();
	
	Fleurs rose(Variete::ROSE);
	Fleurs tulipe(Variete::TULIPE);
	Legumes tomate(Variete::TOMATE);
	Fleurs marguerite(Variete::ROSE);
	Seed_plants cafe(10, Variete::CAFE);
	
	
	champs.placer_plante(Coordonnees(2, 0), rose);
	champs.placer_plante(Coordonnees(4, 4), tulipe);
	champs.placer_plante(Coordonnees(5, 0), tomate);
	champs.placer_plante(Coordonnees(2, 1), marguerite);
	champs.placer_plante(Coordonnees(3, 5), cafe);

	champs.afficher_champs();
	
	Jardiniers j("Jean", Coordonnees(5, 1));
	
	/*CImg<unsigned char> fenetre(1200, 1050, 1, 3, 0);
	champs.dessiner_champs(&fenetre);

	CImg<unsigned char> gardener = j.dessiner_jardiniers();
	gardener = make_transparent(gardener);
	CImgList<unsigned char> gard1, gard2;
	gard1 = gardener.get_split('x', 3);
	gard2 = gard1[0].get_split('y', 4);
	gard2[0].display();
	*/

	
  	/*fenetre.draw_image(0, 350, 0, 0, j.dessiner_jardiniers(), gardener);
	fenetre.draw_image(0, 100, 0, 0, gard2[0]);
  	fenetre.display();
	*/

	

	while (!champs.is_empty()) {
		j.update_mood();
		cout << j << endl;
		champs.update_champs();
		//j.dessiner_jardiniers();
		champs.action(j);
		champs.afficher_champs();
		/*fenetre.display();
		*/
		sleep(1);
	}
	
	//champs.afficher_champs();
	return 0;
}
