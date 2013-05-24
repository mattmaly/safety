#ifndef SAFETY_FORMULA_H
#define SAFETY_FORMULA_H

#include <istream>
#include <ostream>
#include <string>
#include "safety/world.h"

class Formula {
public:
    /** Clears all memory associated with this formula. */
    virtual ~Formula();

    /** Returns a newly allocated deep copy of this formula. */
    virtual Formula* copy() const = 0;

    /** Returns a newly allocated simplified copy of this formula. */
    virtual Formula* simplify() const;

    /** Returns, as a newly allocated formula, the result of this
        formula evaluated at a given world. */
    virtual Formula* evaluate(const World& w) const = 0;

    /** Returns whether this formula is logically true. */
    virtual bool isTrue() const;

    /** Returns whether this formula is logically false. */
    virtual bool isFalse() const;

    /** Returns a newly allocated formula, reading from an input stream. */
    static Formula* parse(std::istream& in);

    /** Returns a newly allocated formula, given an operator. */
    static Formula* getFormulaOfType(const std::string& op);

protected:
    /** Fills the children of this formula, if any,
        by reading from an input stream. */
    virtual void read(std::istream& in) = 0;

    /** Prints this formula to a given output stream. */
    virtual void write(std::ostream& out) const = 0;

    /** The string representation of this formula as printed by write(). */
    mutable std::string name;

    /** A customized ostream printing function so that Formula* values
        are printed as the corresponding Formula object. */
    friend std::ostream& operator<<(std::ostream& out, const Formula* f);
};

namespace std {
    template <>
    struct less<Formula*> {
    public:
        /** A customized less-than function so that Formula* values
            are compared according to the string representations of their
            corresponding Formula objects. */
        bool operator()(Formula* const& f, Formula* const& g) const;
    };
}

#endif
