#ifndef SAFETY_NEXT_H
#define SAFETY_NEXT_H

#include <string>
#include "safety/formulas/unaryformula.h"
#include "safety/world.h"

class Next : public UnaryFormula {
public:
    /** Creates an next formula with a given subformula. */
    Next(Formula* c = NULL);

    /** Clears the subformula belonging to this next formula. */
    virtual ~Next();

    /** Returns a newly allocated deep copy of this next formula. */
    virtual Formula* copy() const;

    /** Returns a newly allocated simplified copy of this next formula. */
    virtual Formula* simplify() const;

    /** Returns, as a newly allocated formula, the result of this
        next formula evaluated at a given world. */
    virtual Formula* evaluate(const World& w) const;

    /** Returns the operator type 'F' for next formulas. */
    virtual std::string getType() const;
};

#endif
