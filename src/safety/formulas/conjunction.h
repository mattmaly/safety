#ifndef SAFETY_CONJUNCTION_H
#define SAFETY_CONJUNCTION_H

#include <string>
#include <set>
#include "safety/formulas//commutativeformula.h"
#include "safety/world.h"

class Conjunction : public CommutativeFormula {
public:
    Conjunction(const std::set<Formula*>& c = std::set<Formula*>());
    virtual ~Conjunction();
    virtual Formula* copy() const;
    virtual Formula* simplify() const;
    virtual Formula* evaluate(const World& w) const;
    virtual std::string getType() const;
};

#endif
