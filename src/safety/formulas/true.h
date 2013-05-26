#ifndef SAFETY_TRUE_H
#define SAFETY_TRUE_H

#include <istream>
#include <ostream>
#include "safety/formula.h"
#include "safety/world.h"

class True : public Formula {
public:
    /** Clears all memory associated with this true formula. */
    virtual ~True();

    /** Reads nothing from an input stream, since true formulas do not
        have subformulas. */
    virtual void read(std::istream& in);

    /** Prints this true formula to a given output stream. */
    virtual void write(std::ostream& out) const;

    /** Returns a newly-allocated true formula. */
    virtual Formula* copy() const;

    /** Returns a newly-allocated true formula, since true evaluates
        to true at any given World. */
    virtual Formula* evaluate(const World& w) const;

    /** Returns true to signify that this false formula is logically true. */
    virtual bool isTrue() const;
};

#endif
