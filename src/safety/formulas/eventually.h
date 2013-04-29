#ifndef SAFETY_EVENTUALLY_H
#define SAFETY_EVENTUALLY_H

#include <string>
#include "safety/formulas/unaryformula.h"

class Eventually : public UnaryFormula {
    virtual ~Eventually();
    virtual std::string getType() const;
};

#endif
