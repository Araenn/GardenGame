#include "main.h"

int main(int argc, char *argv[]) {

	load_jardinier_images(); //chargement des images des jardiniers
	loadImagesVariete(); //idem pour plantes

  vector<Variete> listVariete = {
        Variete::ROSE,
        Variete::TULIPE,
        Variete::TOURNESOL,
        
        Variete::RADIS,
        Variete::HARICOT,
        Variete::TOMATE,
        Variete::MELON,
        Variete::AUBERGINE,
        Variete::CITRON,
        Variete::ANANAS,
        Variete::FRAISE,
        Variete::PATATE,
        Variete::ORANGE,
        Variete::AVOCAT,
        
        Variete::BLE,
        Variete::RIZ,
        Variete::RAISIN,
        Variete::CAFE,
        Variete::FRAMBOISE,
        Variete::MAIS};


	Champs champs(35);
	CImg<unsigned char> fenetre(WIDTH_GAME, HEIGHT_C, 1, 3, 0);
	
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

	CImgDisplay jeu(WIDTH_GAME, HEIGHT_GAME, "Garden Game");
  prevent_fullscreen(jeu);

	champs.placer_plante(Coordonnees(2, 0), rose);
	champs.placer_plante(Coordonnees(4, 4), tulipe);
	champs.placer_plante(Coordonnees(5, 0), tomate);
	champs.placer_plante(Coordonnees(2, 1), marguerite);
	champs.placer_plante(Coordonnees(3, 5), cafe);
	champs.placer_plante(Coordonnees(5, 1), framboise);
	champs.placer_plante(Coordonnees(0, 1), ble);

  int buttonEnabled = 1;
  int buttonBagEnabled = 1;
  int buttonShopEnabled = 1;
  int keyAEnabled = 1;
  int shopLegumeClicked = 1;
  while (!jeu.is_closed()) {//d'abord mood, puis action, puis dessin champs, update champs (plantes), et dessin jardiniers


    for (long unsigned int i = 0; i < listJard.size(); i++) {
      listJard[i].update_mood();
    }

    for (long unsigned int i = 0; i < listJard.size(); i++) {
      champs.action(listJard[i], &fenetre, jeu);
    }
    champs.update_champs(&fenetre);
    dessin_jeu(&fenetre);

    int start = time(NULL);

    while (time(NULL) - start < 1) {
      if (jeu.button()) {
        if (buttonEnabled) { //don't allow multiple clicks to be taken into account
          buttonEnabled = 0;
          int x = jeu.mouse_x();
          int y = jeu.mouse_y();
          //achat jardinier
          //choix position attention pas sur jardinier deja existant
          if ((POSX + WIDTH_C > x && x > POSX) && (POSY + HEIGHT_C > y && y > POSY)) {
            x = jeu.mouse_x()/48;
            y = jeu.mouse_y()/48;
            cout << x << ", " << y << endl;
            //choix du nom
            Jardiniers j3("j3", {x, y});
            listJard.push_back(j3);
          }
        }
      } else {
        buttonEnabled = 1;
      }

      if (jeu.is_key('a')) {
        if (keyAEnabled) {
          //recuperer coordonnees
          keyAEnabled = 0;
          int v = 2;
          int w = 4;
          cout << v << ", " << w << endl;
          //recuperer variete
          Plantes p(Plants_types::LEGUME, Variete::TOMATE);
          champs.placer_plante({v, w}, p); //mettre plante choisie selon variete, donc recuperer variete
          cout << "plante placee" << endl;
        }
      }	else {
        keyAEnabled = 1;
      }

      //bag
      if (jeu.button() && ((WIDTH_MENU < jeu.mouse_x() && jeu.mouse_x() <  WIDTH_MENU + LENGTH_MID) && (HEIGHT_MENU/1.5 < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_MENU )) ) {
        Coordonnees up(WIDTH_MENU, HEIGHT_MENU/1.5);
        Coordonnees down(WIDTH_MENU + LENGTH_MID, HEIGHT_MENU);
        filtre(&fenetre, up, down);
        if (buttonBagEnabled) { //don't allow multiple clicks to be taken into account
          buttonBagEnabled = 0;
          dessin_menu_sac(&fenetre);
          CHOIX_MENU = 1;
          dessin_jeu(&fenetre);
          cout << "sac dessine" << endl;
        } 
      } else {
        buttonBagEnabled = 1;
      }

      //shop
      if (jeu.button() && ((WIDTH_MENU + LENGTH_MID < jeu.mouse_x() && jeu.mouse_x() <  WIDTH_GAME) && (HEIGHT_MENU/1.5 < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_MENU )) ) {
        Coordonnees up(WIDTH_MENU + LENGTH_MID, HEIGHT_MENU/1.5);
        Coordonnees down(WIDTH_GAME, HEIGHT_MENU);
        filtre(&fenetre, up, down);
        if (buttonShopEnabled) { //don't allow multiple clicks to be taken into account
          buttonShopEnabled = 0;
          dessin_menu_shop(&fenetre);
          CHOIX_MENU = 2;
          dessin_jeu(&fenetre);
          cout << "shop dessine" << endl;
        } 
      } else {
        buttonShopEnabled = 1;
      }
      
      if ((CHOIX_MENU == 2) && (jeu.button())) {
        Plantes fleur(Plants_types::FLOWER, Variete::UNKNOWN);
        for (int i = 0; i < 3; i++) {
          if ((WIDTH_MENU + 40 + i * 60 < jeu.mouse_x() && jeu.mouse_x() < WIDTH_MENU + 40 + i * 60 + 16*4.5) && (HEIGHT_MENU + 50 < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_MENU + 50 + 16*4.5)) {
            if (shopLegumeClicked) {
              shopLegumeClicked = 0;
              jeu.wait();
              fleur.set_variete(listVariete[i]);
              Coordonnees fleurCoord = {4, 8};
              champs.placer_plante(fleurCoord, fleur);
              cout << listVariete[i].get_name() << endl;
            }
          
          } else {
            shopLegumeClicked = 1;
          }
        } 
        for (int i = 3; i < 6; i++) {
          if ((WIDTH_MENU + 40 + i * 60 < jeu.mouse_x() && jeu.mouse_x() < WIDTH_MENU + 40 + i * 60 + 16*4.5) && (HEIGHT_MENU + 50 < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_MENU + 50 + 16*4.5)) {
            if (shopLegumeClicked) {
              shopLegumeClicked = 0;
              Plantes leg1(Plants_types::LEGUME, listVariete[i]);
              cout << "legume " << i << " clique" << endl;
            }
        
          } else {
            shopLegumeClicked = 1;
          }
        }
        for (int i = 6; i < 13; i++) {
          if ((WIDTH_MENU/1.85 + i * 60 < jeu.mouse_x() && jeu.mouse_x() < WIDTH_MENU/1.85 + i * 60 + 16*4.5) && (HEIGHT_MENU + 180 < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_MENU + 180 + 16*4.5)) {
            if (shopLegumeClicked) {
              shopLegumeClicked = 0;
              Plantes leg2(Plants_types::LEGUME, listVariete[i]);
              cout << "legume " << i << " clique" << endl;
            }
        
          } else {
            shopLegumeClicked = 1;
          }
        }
        for (int i = 13; i < 14; i++) {
          if ((-5 + i * 60 < jeu.mouse_x() && jeu.mouse_x() < -5 + i * 60 + 16*4.5) && (HEIGHT_MENU + 330 < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_MENU + 330 + 16*4.5)) {
            if (shopLegumeClicked) {
              shopLegumeClicked = 0;
              Plantes leg3(Plants_types::LEGUME, listVariete[i]);
              cout << "legume " << i << " clique" << endl;
            }
        
          } else {
            shopLegumeClicked = 1;
          }
        }
        for (int i = 14; i < 20+1; i++) {
          if ((-5 + i * 60 < jeu.mouse_x() && jeu.mouse_x() < -5 + i * 60 + 16*4.5) && (HEIGHT_MENU + 330 < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_MENU + 330 + 16*4.5)) {
            if (shopLegumeClicked) {
              shopLegumeClicked = 0;
              Plantes seed(Plants_types::SEED_PLANTS, listVariete[i]);
              cout << "seed " << i << " clique" << endl;
            }
        
          } else {
            shopLegumeClicked = 1;
          }
        }
      }

      sleep(0.1);
    } 

    for (long unsigned int i = 0; i < listJard.size(); i++) {
      listJard[i].dessiner_jardiniers_champs(&fenetre);
    }
  
    fenetre.display(jeu);
  }

	return 0;
}

