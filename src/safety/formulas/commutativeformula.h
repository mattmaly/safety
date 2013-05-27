#ifndef SAFETY_COMMUTATIVEFORMULA_H
#define SAFETY_COMMUTATIVEFORMULA_H

#include "safety/formula.h"
#include <ostream>
#include <set>

class CommutativeFormula : public Formula {
public:
    /** Creates a CommutativeFormula with a given set of subformulas. */
	CommutativeFormula(const std::set<Formula*>& c = std::set<Formula*>());

    /** Clears all subformulas belonging to this CommutativeFormula. */
	virtual ~CommutativeFormula();

    /** Returns the set of propositions contained in this commutative formula. */
    virtual std::set<int> getProps() const;

    /** Returns the operator type for this CommutativeFormula. */
    virtual std::string getType() const = 0;

    /** Returns the set of this CommutativeFormula's subformulas. */
    virtual const std::set<Formula*>& getChildren() const;

protected:
    /** Fills the subformulas of this CommutativeFormula
        by reading from an input stream. */
    virtual void read(std::istream& in);

    /** Prints this CommutativeFormula to a given output stream. */
    virtual void write(std::ostream& out) const;

    std::set<Formula*> children;
};

#endif
