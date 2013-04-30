#ifndef SAFETY_EVENTUALLY_H
#define SAFETY_EVENTUALLY_H

#include <string>
#include "safety/formulas/unaryformula.h"

class Eventually : public UnaryFormula {
public:
    Eventually(Formula* c = NULL);
    virtual ~Eventually();
    virtual Formula* copy() const;
    virtual Formula* simplify() const;
    virtual std::string getType() const;
};

#endif
