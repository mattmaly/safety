#ifndef SAFETY_NEXT_H
#define SAFETY_NEXT_H

#include <string>
#include "safety/formulas/unaryformula.h"
#include "safety/world.h"

class Next : public UnaryFormula {
public:
    Next(Formula* c = NULL);
    virtual ~Next();
    virtual Formula* copy() const;
    virtual Formula* simplify() const;
    virtual Formula* evaluate(const World& w) const;
    virtual std::string getType() const;
};

#endif
