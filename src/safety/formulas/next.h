#ifndef SAFETY_NEXT_H
#define SAFETY_NEXT_H

#include <string>
#include "safety/formulas/unaryformula.h"

class Next : public UnaryFormula {
public:
    Next(Formula* c = NULL);
    virtual ~Next();
    virtual Formula* copy() const;
    virtual Formula* simplify() const;
    virtual std::string getType() const;
};

#endif
