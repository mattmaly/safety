#ifndef SAFETY_FORMULA_H
#define SAFETY_FORMULA_H

#include <istream>
#include <ostream>
#include <string>
#include "safety/world.h"

class Formula {
public:
    virtual ~Formula();
    virtual void read(std::istream& in) = 0;
    virtual void write(std::ostream& out) const = 0;
    virtual Formula* copy() const = 0;
    virtual Formula* simplify() const;
    virtual Formula* evaluate(const World& w) const = 0;
    virtual bool isTrue() const;
    virtual bool isFalse() const;

    static Formula* parse(std::istream& in);
    static Formula* getFormulaOfType(const std::string& op);
};

namespace std {
    template <>
    struct less<Formula*> {
    public:
        bool operator()(Formula* const& f, Formula* const& g) const;
    };
}

#endif
