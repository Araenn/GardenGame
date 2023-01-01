#ifndef CIMG_UTILS_H
#define CIMG_UTILS_H

#include "./lib/CImg.h"
#include <iostream>
#include "coordonnees.h"

using namespace cimg_library;
using namespace std;

static const int POSX = 0;
static const int POSY = 0;
static const int WIDTH_C = 640*1.2;
static const int HEIGHT_C = 640*1.2;
static const int WIDTH_GAME = 1200;
static const int HEIGHT_GAME = 640*1.2;
static const int HEIGHT_MENU = 300;
static const int WIDTH_MENU = 640*1.2;
static const int LENGTH_MID = ((WIDTH_GAME - WIDTH_C)/ 2);

CImg<float> make_transparent(CImg<unsigned char> &image);
void quadrillage(CImg<unsigned char> *fenetre);
void filtre(CImg<unsigned char> *fenetre, Coordonnees up, Coordonnees down);
void dessin_menu(CImg<unsigned char> *fenetre, int choix);

#endif