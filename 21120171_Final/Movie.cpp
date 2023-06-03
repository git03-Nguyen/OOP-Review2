#include "Movie.h"

Movie::Movie(const string& _ID, const string& _name, const string& _dir, float _dur, unsigned int _bPrice) :
    ID(_ID), name(_name), director(_dir), duration(_dur), basicPrice(_bPrice) {}

unsigned int Movie::getBasicPrice() const {
    return basicPrice;
}

string Movie::getName() {
    return name;
}
