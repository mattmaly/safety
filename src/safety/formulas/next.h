#ifndef SAFETY_NEXT_H
#define SAFETY_NEXT_H

#include <string>
#include "safety/formulas/unaryformula.h"

class Next : public UnaryFormula {
    virtual ~Next();
    virtual std::string getType() const;
};

#endif
