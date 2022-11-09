#include "main.h"

int main(int argc, char *argv[]) {
	Champs champs(6);
	//champs.afficher_champs();
	Plantes rose(10);
	champs.placer_plante(2, 0, rose);
	champs.afficher_champs();
	Coordonnees pos1(2, 1);

	cout << "position rose : " << champs.get_coordonnees(rose) << endl;

	Jardiniers j("Jean", 1);
	j.set_position(pos1);
	cout << "Prenom : " << j.get_name() << ", mood : " << j.get_mood_name() << ", position : " << j.get_position() << endl;

	return 0;
}
