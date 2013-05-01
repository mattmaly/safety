#ifndef SAFETY_PROPOSITION_H
#define SAFETY_PROPOSITION_H

#include <istream>
#include <ostream>
#include <string>
#include "safety/formula.h"
#include "safety/world.h"

class Proposition : public Formula {
public:
    Proposition(const std::string& n);
    virtual ~Proposition();
    virtual void read(std::istream& in);
    virtual void write(std::ostream& out) const;
    virtual Formula* copy() const;
    virtual Formula* evaluate(const World& w) const;

protected:
    std::string name;
};

#endif
