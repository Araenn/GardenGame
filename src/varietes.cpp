#include "varietes.h"

const Variete Variete::UNKNOWN = Variete("?", -1, -1, -1);

const Variete Variete::RADIS = Variete("Radis", TEMPS_POUSSE_LEGUMES, 0, 0);
const Variete Variete::ROSE = Variete("Rose", TEMPS_POUSSE_FLEURS, 0, 1);

const Variete Variete::HARICOT = Variete("Haricot", TEMPS_POUSSE_LEGUMES, 1, 0);
const Variete Variete::TULIPE = Variete("Tulipe", TEMPS_POUSSE_FLEURS, 1, 1);

const Variete Variete::TOMATE = Variete("Tomate", TEMPS_POUSSE_LEGUMES, 2, 0);
const Variete Variete::MELON = Variete("Melon", TEMPS_POUSSE_LEGUMES, 2, 1);

const Variete Variete::AUBERGINE = Variete("Aubergine", TEMPS_POUSSE_LEGUMES, 3, 0);
const Variete Variete::CITRON = Variete("Citron", TEMPS_POUSSE_LEGUMES, 3, 1);

const Variete Variete::ANANAS = Variete("Ananas", TEMPS_POUSSE_LEGUMES, 4, 0);
const Variete Variete::BLE = Variete("Ble", TEMPS_POUSSE_SEEDPLANTS, 4, 1);

const Variete Variete::RIZ = Variete("Riz", TEMPS_POUSSE_SEEDPLANTS, 5, 0);
const Variete Variete::RAISIN = Variete("Raisin", TEMPS_POUSSE_SEEDPLANTS, 5, 1);

const Variete Variete::FRAISE = Variete("Fraise", TEMPS_POUSSE_LEGUMES, 6, 0);
const Variete Variete::CAFE = Variete("Cafe", TEMPS_POUSSE_SEEDPLANTS, 6, 1);

const Variete Variete::PATATE = Variete("Patate", TEMPS_POUSSE_LEGUMES, 7, 0);
const Variete Variete::FRAMBOISE = Variete("Framboise", TEMPS_POUSSE_SEEDPLANTS, 7, 1);

const Variete Variete::ORANGE = Variete("Orange", TEMPS_POUSSE_LEGUMES, 8, 0);
const Variete Variete::AVOCAT = Variete("Avocat", TEMPS_POUSSE_LEGUMES, 8, 1);

const Variete Variete::MAIS = Variete("Mais", TEMPS_POUSSE_SEEDPLANTS, 9, 0);
const Variete Variete::TOURNESOL = Variete("Tournesol", TEMPS_POUSSE_FLEURS, 9, 1);

static int idGlobal = 0;
static vector<CImg<unsigned char>> variete_imgs; 
static bool imgLoaded = false;


Variete::Variete(string name, int duree_pousse, int posX, int posY) {
    this->name = name;
    this->duree_pousse = duree_pousse;
    this->id = idGlobal++;
    this->posX = posX;
    this->posY = posY;
}

Variete::Variete():
Variete("?", -1, -1, -1)
{}

string Variete::get_name() const {
    return this->name;
}

int Variete::get_duree_pousse() const {
    return this->duree_pousse;
}

/*
pre load all the plants pictures from the spritesheet in a vector
*/
void loadImagesVariete() {
    if (imgLoaded) {
        return;
    }

    CImg <unsigned char> img("./data/Crop_Spritesheet.bmp");

    int index = 0;
    for (int i = 0; i < TEMPS_POUSSE_LEGUMES; i++) { // boucle des lignes
        for (int k = 0; k < 2; k++) { // boucle des colonnes
            for (int j = 0; j < 6; j++) { // boucle des etats
                int line = k * 6 * 16 + 16 * (5 - j);
                int col = i * 16;
                CImg <unsigned char> newImage = img.get_crop(
                    line, 
                    col, 
                    (line + 16), 
                    (col + 16)
                );
                variete_imgs.push_back(newImage);
                variete_imgs[variete_imgs.size() - 1].resize(newImage.height() * 3.5, newImage.width() * 3.5);
                index++;
                
            }
        }

    }

    imgLoaded = true;
}

/*
return the right picture of the species
*/
CImg<unsigned char> Variete::getImage(int state) const {
    if (!imgLoaded) {
        throw std::invalid_argument("Veuillez charger les images avec la fonction Variete.loadImages() avant !");
    }
    
    if (0 > state || state >= MAX_VARIETE_STATE) {
        throw std::invalid_argument("Impossible de charger l'image demand??e !\nL'??tat doit ??tre compris dans l'intervalle [0;6[ !");
    }

    int plantIndex = ((this->posX << 1) | this->posY) * 6 + state;
    return variete_imgs[plantIndex];
}

bool Variete::operator==(const Variete &variete) const {
    return this->id == variete.id;
}

bool Variete::operator!=(const Variete &variete) const {
    return this->id != variete.id;
}

int Variete::get_posX() const {
    return this->posX;
}

int Variete::get_posY() const {
    return this->posY;
}