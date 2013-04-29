#include <string>
#include "safety/formulas/until.h"

Until::~Until() {
}

Formula* Until::copy() const {
    Until* u = new Until();
    u->left = left->copy();
    u->right = right->copy();
    return u;
}

std::string Until::getType() const {
    return std::string("U");
}
