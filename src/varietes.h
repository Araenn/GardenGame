#ifndef VARIETES_H
#define VARIETES_H

#include <iostream>
#include "./lib/CImg.h"
#include "coordonnees.h"
#include "CImgUtils.h"

using namespace std;
using namespace cimg_library;

constexpr int MAX_VARIETE_STATE = 6;

void loadImagesVariete();

class Variete {

    private:
        int id;
        string name;
        int duree_pousse;
        int posX;
        int posY;


    public:
        static const Variete UNKNOWN;

        static const Variete RADIS;
        static const Variete ROSE;
        static const Variete HARICOT;
        static const Variete TULIPE;
        static const Variete TOMATE;
        static const Variete MELON;
        static const Variete AUBERGINE;
        static const Variete CITRON;
        static const Variete ANANAS;
        static const Variete BLE;
        static const Variete RIZ;
        static const Variete RAISIN;
        static const Variete FRAISE;
        static const Variete CAFE;
        static const Variete PATATE;
        static const Variete FRAMBOISE;
        static const Variete ORANGE;
        static const Variete AVOCAT;
        static const Variete MAIS;
        static const Variete TOURNESOL;

        Variete();
        Variete(string name, int duree_pousse, int posX, int posY);

        string get_name() const;
        int get_duree_pousse() const;
        int get_posX() const;
        int get_posY() const;
        
        CImg<unsigned char> getImage(int state) const;

        bool operator==(const Variete &variete) const;
        bool operator!=(const Variete &Variete) const;

        friend ostream &operator<<(ostream &stream, const Variete &variete);

};

#endif