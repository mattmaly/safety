#ifndef SAFETY_UNARYFORMULA_H
#define SAFETY_UNARYFORMULA_H

#include <istream>
#include <ostream>
#include <string>
#include "safety/formula.h"

class UnaryFormula : public Formula {
public:
    virtual ~UnaryFormula();
    virtual void read(std::istream& in);
    virtual void write(std::ostream& out) const;
    virtual std::string getType() const = 0;

protected:
    Formula* child;
};

#endif
