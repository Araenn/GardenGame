#include "crops.h"

Crops::Crops(const Plants_types &plants_types, const Variete &variete):
Plantes(plants_types, variete)
{}

bool Crops::isRecoltable() const {
    return this->etat == 5;
}