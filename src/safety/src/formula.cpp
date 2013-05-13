#include <istream>
#include <sstream>
#include <string>
#include "safety/formula.h"
#include "safety/formulas/negation.h"
#include "safety/formulas/conjunction.h"
#include "safety/formulas/disjunction.h"
#include "safety/formulas/true.h"
#include "safety/formulas/false.h"
#include "safety/formulas/proposition.h"
#include "safety/formulas/eventually.h"
#include "safety/formulas/next.h"
#include "safety/formulas/until.h"

Formula::~Formula() {
}

Formula* Formula::simplify() const {
    return copy();
}

bool Formula::isTrue() const {
    return false;
}

bool Formula::isFalse() const {
    return false;
}

Formula* Formula::parse(std::istream& in) {
    std::string op;
    in >> op;
    Formula* f = Formula::getFormulaOfType(op);
    f->read(in);
    return f;
}

Formula* Formula::getFormulaOfType(const std::string& op) {
    if (op == "!")
        return new Negation();
    else if (op == "&")
        return new Conjunction();
    else if (op == "|")
        return new Disjunction();
    else if (op == "F")
        return new Eventually();
    else if (op == "X")
        return new Next();
    else if (op == "U")
        return new Until();
    else if (op == "true")
        return new True();
    else if (op == "false")
        return new False();
    else
        return new Proposition(op);
}

std::ostream& operator<<(std::ostream& out, const Formula* f) {
    f->write(out);
    return out;
}

bool std::less<Formula*>::operator()(Formula* const& f, Formula* const& g) const {
    std::ostringstream fbuf;
    std::ostringstream gbuf;
    fbuf << f;
    gbuf << g;
    return fbuf.str() < gbuf.str();
}
