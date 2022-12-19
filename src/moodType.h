#ifndef MOOD_TYPE_H
#define MOOD_TYPE_H

#include <iostream>

using namespace std;

class MoodType {

    public:
        static const MoodType HAPPY;
        static const MoodType NORMAL;
        static const MoodType GRUMPY;
        static const MoodType UNKNOWN;

    private:
        string name;
        int id;

    public:
        MoodType();
        MoodType(string name);
        MoodType(const MoodType &moodType);

        string get_name() const;
        int get_id() const;
        MoodType &operator=(const MoodType &moodType);
        bool operator==(const MoodType &moodType);
        bool operator!=(const MoodType &moodType);

        friend ostream &operator<<(ostream &stream, const MoodType &moodType);


};

constexpr int MIN_MOOD_VALUE = 0;
constexpr int MAX_MOOD_VALUE = 2;

const MoodType &get_mood_type_from_id(int id);
const MoodType &get_next_mood(const MoodType &currentMood);
const MoodType &get_previous_mood(const MoodType &currentMood);

#endif