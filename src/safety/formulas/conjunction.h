#ifndef SAFETY_CONJUNCTION_H
#define SAFETY_CONJUNCTION_H

#include <string>
#include "safety/formulas//binaryformula.h"

class Conjunction : public BinaryFormula {
public:
    Conjunction(Formula* lChild = NULL, Formula* rChild = NULL);
    virtual ~Conjunction();
    virtual Formula* copy() const;
    virtual Formula* simplify() const;
    virtual std::string getType() const;
};

#endif
