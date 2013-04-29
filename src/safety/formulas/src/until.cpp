#include <string>
#include "safety/formulas/until.h"

Until::~Until() {
}

std::string Until::getType() const {
    return std::string("U");
}
