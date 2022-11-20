#include "CImgUtils.h"

CImg<float> make_transparent(CImg<unsigned char> &image) {
	CImg<float> opacite(image.width(), image.height(), 1, 1, 0);
	for (int x = 0; x < opacite.width(); x++)
		for (int y = 0; y < opacite.height(); y++)
			if (image(x, y, 0) == 255 && image(x, y, 1) == 255 && image(x, y, 2) == 255) {
				opacite(x, y) = 0;
			}
			else {
				opacite(x, y) = 1;
			}
	return opacite;
}