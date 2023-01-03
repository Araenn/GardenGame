#include "main.h"

int main(int argc, char *argv[]) {

	load_jardinier_images(); //chargement des images des jardiniers
	loadImagesVariete(); //idem pour plantes

  nb_graines_joueur = 0;
  nb_jardiniers = 0;
  nb_fleurs = 0;

  vector<Variete> listVariete = {
        Variete::ROSE,
        Variete::TULIPE,
        Variete::TOURNESOL,
        
        Variete::RADIS,
        Variete::ORANGE,
        Variete::AVOCAT,
        Variete::HARICOT,
        Variete::TOMATE,
        Variete::MELON,
        Variete::AUBERGINE,
        Variete::CITRON,
        Variete::ANANAS,
        Variete::FRAISE,
        Variete::PATATE,
        
        Variete::BLE,
        Variete::RIZ,
        Variete::RAISIN,
        Variete::CAFE,
        Variete::FRAMBOISE,
        Variete::MAIS};


	Champs champs(16);
	CImg<unsigned char> fenetre(WIDTH_GAME, HEIGHT_C, 1, 3, 0);
	
	Fleurs rose(Variete::ROSE);
	Fleurs tulipe(Variete::TULIPE);
	Legumes tomate(Variete::TOMATE);
	Fleurs marguerite(Variete::TOURNESOL);
	Seed_plants cafe = Seed_plants(Variete::CAFE);
	Legumes framboise(Variete::FRAMBOISE);
	Seed_plants ble = Seed_plants(Variete::BLE);
	Seed_plants raisin(Variete::RAISIN);
  Seed_plants riz(Variete::RIZ);
  nb_fleurs = 3;
	
	

	Jardiniers j("Jean", Coordonnees(10, 1));
	Jardiniers j2("Claude", Coordonnees(0, 1));

	vector<Jardiniers> listJard = {j, j2};
  nb_jardiniers = (int)listJard.size();

	champs.dessiner_champs(&fenetre);

	CImgDisplay jeu(WIDTH_GAME, HEIGHT_GAME, "Garden Game");

	champs.placer_plante(Coordonnees(2, 0), rose);
	champs.placer_plante(Coordonnees(4, 4), tulipe);
	champs.placer_plante(Coordonnees(5, 0), tomate);
	champs.placer_plante(Coordonnees(2, 1), marguerite);
	champs.placer_plante(Coordonnees(3, 5), cafe);
	champs.placer_plante(Coordonnees(5, 1), framboise);
	champs.placer_plante(Coordonnees(0, 1), ble);
  champs.placer_plante(Coordonnees(15, 2), riz);
  champs.placer_plante(Coordonnees(10, 9), raisin);

  unsigned char ruby[] = {255, 17, 30};
  int font_size = 20;
	int font_width = 10;
  int posX_icon = WIDTH_C + LENGTH_MID/1.5;

  int buttonEnabled = 1;
  int buttonBagEnabled = 1;
  int buttonShopEnabled = 1;
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

      //bought gardeners and place them
      if (CHOIX_MENU == 0 && jeu.button() ){
        if ((posX_icon < jeu.mouse_x() && jeu.mouse_x() < posX_icon + GARDENERS_WIDTH) && (HEIGHT_MENU + 1024/12 + 140 < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_MENU + 1024/12 + 140 + GARDENERS_HEIGHT)) {
          if (buttonEnabled) { //don't allow multiple clicks to be taken into account
            for (long unsigned int i = 0; i < listJard.size(); i++) {
              if (listJard[i].get_position() != Coordonnees(jeu.mouse_x()/48, jeu.mouse_y()/48)) {
                if (nb_graines_joueur >= COUT_JOUEUR) {
                  buttonEnabled = 0;
                  Jardiniers j3("j3", {jeu.mouse_x()/48, jeu.mouse_y()/48});
                  listJard.push_back(j3);
                  nb_graines_joueur-= COUT_JOUEUR;
                } else if (nb_graines_joueur < COUT_JOUEUR) {
                  fenetre.draw_text(WIDTH_MENU + LENGTH_MID/2, HEIGHT_MENU + 10, "Not enough seeds !", ruby, 0, 1, font_size, font_width);
                } else {

                }
              } else if (listJard[i].get_position() == Coordonnees(jeu.mouse_x()/48, jeu.mouse_y()/48)) {
                fenetre.draw_text(WIDTH_MENU + LENGTH_MID/2, HEIGHT_MENU + 10, "Already a gardener here !", ruby, 0, 1, font_size, font_width);
              } else {

              }
            }
            
        } else {
          buttonEnabled = 1;
        }
      }
    }

      //click on bag
      if (jeu.button() && ((WIDTH_MENU < jeu.mouse_x() && jeu.mouse_x() <  WIDTH_MENU + LENGTH_MID) && (HEIGHT_MENU/1.5 < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_MENU )) ) {
        Coordonnees up(WIDTH_MENU, HEIGHT_MENU/1.5);
        Coordonnees down(WIDTH_MENU + LENGTH_MID, HEIGHT_MENU);
        filtre(&fenetre, up, down);
        if (buttonBagEnabled) { //don't allow multiple clicks to be taken into account
          buttonBagEnabled = 0;
          dessin_menu_sac(&fenetre);
          CHOIX_MENU = 0;
          dessin_jeu(&fenetre);
        } 
      } else {
        buttonBagEnabled = 1;
      }

      //click on shop
      if (jeu.button() && ((WIDTH_MENU + LENGTH_MID < jeu.mouse_x() && jeu.mouse_x() <  WIDTH_GAME) && (HEIGHT_MENU/1.5 < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_MENU )) ) {
        Coordonnees up(WIDTH_MENU + LENGTH_MID, HEIGHT_MENU/1.5);
        Coordonnees down(WIDTH_GAME, HEIGHT_MENU);
        filtre(&fenetre, up, down);
        if (buttonShopEnabled) { //don't allow multiple clicks to be taken into account
          buttonShopEnabled = 0;
          dessin_menu_shop(&fenetre);
          CHOIX_MENU = 1;
          dessin_jeu(&fenetre);
        } 
      } else {
        buttonShopEnabled = 1;
      }
      
      //bought plants and place them
      if ((CHOIX_MENU == 1) && (jeu.button())) {

        //buying flowers, need 150 seeds or warning message in red
        if (nb_graines_joueur >= COUT_FLEUR) {
          Plantes fleur(Plants_types::FLOWER, Variete::UNKNOWN);
          for (int i = 0; i < 3; i++) {
            if ((WIDTH_MENU + 40 + i * 60 < jeu.mouse_x() && jeu.mouse_x() < WIDTH_MENU + 40 + i * 60 + GARDENERS_HEIGHT) && (HEIGHT_MENU + 50 < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_MENU + 50 + GARDENERS_HEIGHT)) {
              if (shopLegumeClicked) {
                shopLegumeClicked = 0;
                jeu.wait();
                fleur.set_variete(listVariete[i]);
                bool plantePlacee = false;
                while (!plantePlacee) {
                  if ((POSX < jeu.mouse_x() && jeu.mouse_x() < WIDTH_C) && (POSY < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_C)) {
                    if (jeu.button()) {
                      Coordonnees fleurCoord = {jeu.mouse_x()/48, jeu.mouse_y()/48};
                      champs.placer_plante(fleurCoord, fleur);
                      nb_graines_joueur-= COUT_FLEUR;
                      plantePlacee = true;
                      nb_fleurs++;
                    }
                  }
                }
              }
            
            } else {
              shopLegumeClicked = 1;
            }
          }
        } else if (nb_graines_joueur < COUT_FLEUR) {
          fenetre.draw_text(WIDTH_MENU + LENGTH_MID/2, HEIGHT_MENU + 400, "Not enough seeds !", ruby, 0, 1, font_size, font_width);
        } else {
        }
        
        //buying legumes, need 20 seeds or warning message in red
        if (nb_graines_joueur >= COUT_LEGUME) {
          Plantes leg1(Plants_types::LEGUME, Variete::UNKNOWN);
          for (int i = 3; i < 6; i++) {
            if ((WIDTH_MENU + 40 + i * 60 < jeu.mouse_x() && jeu.mouse_x() < WIDTH_MENU + 40 + i * 60 + GARDENERS_HEIGHT) && (HEIGHT_MENU + 50 < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_MENU + 50 + GARDENERS_HEIGHT)) {
              if (shopLegumeClicked) {
                shopLegumeClicked = 0;
                leg1.set_variete(listVariete[i]);
                bool plantePlacee = false;
                while (!plantePlacee) {
                  if ((POSX < jeu.mouse_x() && jeu.mouse_x() < WIDTH_C) && (POSY < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_C)) {
                    if (jeu.button()) {
                      Coordonnees leg1Coord = {jeu.mouse_x()/48, jeu.mouse_y()/48};
                      champs.placer_plante(leg1Coord, leg1);
                      nb_graines_joueur-= COUT_LEGUME;
                      plantePlacee = true;
                    }
                  }
                }
              }
          
            } else {
              shopLegumeClicked = 1;
            }
          }
          Plantes leg2(Plants_types::LEGUME, Variete::UNKNOWN);
          for (int i = 6; i < 13; i++) {
            if ((WIDTH_MENU/1.85 + i * 60 < jeu.mouse_x() && jeu.mouse_x() < WIDTH_MENU/1.85 + i * 60 + GARDENERS_HEIGHT) && (HEIGHT_MENU + 180 < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_MENU + 180 + GARDENERS_HEIGHT)) {
              if (shopLegumeClicked) {
                shopLegumeClicked = 0;
                leg2.set_variete(listVariete[i]);
                bool plantePlacee = false;
                while (!plantePlacee) {
                  if ((POSX < jeu.mouse_x() && jeu.mouse_x() < WIDTH_C) && (POSY < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_C)) {
                    if (jeu.button()) {
                      Coordonnees leg2Coord = {jeu.mouse_x()/48, jeu.mouse_y()/48};
                      champs.placer_plante(leg2Coord, leg2);
                      nb_graines_joueur-= COUT_LEGUME;
                      plantePlacee = true;
                    }
                  }
                }
              }
          
            } else {
              shopLegumeClicked = 1;
            }
          }
          Plantes leg3(Plants_types::LEGUME, Variete::UNKNOWN);
          for (int i = 13; i < 14; i++) {
            if ((-5 + i * 60 < jeu.mouse_x() && jeu.mouse_x() < -5 + i * 60 + GARDENERS_HEIGHT) && (HEIGHT_MENU + 330 < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_MENU + 330 + GARDENERS_HEIGHT)) {
              if (shopLegumeClicked) {
                shopLegumeClicked = 0;
                leg3.set_variete(listVariete[i]);
                bool plantePlacee = false;
                while (!plantePlacee) {
                  if ((POSX < jeu.mouse_x() && jeu.mouse_x() < WIDTH_C) && (POSY < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_C)) {
                    if (jeu.button()) {
                      Coordonnees leg3Coord = {jeu.mouse_x()/48, jeu.mouse_y()/48};
                      champs.placer_plante(leg3Coord, leg3);
                      nb_graines_joueur-= COUT_LEGUME;
                      plantePlacee = true;
                    }
                  }
                }
              }
            } else {
              shopLegumeClicked = 1;
            }
          }

        } else if (nb_graines_joueur < COUT_LEGUME) {
          fenetre.draw_text(WIDTH_MENU + LENGTH_MID/2, HEIGHT_MENU + 400, "Not enough seeds !", ruby, 0, 1, font_size, font_width);
        }

        //buying seed_plants, need 90 seeds or warning message in red
        if (nb_graines_joueur >= COUT_SEEDPLANT) {
          Plantes seed(Plants_types::SEED_PLANTS, Variete::UNKNOWN);
          for (int i = 14; i < COUT_LEGUME+1; i++) {
            if ((-5 + i * 60 < jeu.mouse_x() && jeu.mouse_x() < -5 + i * 60 + GARDENERS_HEIGHT) && (HEIGHT_MENU + 330 < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_MENU + 330 + GARDENERS_HEIGHT)) {
              if (shopLegumeClicked) {
                shopLegumeClicked = 0;
                seed.set_variete(listVariete[i]);
                bool plantePlacee = false;
                while (!plantePlacee) {
                  if ((POSX < jeu.mouse_x() && jeu.mouse_x() < WIDTH_C) && (POSY < jeu.mouse_y() && jeu.mouse_y() < HEIGHT_C)) {
                    if (jeu.button()) {
                      Coordonnees seeCoord = {jeu.mouse_x()/48, jeu.mouse_y()/48};
                      champs.placer_plante(seeCoord, seed);
                      nb_graines_joueur-= COUT_SEEDPLANT;
                      plantePlacee = true;
                    }
                  }
                }
              }
          
            } else {
              shopLegumeClicked = 1;
            }
          }
        } else if (nb_graines_joueur < COUT_SEEDPLANT) {
          fenetre.draw_text(WIDTH_MENU + LENGTH_MID/2, HEIGHT_MENU + 400, "Not enough seeds !", ruby, 0, 1, font_size, font_width);
        } else {

        }
      }

      sleep(0.1);
    } 

    //draw all gardeners
    for (long unsigned int i = 0; i < listJard.size(); i++) {
      listJard[i].dessiner_jardiniers_champs(&fenetre);
      nb_jardiniers = (int)listJard.size();
    }
  
    fenetre.display(jeu);
  }

	return 0;
}

