#include "main.h"

int main(int argc, char *argv[]) {

	load_jardinier_images();
	loadImagesVariete();


	cout << "valeur du type par defaut: " << Plantes::DEFAULT.get_type().get_name() << endl;
	cout << "id: " << Plantes::DEFAULT.get_id() << endl;

	Champs champs(6);
	CImg<unsigned char> fenetre(1200, 1050, 1, 3, 0);
	
	Fleurs rose(Variete::ROSE);
	Fleurs tulipe(Variete::TULIPE);
	Legumes tomate(Variete::TOMATE);
	Fleurs marguerite(Variete::ROSE);
	Seed_plants cafe(10, Variete::CAFE);
	Seed_plants framboise(10, Variete::FRAMBOISE);
	
	
	
	
	Jardiniers j("Jean", Coordonnees(5, 1));
	champs.dessiner_champs(&fenetre);

	CImgDisplay jeu(1200, 1050, "Garden Game");
	champs.placer_plante(Coordonnees(2, 0), rose, &fenetre);
	champs.placer_plante(Coordonnees(4, 4), tulipe, &fenetre);
	champs.placer_plante(Coordonnees(5, 0), tomate, &fenetre);
	champs.placer_plante(Coordonnees(2, 1), marguerite, &fenetre);
	champs.placer_plante(Coordonnees(3, 5), cafe, &fenetre);
	champs.placer_plante(Coordonnees(5, 1), framboise, &fenetre);

	/*
	CImg <unsigned char> img("./data/Crop_Spritesheet.bmp");
	Coordonnees pos = get_spritesheet_plantes_coord(Variete::MAIS, 5);
	img = img.get_crop(pos.getX(), pos.getY(), pos.getX() + PLANT_IMAGE_SIZE[0], pos.getY() + PLANT_IMAGE_SIZE[1]);
	img.resize(img.height() * 3.5, img.width() * 4.5);
	CImg <float> mask_img = make_transparent(img);
	cout << "coord : " << pos.getX() << ", " << pos.getY() << ", " << pos.getX() + PLANT_IMAGE_SIZE[0] << ", " << pos.getY() + PLANT_IMAGE_SIZE[1] << endl;
	*/

	while (!jeu.is_closed()) {
		j.update_mood();
		champs.dessiner_champs(&fenetre);
		//fenetre.draw_image(0, 300, 0, 0, img, mask_img);
		champs.update_champs(&fenetre);
		//champs.dessiner_champs(&fenetre);
		champs.action(j, &fenetre);
		fenetre.display(jeu);
		sleep(1);
	}
	//champs.afficher_champs();
	return 0;
}

