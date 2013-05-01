#ifndef SAFETY_EVENTUALLY_H
#define SAFETY_EVENTUALLY_H

#include <string>
#include "safety/formulas/unaryformula.h"
#include "safety/world.h"

class Eventually : public UnaryFormula {
public:
    Eventually(Formula* c = NULL);
    virtual ~Eventually();
    virtual Formula* copy() const;
    virtual Formula* simplify() const;
    virtual Formula* evaluate(const World& w) const;
    virtual std::string getType() const;
};

#endif
