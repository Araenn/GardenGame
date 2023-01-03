#ifndef CIMG_UTILS_H
#define CIMG_UTILS_H

#include "./lib/CImg.h"
#include <iostream>
#include <string>
#include <filesystem>
#include "coordonnees.h"

extern int CHOIX_MENU;
extern int nb_graines_joueur;
extern int nb_jardiniers;
extern int nb_fleurs;

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
void dessin_menu_sac(CImg<unsigned char> *fenetre);
void dessin_menu_shop(CImg<unsigned char> *fenetre);
void prevent_fullscreen(CImgDisplay &jeu);
void dessin_jeu(CImg<unsigned char> *fenetre);

#endif