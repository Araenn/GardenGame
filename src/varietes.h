#ifndef VARIETES_H
#define VARIETES_H

#include <iostream>
#include "./lib/CImg.h"

using namespace std;
using namespace cimg_library;

constexpr int MAX_VARIETE_STATE = 6;

class Variete {

    private:
        int id;
        string name;
        CImg<unsigned char> imgStates[MAX_VARIETE_STATE];
        bool imgLoaded;
        int duree_pousse;


    public:
        static const Variete UNKNOWN;

        static const Variete RADIS;
        static const Variete HARICOT;
        static const Variete TOMATE;
        static const Variete AUBERGINE;

        static const Variete FRAISE;
        static const Variete ANANAS;
        static const Variete ORANGE;

        static const Variete ROSE;
        static const Variete TULIPE;
        static const Variete TOURNESOL;

        static const Variete CAFE;
        static const Variete MAIS;
        static const Variete RAISIN;

        Variete();
        Variete(string name, int duree_pousse);

        string get_name() const;
        int get_duree_pousse() const;
        void loadImages();
        CImg<unsigned char> &getImage(int state);

        bool operator==(const Variete &variete) const;
        bool operator!=(const Variete &Variete) const;

        friend ostream &operator<<(ostream &stream, const Variete &variete);

};

#endif