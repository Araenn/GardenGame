#include "main.h"

int main(int argc, char *argv[]) {
	Champs champs(6);
	//champs.afficher_champs();
	Plantes rose(30);
	Plantes tulipe;
	Legumes tomate;
	Fleurs marguerite;
	Seed_plants cafe;

	champs.placer_plante(Coordonnees(2, 0), rose);
	champs.placer_plante(Coordonnees(4, 4), tulipe);
	champs.placer_plante(Coordonnees(5, 0), tomate);
	champs.placer_plante(Coordonnees(2, 1), marguerite);
	champs.placer_plante(Coordonnees(3, 5), cafe);

	champs.afficher_champs();

	Jardiniers j("Jean", 1);
	j.set_position(Coordonnees(2, 1));

	cout << "Prenom : " << j.get_name() << ", mood : " << j.get_mood_name() << ", position : " << j.get_position() << endl;
	cout << "distance entre jean et rose : " << champs.calcul_distance(rose, j) << endl;
	cout << "distance entre jean et tomate : " << champs.calcul_distance(tomate, j) << endl;
	cout << "distance entre jean et marguerite : " << champs.calcul_distance(marguerite, j) << endl;
	cout << "distance entre jean et tulipe : " << champs.calcul_distance(tulipe, j) << endl;
	cout << "plante la plus proche de jean : " << champs.plus_proche_plante(j) << endl;

	while(1) {
		champs.action(j);
		cout << j.get_mood_name() << endl;
		champs.afficher_champs();
	}

	champs.afficher_champs();
	return 0;
}
