#include "main.h"

int main(int argc, char *argv[]) {
	Plantes p(10);
	Plantes r(30);

	while(1) {
		cout << "temps de pousse de p = " << p.get_dureePousse() << endl;
		cout << "plante depuis : " << time(NULL) - p.get_datePlantation() << endl;
		cout << "temps de pousse de r = " << r.get_dureePousse() << endl;
		cout << "plante depuis : " << time(NULL) - r.get_datePlantation() << endl;
		cout << p.etapes_pousse() << endl;
		cout << r.etapes_pousse() << endl;
		sleep(1);
	}
	return 0;
}