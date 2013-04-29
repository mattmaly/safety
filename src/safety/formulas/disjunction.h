#ifndef SAFETY_DISJUNCTION_H
#define SAFETY_DISJUNCTION_H

#include <string>
#include "safety/formulas/binaryformula.h"

class Disjunction : public BinaryFormula {
    virtual ~Disjunction();
    virtual std::string getType() const;
};

#endif