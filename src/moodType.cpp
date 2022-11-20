#include "moodType.h"

const MoodType MoodType::HAPPY = MoodType("Content");
const MoodType MoodType::NORMAL = MoodType("Normal");
const MoodType MoodType::GRUMPY = MoodType("Grincheux");
const MoodType MoodType::UNKNOWN = MoodType("?");

static int globalID = 0;

MoodType::MoodType() {
    this->name = "?";
    this->id = -1;
}

MoodType::MoodType(string name) {
    this->name = name;
    this->id = globalID++;
}

MoodType::MoodType(const MoodType &orientation) {
    this->name = orientation.name;
    this->id = orientation.id;
}

string MoodType::get_name() const {
    return this->name;
}

int MoodType::get_id() const {
    return this->id;
}

MoodType &MoodType::operator=(const MoodType &orientation) {
    this->name = orientation.name;
    this->id = orientation.id;
    return *this;
}

bool MoodType::operator==(const MoodType &moodType) {
    return this->get_id() == moodType.get_id();
}

bool MoodType::operator!=(const MoodType &moodType) {
    return this->get_id() != moodType.get_id();
}

ostream &operator<<(ostream &stream, const MoodType &moodType) {
    return stream << "{id:" << moodType.get_id() << ",name:" << moodType.get_name() << '}'; 
}

const MoodType &get_mood_type_from_id(int id) {
    switch (id) {
        case 0: return MoodType::HAPPY;
        case 1: return MoodType::NORMAL;
        case 2: return MoodType::GRUMPY;
    }
    return MoodType::UNKNOWN;
}


const MoodType &get_next_mood(const MoodType &currentMood) {
    if (currentMood.get_id() >= MAX_MOOD_VALUE) {
        throw invalid_argument("current mood is already at his max.");
    }

    return get_mood_type_from_id(currentMood.get_id() + 1);
}

const MoodType &get_previous_mood(const MoodType &currentMood) {
    if (currentMood.get_id() <= MIN_MOOD_VALUE) {
        throw invalid_argument("current mood is already at his min.");
    }

    return get_mood_type_from_id(currentMood.get_id() - 1);
}