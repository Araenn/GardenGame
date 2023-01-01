#include "CImgUtils.h"

static vector<CImg<unsigned char>> plants_fullygrown; 

/*
apply transparency to an image with a mask
*/
CImg<float> make_transparent(CImg<unsigned char> &image) {
	CImg<float> opacite(image.width(), image.height(), 1, 1, 0);
	for (int x = 0; x < opacite.width(); x++)
		for (int y = 0; y < opacite.height(); y++)
			if (image(x, y, 0) == 255 && image(x, y, 1) == 255 && image(x, y, 2) == 255) {
				opacite(x, y) = 0;
			} else {
				opacite(x, y) = 1;
			}
	return opacite;
}

/*
draw a grid for visualization 
*/
void quadrillage(CImg <unsigned char> *fenetre) {
	int pos_x = 0;
	int pos_y = 0;
	int width_f = 640*1.2; //fenetre->width();
	int height_f = 640*1.2; //fenetre->height();

	int LineAmount = 16;
	int colAmount = 16;

	int Lc = width_f/colAmount;
	int Hc = height_f/LineAmount;


	unsigned char brown[] = {139, 69, 19};
	for (int i = 0; i < LineAmount + 1; i++) {
		fenetre->draw_line(pos_x, pos_y + (Hc * i), pos_x + width_f, pos_y + (Hc * i), brown);
	}

	for (int i = 0; i < colAmount + 1; i++) {
		fenetre->draw_line(pos_x + (Lc * i), pos_y, pos_x + (Lc * i), pos_y + height_f, brown);
	}
}

/*
apply a rectangular filter to the chosen area
*/
void filtre(CImg<unsigned char> *fenetre, Coordonnees up, Coordonnees down) {
	unsigned char grey[] = {100, 100, 100};
	const float alpha = 0.01; //transparency, 0 for full transparent and 1 for opaque
	fenetre->draw_rectangle(up.getX(), up.getY(), down.getX(), down.getY(), grey, alpha);
}

/*
draw the menu
*/
void dessin_menu_sac(CImg<unsigned char> *fenetre) {
	CImg<unsigned char> nut_bag("./data/nut_bag.bmp");
	nut_bag.resize(nut_bag.width()/12, nut_bag.height()/12);
	CImg<float> mask_nutbag = make_transparent(nut_bag);

	CImg<unsigned char> gardener("./data/character/Content/SOUTH.bmp");
	gardener.resize(gardener.height() * 3.5, gardener.width() * 4.5);
	CImg<float> mask_gardener = make_transparent(gardener);

	CImg<unsigned char> plant("./data/fully_grown/rose.bmp");
	plant.resize(plant.height() * 3.5, plant.width() * 3.5);
	CImg<float> mask_plant = make_transparent(plant);

	int posX_icon = WIDTH_C + LENGTH_MID/2;
	unsigned char black[] = {0, 0, 0};
	int font_size = 20;
	int font_width = 20;

	fenetre->draw_image(posX_icon - 15, HEIGHT_MENU + 70, nut_bag, mask_nutbag);
	fenetre->draw_text(posX_icon - 15 + nut_bag.width(), HEIGHT_MENU + 65 + nut_bag.height()/2, ": graines", black, 0, 1, font_size, font_width);

	fenetre->draw_image(posX_icon, HEIGHT_MENU + nut_bag.height() + 140, gardener, mask_gardener);
	fenetre->draw_text(posX_icon + gardener.width(), HEIGHT_MENU + nut_bag.height() + 145 + gardener.height()/2, ": jardiniers", black, 0, 1, font_size, font_width);

	fenetre->draw_image(posX_icon, HEIGHT_MENU + nut_bag.height() + gardener.height() + 210, plant, mask_plant);
	fenetre->draw_text(posX_icon + plant.width(), HEIGHT_MENU + nut_bag.height() + gardener.height() + 210 + plant.height()/2, ": fleurs", black, 0, 1, font_size, font_width);
}

void dessin_menu_shop(CImg<unsigned char> *fenetre) {
	//dessiner toutes plantes fully grown en ligne

    vector <CImg<unsigned char>> listPlant;
	std::filesystem::path filePath = "./data/fully_grown";
    for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(filePath)) {
		string fileName1 = entry.path().filename();
    	string fileName = "./data/fully_grown/" + fileName1;
		const char *fileName2 = fileName.c_str();
		CImg<unsigned char> img(fileName2);
		img.resize(img.height() * 3.5, img.width() * 4.5);
      	listPlant.push_back(img);
  	}

	for (long unsigned int i = 0; i < listPlant.size()/2; i++) {
		for (int j = 0; j < listPlant.size()/2 - 1; j++) {
		CImg<float> mask = make_transparent(listPlant[i]);
		fenetre->draw_image(WIDTH_MENU + i * 30, HEIGHT_MENU + 20, listPlant[i], mask);
		}
	}
	for (long unsigned int i = listPlant.size()/2; i < listPlant.size()/2; i++) {
		CImg<float> mask = make_transparent(listPlant[i]);
		fenetre->draw_image(WIDTH_MENU + i * 30, HEIGHT_MENU + 100, listPlant[i], mask);
	}
}

void prevent_fullscreen(CImgDisplay &jeu) {
	int width = jeu.width(), height = jeu.height();
	int x = jeu.window_x(), y = jeu.window_y();

  	bool is_fullscreen = false; // Flag to track fullscreen mode
		// Check for fullscreen mode events
		jeu.wait();
		if (jeu.is_resized()) {
		// If the window is resized, switch between fullscreen and windowed mode
			if (!is_fullscreen) {
				// Switch to fullscreen mode
				jeu.move(0,0).resize(jeu.width(), jeu.height());
				is_fullscreen = true;
			}
			else {
				// Switch to windowed mode
				jeu.move(x,y).resize(width,height);
				is_fullscreen = false;
			}
		}
}
