#ifndef SAFETY_CONJUNCTION_H
#define SAFETY_CONJUNCTION_H

#include <string>
#include "safety/formulas//binaryformula.h"

class Conjunction : public BinaryFormula {
    virtual ~Conjunction();
    virtual Formula* copy() const;
    virtual std::string getType() const;
};

#endif
