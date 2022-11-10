#include "main.h"

int main(int argc, char *argv[]) {
	Champs champs(6);
	//champs.afficher_champs();
	Plantes rose(30);
	Plantes tulipe;
	champs.placer_plante(2, 0, rose);
	champs.placer_plante(4, 4, tulipe);
	champs.afficher_champs();
	Coordonnees pos1(2, 1);
	
	cout << "position rose : " << champs.get_coordonnees(rose) << endl;

	Jardiniers j("Jean", 1);
	j.set_position(pos1);
	cout << "Prenom : " << j.get_name() << ", mood : " << j.get_mood_name() << ", position : " << j.get_position() << endl;
	cout << "distance entre jean et rose : " << champs.calcul_distance(rose, j) << endl;
	cout << "distance entre jean et tulipe : " << champs.calcul_distance(tulipe, j) << endl;
	cout << "plante la plus proche de jean : " << champs.plus_proche_plante(j) << endl;


	return 0;
}
