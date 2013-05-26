#ifndef SAFETY_CONJUNCTION_H
#define SAFETY_CONJUNCTION_H

#include <string>
#include <set>
#include "safety/formulas//commutativeformula.h"
#include "safety/world.h"

class Conjunction : public CommutativeFormula {
public:
    /** Creates a conjunction with a given set of subformulas. */
    Conjunction(const std::set<Formula*>& c = std::set<Formula*>());

    /** Clears all subformulas belonging to this conjunction. */
    virtual ~Conjunction();

    /** Returns a newly allocated deep copy of this conjunction. */
    virtual Formula* copy() const;

    /** Returns a newly allocated simplified copy of this conjunction. */
    virtual Formula* simplify() const;

    /** Returns, as a newly allocated formula, the result of this
        conjunction evaluated at a given world. */
    virtual Formula* evaluate(const World& w) const;

    /** Returns the operator type '&' for conjunctions. */
    virtual std::string getType() const;
};

#endif
