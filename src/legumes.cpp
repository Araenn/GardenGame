#include "legumes.h"

Legumes::Legumes(const Variete &varietes):
Crops(Plants_types::LEGUME, variete) {}

bool Legumes::is_eatable() const {
	return isRecoltable();
}