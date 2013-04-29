#ifndef SAFETY_BINARYFORMULA_H
#define SAFETY_BINARYFORMULA_H

#include <istream>
#include <ostream>
#include <string>
#include "safety/formula.h"

class BinaryFormula : public Formula {
public:
    virtual ~BinaryFormula();
    virtual void read(std::istream& in);
    virtual void write(std::ostream& out) const;
    virtual std::string getType() const = 0;

protected:
    Formula* left;
    Formula* right;
};

#endif
