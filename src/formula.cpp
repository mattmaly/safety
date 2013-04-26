#include <istream>
#include <string>
#include "formula.h"
#include "negation.h"
#include "conjunction.h"
#include "disjunction.h"
#include "true.h"
#include "false.h"
#include "proposition.h"

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
    else if (op == "true")
        return new True();
    else if (op == "false")
        return new False();
    else
        return new Proposition(op);
}
