#ifndef SAFETY_DISJUNCTION_H
#define SAFETY_DISJUNCTION_H

#include <string>
#include "safety/formulas/binaryformula.h"
#include "safety/world.h"

class Disjunction : public BinaryFormula {
public:
    Disjunction(Formula* lChild = NULL, Formula* rChild = NULL);
    virtual ~Disjunction();
    virtual Formula* copy() const;
    virtual Formula* simplify() const;
    virtual Formula* evaluate(const World& w) const;
    virtual std::string getType() const;
};

#endif
