#include "main.h"

int main(int argc, char *argv[]) {
	Champs champs(6);
	//champs.afficher_champs();
	Plantes rose(10);
	champs.placer_plante(2, 0, rose);
	champs.afficher_champs();
	return 0;
}
