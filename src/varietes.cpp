#include "varietes.h"

const Variete Variete::UNKNOWN = Variete("?", -1);

const Variete Variete::RADIS = Variete("Radis", 10);
const Variete Variete::HARICOT = Variete("Haricot", 10);
const Variete Variete::TOMATE = Variete("Tomate", 10);
const Variete Variete::AUBERGINE = Variete("Aubergine", 10);

const Variete Variete::FRAISE = Variete("Fraise", 10);
const Variete Variete::ANANAS = Variete("Ananas", 10);
const Variete Variete::ORANGE = Variete("Orange", 10);

const Variete Variete::ROSE = Variete("Rose", 10);
const Variete Variete::TULIPE = Variete("Tulipe", 10);
const Variete Variete::TOURNESOL = Variete("Tournesol", 10);

const Variete Variete::CAFE = Variete("Cafe", 10);
const Variete Variete::MAIS = Variete("Mais", 10);
const Variete Variete::RAISIN = Variete("Raison", 10);

static int idGlobal = 0;

Variete::Variete(string name, int duree_pousse) {
    this->name = name;
    this->duree_pousse = duree_pousse;
    this->id = idGlobal++;
    this->imgLoaded = false;
}

Variete::Variete():
Variete("?", -1)
{}

string Variete::get_name() const {
    return this->name;
}

int Variete::get_duree_pousse() const {
    return this->duree_pousse;
}

void Variete::loadImages() {
    if (!this->imgLoaded) {
        // réaliser le chargement des images et les placer dans le tableau
    }
}

CImg<unsigned char> &Variete::getImage(int state) {
    if (!imgLoaded) {
        throw std::invalid_argument("Veuillez charger les images avec la fonction Variete.loadImages() avant !");
    }
    
    if (0 < state || state >= MAX_VARIETE_STATE) {
        throw std::invalid_argument("Impossible de charger l'image demandée !\nL'état doit être compris dans l'intervalle [0;6[ !");
    }

    return this->imgStates[state];
}

bool Variete::operator==(const Variete &variete) const {
    return this->id == variete.id;
}

bool Variete::operator!=(const Variete &variete) const {
    return this->id != variete.id;
}