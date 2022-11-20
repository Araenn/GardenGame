#include "plants_types.h"

const Plants_types Plants_types::UNKNOWN("?");
const Plants_types Plants_types::LEGUME("Legumes");
const Plants_types Plants_types::SEED_PLANTS("Plante a graine");
const Plants_types Plants_types::FLOWER("Fleur");

static int idGlobal = 0;

Plants_types::Plants_types(string name) {
    this->name = name;
    this->id = idGlobal++;
}

Plants_types::Plants_types():
Plants_types("Unknow plant type")
{}

string Plants_types::get_name() const {
    return this->name;
}

bool Plants_types::operator==(const Plants_types &plants_types) const {
    return plants_types.id == this->id;
}

bool Plants_types::operator!=(const Plants_types &plants_types) const {
    return plants_types.id != this->id;
}

ostream &operator<<(ostream &stream, const Plants_types &plant_type) {
    return stream << "{id:" << plant_type.id << ",name:" << plant_type.get_name() << "}";
}