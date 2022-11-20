#ifndef PLANTS_TYPES_H
#define PLANTS_TYPES_H

#include <iostream>

using namespace std;

class Plants_types {

    private:
        string name;
        int id;

    public:
        static const Plants_types UNKNOWN;
        static const Plants_types LEGUME;
        static const Plants_types SEED_PLANTS;
        static const Plants_types FLOWER;

        Plants_types();
        Plants_types(string name);

        string get_name() const;

        bool operator==(const Plants_types &plants_types) const;
        bool operator!=(const Plants_types &plants_types) const;

        friend ostream &operator<<(ostream &stream, const Plants_types &plant_type);
};


#endif