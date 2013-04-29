#ifndef SAFETY_FORMULA_H
#define SAFETY_FORMULA_H

#include <istream>
#include <ostream>
#include <string>

class Formula {
public:
    virtual ~Formula();
    virtual void read(std::istream& in) = 0;
    virtual void write(std::ostream& out) const = 0;

    static Formula* parse(std::istream& in);
    static Formula* getFormulaOfType(const std::string& op);
};

#endif