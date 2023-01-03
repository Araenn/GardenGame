#include "fleurs.h"

Fleurs::Fleurs(const Variete &variete) :
Plantes(Plants_types::FLOWER, variete)
{}

bool Fleurs::is_fullyGrown() {
    return this->etat == 5;
}