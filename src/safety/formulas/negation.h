#ifndef SAFETY_NEGATION_H
#define SAFETY_NEGATION_H

#include <string>
#include "safety/formulas/unaryformula.h"

class Negation : public UnaryFormula {
    virtual ~Negation();
    virtual std::string getType() const;
};

#endif
