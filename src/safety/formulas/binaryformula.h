#ifndef SAFETY_BINARYFORMULA_H
#define SAFETY_BINARYFORMULA_H

#include <istream>
#include <ostream>
#include <string>
#include "safety/formula.h"

class BinaryFormula : public Formula {
public:
    BinaryFormula(Formula* lChild = NULL, Formula* rChild = NULL);
    virtual ~BinaryFormula();
    virtual void read(std::istream& in);
    virtual void write(std::ostream& out) const;
    virtual std::string getType() const = 0;
    virtual const Formula* getLeft() const;
    virtual const Formula* getRight() const;

protected:
    Formula* left;
    Formula* right;
};

#endif
