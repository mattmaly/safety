#ifndef SAFETY_EVENTUALLY_H
#define SAFETY_EVENTUALLY_H

#include <string>
#include "safety/formulas/unaryformula.h"
#include "safety/world.h"

class Eventually : public UnaryFormula {
public:
    /** Creates an eventually formula with a given subformula. */
    Eventually(Formula* c = NULL);

    /** Clears the subformula belonging to this eventually formula. */
    virtual ~Eventually();

    /** Returns a newly allocated deep copy of this eventually formula. */
    virtual Formula* copy() const;

    /** Returns a newly allocated simplified copy of this eventually formula. */
    virtual Formula* simplify() const;

    /** Returns, as a newly allocated formula, the result of this
        eventually formula evaluated at a given world. */
    virtual Formula* evaluate(const World& w) const;

    /** Returns the operator type 'F' for eventually formulas. */
    virtual std::string getType() const;
};

#endif
