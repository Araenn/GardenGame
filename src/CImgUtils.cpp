#include "CImgUtils.h"

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
		//cout << i << endl;
		fenetre->draw_line(pos_x + (Lc * i), pos_y, pos_x + (Lc * i), pos_y + height_f, brown);
	}
}