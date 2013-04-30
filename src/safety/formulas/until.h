#ifndef SAFETY_UNTIL_H
#define SAFETY_UNTIL_H

#include <string>
#include "safety/formulas/binaryformula.h"

class Until : public BinaryFormula {
public:
    Until(Formula* lChild = NULL, Formula* rChild = NULL);
    virtual ~Until();
    virtual Formula* copy() const;
    virtual Formula* simplify() const;
    virtual std::string getType() const;
};

#endif
