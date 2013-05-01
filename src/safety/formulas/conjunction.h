#ifndef SAFETY_CONJUNCTION_H
#define SAFETY_CONJUNCTION_H

#include <string>
#include "safety/formulas//binaryformula.h"
#include "safety/world.h"

class Conjunction : public BinaryFormula {
public:
    Conjunction(Formula* lChild = NULL, Formula* rChild = NULL);
    virtual ~Conjunction();
    virtual Formula* copy() const;
    virtual Formula* simplify() const;
    virtual Formula* evaluate(const World& w) const;
    virtual std::string getType() const;
};

#endif
