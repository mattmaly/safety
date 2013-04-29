#include <string>
#include "safety/formulas/eventually.h"

Eventually::~Eventually() {
}

Formula* Eventually::copy() const {
    Eventually* e = new Eventually();
    e->child = child->copy();
    return e;
}

std::string Eventually::getType() const {
    return std::string("F");
}
