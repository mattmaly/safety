#ifndef SAFETY_NEGATION_H
#define SAFETY_NEGATION_H

#include <string>
#include "safety/formulas/unaryformula.h"
#include "safety/world.h"

class Negation : public UnaryFormula {
public:
    Negation(Formula* c = NULL);
    virtual ~Negation();
    virtual Formula* copy() const;
    virtual Formula* simplify() const;
    virtual Formula* evaluate(const World& w) const;
    virtual std::string getType() const;
};

#endif
