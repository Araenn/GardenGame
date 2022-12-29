#include "main.h"

int main(int argc, char *argv[]) {

	load_jardinier_images(); //chargement des images des jardiniers
	loadImagesVariete(); //idem pour plantes


	Champs champs(35);
	CImg<unsigned char> fenetre(1200, 640*1.2, 1, 3, 0);
	
	Fleurs rose(Variete::ROSE);
	Fleurs tulipe(Variete::TULIPE);
	Legumes tomate(Variete::TOMATE);
	Fleurs marguerite(Variete::TOURNESOL);
	Seed_plants cafe(10, Variete::CAFE);
	Legumes framboise(Variete::FRAMBOISE);
	Seed_plants ble(10, Variete::BLE);
	
	
	

	Jardiniers j("Jean", Coordonnees(10, 1));
	Jardiniers j2("Claude", Coordonnees(0, 1));

	vector<Jardiniers> listJard = {j, j2};

	champs.dessiner_champs(&fenetre);

	CImgDisplay jeu(1200, 640*1.2, "Garden Game");
	champs.placer_plante(Coordonnees(2, 0), rose);
	champs.placer_plante(Coordonnees(4, 4), tulipe);
	champs.placer_plante(Coordonnees(5, 0), tomate);
	champs.placer_plante(Coordonnees(2, 1), marguerite);
	champs.placer_plante(Coordonnees(3, 5), cafe);
	champs.placer_plante(Coordonnees(5, 1), framboise);
	champs.placer_plante(Coordonnees(0, 1), ble);

  while (!jeu.is_closed()) {//d'abord mood, puis action, puis dessin champs, update champs (plantes), et dessin jardiniers
      for (int i = 0; i < listJard.size(); i++) {
        listJard[i].update_mood();
        cout << "mood updated" << endl;
      }

      for (int i = 0; i < listJard.size(); i++) {
        champs.action(listJard[i], &fenetre, jeu);
        cout << "action done" << endl;
      }
      champs.update_champs(&fenetre);
      cout << "champs updated" << endl;

      if (jeu.button()) {
        //achat jardinier
        //choix position attention pas sur jardinier deja existant
        int x = jeu.mouse_x()/48;
        int y = jeu.mouse_y()/48;
        cout << x << ", " << y << endl;
        //choix du nom
        Jardiniers j3("j3", {x, y});
        listJard.push_back(j3);
      }

      if (jeu.is_key('a')) {
        //recuperer coordonnees
        int v = 2;
        int w = 4;
        cout << v << ", " << w << endl;
        //recuperer variete
        Plantes p(Plants_types::LEGUME, Variete::TOMATE);
        champs.placer_plante({v, w}, p); //mettre plante choisie selon variete, donc recuperer variete
        cout << "plante placee" << endl;
      }	

      for (int i = 0; i < listJard.size(); i++) {
        listJard[i].dessiner_jardiniers_champs(&fenetre);
        cout << "jard drawed" << endl;
      }
    
      

      
      fenetre.display(jeu);
      cout << "windows displayed" << endl;
      sleep(1);
    }

	return 0;
}

