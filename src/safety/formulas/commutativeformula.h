#ifndef SAFETY_COMMUTATIVEFORMULA_H
#define SAFETY_COMMUTATIVEFORMULA_H

#include "safety/formulas/binaryformula.h"
#include <ostream>

class CommutativeFormula : public BinaryFormula {
public:
	CommutativeFormula(Formula* lChild = NULL, Formula* rChild = NULL);
	virtual ~CommutativeFormula();
	virtual void write(std::ostream& out) const;
};

#endif
