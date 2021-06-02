#ifndef SAFETY_UNTIL_H
#define SAFETY_UNTIL_H

#include <set>
#include <string>
#include "safety/formula.h"

class Until : public Formula {
public:
    /** Creates an until formula with given left and right subformulas. */
    Until(Formula* lChild = nullptr, Formula* rChild = nullptr);

    /** Clears all subformulas belonging to this until formula. */
    virtual ~Until();

    /** Returns a newly allocated deep copy of this until formula. */
    virtual Formula* copy() const;

    /** Returns a newly allocated simplified copy of this until formula. */
    virtual Formula* simplify() const;

    /** Returns, as a newly allocated formula, the result of this
        until formula evaluated at a given world. */
    virtual Formula* evaluate(const World& w) const;

    /** Returns the set of propositions contained in this until formula. */
    virtual std::set<int> getProps() const;

    /** Returns the operator type 'U' for until formulas. */
    virtual std::string getType() const;

    /** Returns the left subformula of this until formula. */
    virtual const Formula* getLeft() const;

    /** Returns the right subformula of this until formula. */
    virtual const Formula* getRight() const;

protected:
    /** Fills the left and right subformulas of this until formula
        by reading from an input stream. */
    virtual void read(std::istream& in);

    /** Prints this until formula to a given output stream. */
    virtual void write(std::ostream& out) const;

    Formula* left;
    Formula* right;
};

#endif
