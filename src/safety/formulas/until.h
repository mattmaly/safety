#ifndef SAFETY_UNTIL_H
#define SAFETY_UNTIL_H

#include <string>
#include "safety/formulas/binaryformula.h"

class Until : public BinaryFormula {
    virtual ~Until();
    virtual std::string getType() const;
};

#endif