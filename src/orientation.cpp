#include "orientation.h"

const Orientation Orientation::NORTH = Orientation("NORTH");
const Orientation Orientation::SOUTH = Orientation("SOUTH");
const Orientation Orientation::EAST = Orientation("EAST");
const Orientation Orientation::WEST = Orientation("WEST");
const Orientation Orientation::UNKNOWN = Orientation("?");

static int globalID = 0;

Orientation::Orientation() {
    this->name = "?";
    this->id = -1;
}

Orientation::Orientation(string name) {
    this->name = name;
    this->id = globalID++;
}

Orientation::Orientation(const Orientation &orientation) {
    this->name = orientation.name;
    this->id = orientation.id;
}

string Orientation::get_name() const {
    return this->name;
}

int Orientation::get_id() const {
    return this->id;
}

const Orientation &get_orientation_from_id(int id) {
    switch (id) {
        case 0: return Orientation::NORTH;
        case 1: return Orientation::SOUTH;
        case 2: return Orientation::EAST;
        case 3: return Orientation::WEST;
    }
    return Orientation::UNKNOWN;
}

Orientation &Orientation::operator=(const Orientation &orientation) {
    this->name = orientation.name;
    this->id = orientation.id;
    return *this;
}