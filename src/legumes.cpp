#include "legumes.h"

Legumes::Legumes(const Variete &varietes):
Crops(Plants_types::LEGUME, varietes) {}

Legumes::Legumes() :
Legumes(Variete::UNKNOWN) {}

bool Legumes::is_eatable() const {
	return isRecoltable();
}