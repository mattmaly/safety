#ifndef SAFETY_PROPOSITION_H
#define SAFETY_PROPOSITION_H

#include <istream>
#include <ostream>
#include <set>
#include <string>
#include "safety/formula.h"
#include "safety/world.h"

class Proposition : public Formula {
public:
    /** Creates a proposition with a given name. */
    Proposition(const std::string& n);

    /** Clears all memory associated with this proposition. */
    virtual ~Proposition();

    /** Returns a singleton set containing this proposition's ID. */
    virtual std::set<int> getProps() const;

    /** Reads nothing from an input stream, since propositions do not
        have subformulas. Instead, registers this proposition with World. */
    virtual void read(std::istream& in);

    /** Prints this proposition to a given output stream. */
    virtual void write(std::ostream& out) const;

    /** Returns a newly allocated copy of this proposition. */
    virtual Formula* copy() const;

    /** Returns, as a newly allocated formula, the result of this
        proposition evaluated at a given World. If the World contains
        this proposition, then a true or false formula is returned accordingly.
        Otherwise, a copy of this proposition will be returned. */
    virtual Formula* evaluate(const World& w) const;

protected:
    std::string name;
};

#endif
