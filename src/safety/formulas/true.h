#ifndef SAFETY_TRUE_H
#define SAFETY_TRUE_H

#include <istream>
#include <ostream>
#include "safety/formula.h"
#include "safety/world.h"

class True : public Formula {
public:
    virtual ~True();
    virtual void read(std::istream& in);
    virtual void write(std::ostream& out) const;
    virtual Formula* copy() const;
    virtual Formula* evaluate(const World& w) const;
    virtual bool isTrue() const;
};

#endif
