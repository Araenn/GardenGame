#ifndef CIMG_UTILS_H
#define CIMG_UTILS_H

#include "./lib/CImg.h"
#include <iostream>

using namespace cimg_library;
using namespace std;

CImg<float> make_transparent(CImg<unsigned char> &image);
void quadrillage(CImg<unsigned char> *fenetre);

#endif