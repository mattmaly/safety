#ifndef SAFETY_NEGATION_H
#define SAFETY_NEGATION_H

#include <string>
#include "safety/formulas/unaryformula.h"
#include "safety/world.h"

class Negation : public UnaryFormula {
public:
    /** Creates an negation with a given subformula. */
    Negation(Formula* c = nullptr);

    /** Clears the subformula belonging to this negation. */
    virtual ~Negation();

    /** Returns a newly allocated deep copy of this negation. */
    virtual Formula* copy() const;

    /** Returns a newly allocated simplified copy of this negation. */
    virtual Formula* simplify() const;

    /** Returns, as a newly allocated formula, the result of this
        negation evaluated at a given world. */
    virtual Formula* evaluate(const World& w) const;

    /** Returns the operator type 'F' for negations. */
    virtual std::string getType() const;
};

#endif
