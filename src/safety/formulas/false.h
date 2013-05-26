#ifndef SAFETY_FALSE_H
#define SAFETY_FALSE_H

#include <istream>
#include <ostream>
#include "safety/formula.h"
#include "safety/world.h"

class False : public Formula {
public:
    /** Clears all memory associated with this false formula. */
    virtual ~False();

    /** Reads nothing from an input stream, since false formulas do not
        have subformulas. */
    virtual void read(std::istream& in);

    /** Prints this false formula to a given output stream. */
    virtual void write(std::ostream& out) const;

    /** Returns a newly-allocated false formula. */
    virtual Formula* copy() const;

    /** Returns a newly-allocated false formula, since false evaluates
        to false at any given World. */
    virtual Formula* evaluate(const World& w) const;

    /** Returns true to signify that this false formula is logically false. */
    virtual bool isFalse() const;
};

#endif
