#ifndef SAFETY_UNARYFORMULA_H
#define SAFETY_UNARYFORMULA_H

#include <istream>
#include <ostream>
#include <string>
#include "safety/formula.h"

class UnaryFormula : public Formula {
public:
    /** Creates a unary formula with a given subformula. */
    UnaryFormula(Formula* c = NULL);

    /** Clears the subformula belonging to this unary formula. */
    virtual ~UnaryFormula();

    /** Fills the subformula of this unary formula by reading
        from an input stream. */
    virtual void read(std::istream& in);

    /** Prints this unary formula to a given output stream. */
    virtual void write(std::ostream& out) const;

    /** Returns the operator type for this unary formula. */
    virtual std::string getType() const = 0;

protected:
    Formula* child;
};

#endif
