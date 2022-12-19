#ifndef ORIENTATION_H
#define ORIENTATION_H

#include <iostream>

using namespace std;

class Orientation {

    public:
        static const Orientation NORTH;
        static const Orientation SOUTH;
        static const Orientation EAST;
        static const Orientation WEST;
        static const Orientation UNKNOWN;

    private:
        string name;
        int id;

    public:
        Orientation();
        Orientation(string name);
        Orientation(const Orientation &orientation);

        string get_name() const;
        int get_id() const;
        Orientation &operator=(const Orientation &orientation);


};

const Orientation &get_orientation_from_id(int id);

#endif