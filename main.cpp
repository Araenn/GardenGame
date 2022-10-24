#include "main.h"

int main(int argc, char *argv[]) {
	Jardiniers j1("jean");
	Jardiniers j2("jacques", 3);

	cout << j1.get_name() << endl;
	cout << j2.get_name() << endl;
	cout << j2.get_mood() << endl;


	return 0;
}
