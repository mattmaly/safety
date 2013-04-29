#include <string>
#include "safety/formulas/eventually.h"

Eventually::~Eventually() {
}

std::string Eventually::getType() const {
    return std::string("F");
}
