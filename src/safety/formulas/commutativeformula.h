#ifndef SAFETY_COMMUTATIVEFORMULA_H
#define SAFETY_COMMUTATIVEFORMULA_H

#include "safety/formula.h"
#include <ostream>
#include <set>

class CommutativeFormula : public Formula {
public:
	CommutativeFormula(const std::set<Formula*>& c = std::set<Formula*>());
	virtual ~CommutativeFormula();
    virtual std::string getType() const = 0;
    virtual const std::set<Formula*>& getChildren() const;

protected:
    virtual void read(std::istream& in);
    virtual void write(std::ostream& out) const;

    std::set<Formula*> children;
};

#endif
