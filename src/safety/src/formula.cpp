#include <istream>
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

Formula* Formula::parse(std::istream& in) {
    std::string op;
    in >> op;
    Formula* f = Formula::getFormulaOfType(op);
    f->read(in);
    return f;
}

Formula* Formula::getFormulaOfType(const std::string& op) {
    if (op[0] == '!')
        return new Negation();
    else if (op[0] == '&')
        return new Conjunction();
    else if (op[0] == '|')
        return new Disjunction();
    else if (op[0] == 'F')
        return new Eventually();
    else if (op[0] == 'X')
        return new Next();
    else if (op[0] == 'U')
        return new Until();
    else if (op == "true")
        return new True();
    else if (op == "false")
        return new False();
    else
        return new Proposition(op);
}
