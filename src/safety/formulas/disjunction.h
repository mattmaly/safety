#ifndef SAFETY_DISJUNCTION_H
#define SAFETY_DISJUNCTION_H

#include <string>
#include <set>
#include "safety/formulas/commutativeformula.h"
#include "safety/world.h"

class Disjunction : public CommutativeFormula {
public:
    /** Creates a disjunction with a given set of subformulas. */
    Disjunction(const std::set<Formula*>& c = std::set<Formula*>());

    /** Clears all subformulas belonging to this disjunction. */
    virtual ~Disjunction();

    /** Returns a newly allocated deep copy of this disjunction. */
    virtual Formula* copy() const;

    /** Returns a newly allocated simplified copy of this disjunction. */
    virtual Formula* simplify() const;

    /** Returns, as a newly allocated formula, the result of this
        disjunction evaluated at a given world. */
    virtual Formula* evaluate(const World& w) const;

    /** Returns the operator type '|' for disjunctions. */
    virtual std::string getType() const;
};

#endif
