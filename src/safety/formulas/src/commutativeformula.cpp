#include <algorithm>
#include <ostream>
#include <sstream>
#include <string>
#include "safety/formulas/commutativeformula.h"

CommutativeFormula::CommutativeFormula(Formula* lChild, Formula* rChild) : BinaryFormula(lChild, rChild) {
}

CommutativeFormula::~CommutativeFormula() {
}

void CommutativeFormula::write(std::ostream& out) const {
	std::ostringstream lBuf, rBuf;
	left->write(lBuf);
	right->write(rBuf);
	std::string lStr(lBuf.str());
	std::string rStr(rBuf.str());
	if (rStr < lStr)
		std::swap(lStr, rStr);
    out << getType() << " " << lStr << " " << rStr;
}
